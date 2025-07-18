#include "RoomView.h"

RoomView::RoomView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::RoomView)
{
    _ui->setupUi(this);

    _ui->record_listView->setModel(new MedicalRecordListModel(this));

    _ui->examinationSection_frame->setEnabled(0);

    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Kết thúc khám");
    _ui->buttonBox->button(QDialogButtonBox::Ok)
        ->setStyleSheet("padding-left: 10px; padding-right: 10px;");

    _ui->dob_dateEdit->setDate(QDate::currentDate());
    _ui->issueDate_dateEdit->setDate(QDate::currentDate());
    _ui->expiryDate_dateEdit->setDate(QDate::currentDate());
    _ui->prescribedDate_dateEdit->setDate(QDate::currentDate());

    _ui->specifiedTests_tableView
        ->setModel(new ClinicalTestTableModel(this));
    _ui->specifiedTests_tableView->verticalHeader()
        ->setStyleSheet("QHeaderView::section { padding-right: 10px; }");

    _ui->precibedMedicines_tableView
        ->setModel(new MedicineUsageTableModel(this));
    _ui->precibedMedicines_tableView->verticalHeader()
        ->setStyleSheet("QHeaderView::section { padding-right: 10px; }");

    setStyleSheet("");
    setConnections();
    createCompleter();
}

RoomView::~RoomView() {
    delete _ui;
}

void RoomView::setConnections() {
    connect(_ui->waiting_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto roomId = _ui->id_label->text().toStdString();
            auto records = ServiceLocator::instance()
                ->examinationService()->getAllRecordsInRoomByState(roomId);
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->examining_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto roomId = _ui->id_label->text().toStdString();
            auto records = ServiceLocator::instance()->examinationService()
                ->getAllRecordsInRoomByState(roomId, ExaminationState::Examining);
            auto additionalRecords = ServiceLocator::instance()->examinationService()
                ->getAllRecordsInRoomByState(roomId, ExaminationState::TestPending);
            records.insert(records.end(), additionalRecords.begin(), additionalRecords.end());
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->completed_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto roomId = _ui->id_label->text().toStdString();
            auto records = ServiceLocator::instance()->examinationService()
                ->getAllRecordsInRoomByState(roomId, ExaminationState::Completed);
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->allRecords_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto roomId = _ui->id_label->text().toStdString();
            auto records = ServiceLocator::instance()
                ->examinationService()->getAllRecordsInRoom(roomId);
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->record_listView, &QListView::clicked, this,
        [this](const QModelIndex& index) {
            _ui->examinationSection_frame->setEnabled(1);
            setExaminationInfo(index.data().toString().toStdString());
            setPatientInfo();
            setClinicalTests();
            setMedicineUsages();
        });

    connect(_ui->quickSpecify_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto state = ServiceLocator::instance()
                ->examinationService()->recordState(recordId);
            if (!state->canOrderClinicalTest()) {
                return warn("Không thể chỉ định với trạng thái hiện tại!");
            }

            auto testIds = ServiceLocator::instance()
                ->examinationService()->clinicalTestIds(recordId);
            TestServiceTableModel model(QVector<std::string>(testIds.begin(), testIds.end()));
            SelectingView view;
            view.setWindowTitle("Danh sách cận lâm sàng");
            view.setModel(&model);
            view.exec();

            auto specifiedTests = model.selectedItems();
            ServiceLocator::instance()->examinationService()->orderClinicalTests(
                recordId, std::vector<std::string>(specifiedTests.begin(), specifiedTests.end()));
            updateView();
        });

    connect(_ui->quickPrescribe_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto state = ServiceLocator::instance()
                ->examinationService()->recordState(recordId);
            if (!state->canPrescribeMedicine()) {
                return warn("Không thể kê thuốc với trạng thái hiện tại!");
            }

            MedicinePrescribingView view;
            if (view.exec() == QDialog::Accepted) {
                if (!view.checkValidId()) {
                    return warn("Mã thuốc không hợp lệ!");
                }

                if (!view.checkValidQuantity()) {
                    return warn("Số lượng thuốc phải lớn hơn 0!");
                }

                if (confirm("Xác nhận thêm thuốc", "Bạn có chắc chắn muốn thêm thuốc?")) {
                    ServiceLocator::instance()->examinationService()
                        ->prescribeMedicine(recordId, view.getUsage());
                    updateView();
                }
            }
        });

    connect(_ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this,
        [this](bool) {
            if (!_ui->primaryDiagnose_lineEdit->text().length()) {
                return warn("Chẩn đoán chính không thể để trống!");
            }

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto state = ServiceLocator::instance()
                ->examinationService()->recordState(recordId);
            if (!state->canComplete()) {
                return warn("Không thể kết thúc khám với trạng thái hiện tại!");
            }

            if (confirm("Xác nhận", "Bạn có chắc chắn muốn kết thúc quá trình khám?")) {
                auto primaryResult = _ui->primaryDiagnose_lineEdit->text();
                auto secondaryResult = _ui->secondaryDiagnose_lineEdit->text();
                auto result = primaryResult + "<>" + secondaryResult;
                ServiceLocator::instance()->examinationService()
                    ->compeleteExamination(recordId, result.toStdString());
                updateView();
            }
        });
}

