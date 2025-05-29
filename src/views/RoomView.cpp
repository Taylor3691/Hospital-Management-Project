#include "RoomView.h"

RoomView::RoomView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::RoomView)
    , _service(std::make_unique<ExaminationService>(
        ServiceLocator::getInstance()->medicalRecordRepository(),
        ServiceLocator::getInstance()->medicineRepository(),
        ServiceLocator::getInstance()->roomExaminationRepository(),
        ServiceLocator::getInstance()->testServiceRepository(),
        ServiceLocator::getInstance()->employeeRepository(),
        ServiceLocator::getInstance()->patientRepository()
    ))
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

    setStyleSheet("");
    setConnections();
    createCompleter();
}

RoomView::~RoomView() {
    delete _ui;
}

void RoomView::setConnections() {
    connect(_ui->record_listView, &QListView::clicked, this,
        [this](const QModelIndex&) {
            _ui->examinationSection_frame->setEnabled(1);
            setExaminationInfo();
            setPatientInfo();
            setClinicalTests();
        });

    connect(_ui->quickSpecify_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            QVector<std::string> specifiedTests;
            for (const auto& test : currentRecord()->clinicalTests()) {
                specifiedTests.push_back(test->testId());
            }

            TestServiceTableModel model(specifiedTests);
            SelectingView view;
            view.setWindowTitle("Danh sách cận lâm sàng");
            view.setModel(&model);
            view.exec();

            addTests(model.selectedItems());
            setClinicalTests();
        });

    connect(_ui->quickPrescribe_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            MedicinePrescribingView view;
            QString title = "Xác nhận thêm thuốc";
            QString msg = "Bạn có chắc chắn muốn thêm thuốc?";
            if (view.exec() == QDialog::Accepted && confirm(title, msg)) {
                
            }
        });
}

void RoomView::createCompleter() {
    QStringList doctorNames;
    auto repo = ServiceLocator::getInstance()->employeeRepository();
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
            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto record = _service->findRecordById(recordId);

            FilterCriteria criteria;
            criteria.value = text.toStdString();
            auto doctorId = ServiceLocator::getInstance()->employeeManager()
                ->find({ {criteria, &Employee::name} })[0]->id();

            record->startExamination(doctorId);
            _ui->doctorId_lineEdit->setText(QString::fromStdString(doctorId));
            ServiceLocator::getInstance()->medicalRecordRepository()->update(*record);
        });

    connect(_ui->doctorName_lineEdit, &QLineEdit::editingFinished,
        this, [this, doctorNames]() {
            auto text = _ui->doctorName_lineEdit->text();
            if (doctorNames.contains(text, Qt::CaseInsensitive)) {
                return;
            }

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto record = _service->findRecordById(recordId);
            record->cancelExamination();
            _ui->doctorId_lineEdit->clear();
            _ui->doctorName_lineEdit->clear();
            ServiceLocator::getInstance()->medicalRecordRepository()->update(*record);
        });
}

const MedicalRecord* RoomView::currentRecord() {
    auto index = _ui->record_listView->currentIndex();
    if (!index.isValid()) {
        return nullptr;
    }
    return static_cast<const MedicalRecord*>(
        index.data(Qt::UserRole).value<void*>());
}

void RoomView::setExaminationInfo() {
    auto record = currentRecord();
    _ui->recordId_lineEdit->setText(QString::fromStdString(record->id()));

    auto doctors = _service->getAllDoctor();
    auto doctorId = record->doctorId();
    auto doctor = from(doctors).where(&Doctor::id, doctorId).findOne();
    _ui->doctorId_lineEdit->setText(QString::fromStdString(doctor->id()));
    _ui->doctorName_lineEdit->setText(QString::fromStdString(doctor->name()));

    _ui->primaryDiagnose_lineEdit
        ->setText(QString::fromStdString(record->diagnosisResult()));
}

void RoomView::setPatientInfo() {
    auto record = currentRecord();
    auto patient = _service->findPatientById(record->patientId());
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
        _ui->cardId_lineEdit->setText(QString::fromStdString(insurance->id()));
        auto date = insurance->issueDate();
        _ui->issueDate_dateEdit->setDate({ date.year(), date.month(), date.day() });
        date = insurance->expiryDate();
        _ui->expiryDate_dateEdit->setDate({ date.year(), date.month(), date.day() });
        _ui->coveragePercent_doubleSpinBox->setValue(insurance->coveragePercent());
    }
}

void RoomView::setClinicalTests() {
    auto tests = currentRecord()->clinicalTests();
    static_cast<ClinicalTestTableModel*>(_ui->specifiedTests_tableView
        ->model())->setData(QVector<const ClinicalTest*>(tests.begin(), tests.end()));
    pad(_ui->specifiedTests_tableView->horizontalHeader());
}

void RoomView::clearExaminationInfo() {
    _ui->recordId_lineEdit->clear();
    _ui->doctorId_lineEdit->clear();
    _ui->doctorName_lineEdit->clear();
    _ui->primaryDiagnose_lineEdit->clear();
    _ui->secondaryDiagnose_lineEdit->clear();
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

void RoomView::addTests(const QVector<std::string>& specifiedTests) {
    auto recordId = _ui->record_listView
        ->currentIndex().data().toString().toStdString();
    auto record = _service->findRecordById(recordId);
    record->clearOrderedTests();

    auto tests = _service->getAllTestService();
    for (const auto& testId : specifiedTests) {
        auto test = from(tests)
            .where(&TestService::id, testId)
            .findOne();
        record->orderClinicalTest(_service->createCinicalTest(
            test->id(), test->name(), test->cost()));
    }

    ServiceLocator::getInstance()->medicalRecordRepository()->update(*record);
}

void RoomView::changeRoom(int index) {
    auto room = ServiceLocator::getInstance()
        ->roomExaminationRepository()->data()[index];

    _ui->id_label->setText(QString::fromStdString(room->id()));
    _ui->name_label->setText(QString::fromStdString(room->name()));
    _ui->examinationSection_frame->setEnabled(0);
    clearExaminationInfo();
    clearPatientInfo();
    clearClinicalTests();

    static_cast<MedicalRecordListModel*>(_ui->record_listView->model())
        ->changeFilter(room->id());
}
