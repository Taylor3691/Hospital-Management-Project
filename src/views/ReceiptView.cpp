#include "ReceiptView.h"

ReceiptView::ReceiptView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ReceiptView)
{
    _ui->setupUi(this);

    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Thanh toán");
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet(
        "padding-left: 10px; padding-right: 10px;");

    _ui->record_listView->setModel(new MedicalRecordListModel(this));

    _ui->receiptDetail_tableView
        ->setModel(new BillableComponentTableModel(this));
    _ui->receiptDetail_tableView->verticalHeader()
        ->setStyleSheet("QHeaderView::section { padding-right: 10px; }");

    setStyleSheet("");
    setConnections();
    updateView();
}

ReceiptView::~ReceiptView() {
    delete _ui;
}

void ReceiptView::setConnections() {
    connect(_ui->notPaidYet_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto records = ServiceLocator::instance()->billService()
                ->getAllRecordsByState(ExaminationState::Completed);
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->paid_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto records = ServiceLocator::instance()->billService()
                ->getAllRecordsByState(ExaminationState::Paid);
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->allRecords_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto records = ServiceLocator::instance()->billService()
                ->getAllRecordsByState(ExaminationState::Completed);
            auto additionalRecords = ServiceLocator::instance()->billService()
                ->getAllRecordsByState(ExaminationState::Paid);
            records.reserve(records.size() + additionalRecords.size());
            for (auto& record : additionalRecords) {
                records.push_back(std::move(record));
            }
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->record_listView, &QListView::clicked, this,
        [this](const QModelIndex& index) {
            setReceiptInfo(index.data().toString().toStdString());
        });

    connect(_ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this,
        [this](bool) {
            if (!_ui->recordId_lineEdit->text().length()) {
                return warn("Vui lòng chọn một hồ sơ để thanh toán!");
            }

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto record = ServiceLocator::instance()
                ->examinationService()->findRecordById(recordId);

            if (record->state()->stateName() == ExaminationState::Paid) {
                return notify("Thông báo", "Bạn đã thanh toán cho hóa đơn này rồi!");
            }

            if (confirm("Xác nhận thanh toán", "Bạn có chắc chắn muốn thanh toán?")) {
                record->changeState(std::make_unique<PaidState>());
                ServiceLocator::instance()->medicalRecordRepository()->update(*record);

                notify("Kết quả thanh toán", "Bạn đã thanh toán thành công!");
                triggerRecordFilter();
            }
        });
}

void ReceiptView::triggerRecordFilter() {
    if (_ui->notPaidYet_radioButton->isChecked()) {
        emit _ui->notPaidYet_radioButton->toggled(1);
    }
    else if (_ui->paid_radioButton->isChecked()) {
        emit _ui->paid_radioButton->toggled(1);
    }
    else if (_ui->allRecords_radioButton->isChecked()) {
        emit _ui->allRecords_radioButton->toggled(1);
    }
}

void ReceiptView::setReceiptInfo(const std::string& recordId) {
    _ui->recordId_lineEdit->setText(QString::fromStdString(recordId));

    auto usages = ServiceLocator::instance()
        ->billService()->getAllMedicineUsagesInRecord(recordId);
    auto tests = ServiceLocator::instance()
        ->billService()->getAllClinicalTestsInRecord(recordId);
    std::vector<const BillableComponent*> data;
    for (const auto& usage : usages) {
        data.push_back(usage.get());
    }
    for (const auto& test : tests) {
        data.push_back(test.get());
    }
    static_cast<BillableComponentTableModel*>(
        _ui->receiptDetail_tableView->model())->setData(data);

    auto record = ServiceLocator::instance()
        ->examinationService()->findRecordById(recordId);

    auto totalCost = record->calculateFee();
    _ui->totalCost_doubleSpinBox->setValue(totalCost);

    auto patient = ServiceLocator::instance()
        ->examinationService()->findPatientById(record->patientId());
    auto coverage = 0.0;
    if (auto insurance = patient->insuranceCard()) {
        coverage = insurance->coveragePercent();
        _ui->insuranceCoverage_doubleSpinBox->setValue(coverage);
    }

    auto finalCost = totalCost * (100.0 - coverage) / 100.0;
    _ui->finalCost_doubleSpinBox->setValue(finalCost);
}

void ReceiptView::clearReceiptInfo() { 
    _ui->recordId_lineEdit->clear();
    _ui->totalCost_doubleSpinBox->setValue(0.0);
    _ui->insuranceCoverage_doubleSpinBox->setValue(0.0);
    _ui->finalCost_doubleSpinBox->setValue(0.0);
    static_cast<BillableComponentTableModel*>(
        _ui->receiptDetail_tableView->model())->setData({});
}

void ReceiptView::updateView() {
    clearReceiptInfo();
    triggerRecordFilter();
}