void RoomView::createCompleter() {
    QStringList doctorNames;
    auto repo = ServiceLocator::instance()->employeeRepository();
    for (const auto& employee : repo->data()) {
        if (auto doctor = dynamic_cast<const Doctor*>(employee)) {
            doctorNames << QString::fromStdString(doctor->name());
        }
    }

    QCompleter* completer = new QCompleter(doctorNames, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    _ui->doctorName_lineEdit->setCompleter(completer);

    connect(completer, QOverload<const QString&>::of(&QCompleter::activated),
        this, [this](const QString& text) {
            _ui->prescribingDoctorName_lineEdit->setText(text);

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto doctorId = ServiceLocator::instance()
                ->examinationService()->findDoctorIdByName(text.toStdString());
            ServiceLocator::instance()->examinationService()
                ->startExamination(recordId, doctorId);

            _ui->doctorId_lineEdit->setText(QString::fromStdString(doctorId));
            updateView();
        });

    connect(_ui->doctorName_lineEdit, &QLineEdit::editingFinished,
        this, [this, doctorNames]() {
            auto text = _ui->doctorName_lineEdit->text();
            if (doctorNames.contains(text, Qt::CaseInsensitive)) {
                return;
            }

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            ServiceLocator::instance()->examinationService()
                ->cancelExamination(recordId);

            _ui->doctorId_lineEdit->clear();
            _ui->doctorName_lineEdit->clear();
            _ui->prescribingDoctorName_lineEdit->clear();
            updateView();
        });
}

void RoomView::updateView() {
    setClinicalTests();
    setMedicineUsages();
    triggerRecordFilter();
}

void RoomView::setExaminationInfo(const std::string& recordId) {
    auto state = ServiceLocator::instance()
        ->examinationService()->recordState(recordId);
    if (state->stateName() == ExaminationState::Waiting) {
        _ui->doctorName_lineEdit->setReadOnly(0);
    }
    else {
        _ui->doctorName_lineEdit->setReadOnly(1);
    }

    _ui->recordId_lineEdit->setText(QString::fromStdString(recordId));

    auto record = ServiceLocator::instance()->examinationService()
        ->findRecordById(recordId);
    auto doctorId = record->doctorId();
    if (!doctorId.size()) {
        return;
    }
    auto doctor = ServiceLocator::instance()->examinationService()
        ->findDoctorById(doctorId);
    _ui->doctorId_lineEdit->setText(QString::fromStdString(doctor->id()));
    _ui->doctorName_lineEdit->setText(QString::fromStdString(doctor->name()));
    _ui->prescribingDoctorName_lineEdit->setText(
        QString::fromStdString(doctor->name()));

    auto result = QString::fromStdString(record->diagnosisResult());
    auto splitedResult = result.split("<>");
    if (splitedResult.size() > 0) {
        _ui->primaryDiagnose_lineEdit->setText(splitedResult[0]);
        if (splitedResult.size() > 1) {
            _ui->secondaryDiagnose_lineEdit->setText(splitedResult[1]);
        }
    }
}

void RoomView::setPatientInfo() {
    auto record = ServiceLocator::instance()->examinationService()
        ->findRecordById(_ui->recordId_lineEdit->text().toStdString());
    auto patient = ServiceLocator::instance()
        ->examinationService()->findPatientById(record->patientId());
    _ui->patientId_lineEdit->setText(QString::fromStdString(patient->id()));
    _ui->patientName_lineEdit->setText(QString::fromStdString(patient->name()));
    _ui->gender_comboBox->setCurrentText(QString::fromStdString(patient->gender()));
    auto dob = patient->dob();
    _ui->dob_dateEdit->setDate({ dob.year(), dob.month(), dob.day() });
    _ui->address_lineEdit->setText(QString::fromStdString(patient->address()));
    _ui->phone_lineEdit->setText(QString::fromStdString(patient->phone()));

    auto symptoms = patient->symptoms();
    QStringList list;
    for (const auto& symptom : symptoms) {
        list << QString::fromStdString(symptom);
    }
    _ui->symptom_plainTextEdit->setPlainText(list.join(", "));

    if (auto insurance = patient->insuranceCard()) {
        _ui->insuranceInfo_groupBox->setEnabled(1);
        _ui->cardId_lineEdit->setText(QString::fromStdString(insurance->id()));
        auto date = insurance->issueDate();
        _ui->issueDate_dateEdit->setDate({ date.year(), date.month(), date.day() });
        date = insurance->expiryDate();
        _ui->expiryDate_dateEdit->setDate({ date.year(), date.month(), date.day() });
        _ui->coveragePercent_doubleSpinBox->setValue(insurance->coveragePercent());
    }
    else {
        _ui->insuranceInfo_groupBox->setEnabled(0);
    }
}

void RoomView::setClinicalTests() {
    auto record = ServiceLocator::instance()->examinationService()
        ->findRecordById(_ui->recordId_lineEdit->text().toStdString());
    auto tests = record->clinicalTests();
    static_cast<ClinicalTestTableModel*>(
        _ui->specifiedTests_tableView->model())->setData(tests);
    pad(_ui->specifiedTests_tableView->horizontalHeader());
}

void RoomView::setMedicineUsages() {
    auto record = ServiceLocator::instance()->examinationService()
        ->findRecordById(_ui->recordId_lineEdit->text().toStdString());
    auto usages = record->prescribedMedicines();
    static_cast<MedicineUsageTableModel*>(
        _ui->precibedMedicines_tableView->model())->setData(usages);
    pad(_ui->precibedMedicines_tableView->horizontalHeader());
}

void RoomView::clearExaminationInfo() {
    _ui->recordId_lineEdit->clear();
    _ui->doctorId_lineEdit->clear();
    _ui->doctorName_lineEdit->clear();
    _ui->primaryDiagnose_lineEdit->clear();
    _ui->secondaryDiagnose_lineEdit->clear();
    _ui->prescribingDoctorName_lineEdit->clear();
}

void RoomView::clearPatientInfo() {
    _ui->patientId_lineEdit->clear();
    _ui->patientName_lineEdit->clear();
    _ui->gender_comboBox->setCurrentIndex(0);
    _ui->dob_dateEdit->setDate(QDate::currentDate());
    _ui->address_lineEdit->clear();
    _ui->phone_lineEdit->clear();
    _ui->symptom_plainTextEdit->clear();
    _ui->cardId_lineEdit->clear();
    _ui->issueDate_dateEdit->setDate(QDate::currentDate());
    _ui->expiryDate_dateEdit->setDate(QDate::currentDate());
    _ui->coveragePercent_doubleSpinBox->setValue(0.0);
}

void RoomView::clearClinicalTests() {
    static_cast<ClinicalTestTableModel*>(
        _ui->specifiedTests_tableView->model())->setData({});
}

void RoomView::clearMedicineUsages() {
    static_cast<MedicineUsageTableModel*>(
        _ui->precibedMedicines_tableView->model())->setData({});
}

void RoomView::triggerRecordFilter() {
    if (_ui->waiting_radioButton->isChecked()) {
        emit _ui->waiting_radioButton->toggled(1);
    }
    else if (_ui->examining_radioButton->isChecked()) {
        emit _ui->examining_radioButton->toggled(1);
    }
    else if (_ui->completed_radioButton->isChecked()) {
        emit _ui->completed_radioButton->toggled(1);
    }
    else if (_ui->allRecords_radioButton->isChecked()) {
        emit _ui->allRecords_radioButton->toggled(1);
    }
}

void RoomView::changeRoom(int index) {
    auto room = ServiceLocator::instance()
        ->roomExaminationRepository()->data()[index];

    _ui->id_label->setText(QString::fromStdString(room->id()));
    _ui->name_label->setText(QString::fromStdString(room->name()));
    _ui->examinationSection_frame->setEnabled(0);
    clearExaminationInfo();
    clearPatientInfo();
    clearClinicalTests();
    clearMedicineUsages();
    triggerRecordFilter();
}
