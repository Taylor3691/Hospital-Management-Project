#include "ParaclinicalView.h"

ParaclinicalView::ParaclinicalView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ParaclinicalView)
{
    _ui->setupUi(this);

    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Xong");
    _ui->record_listView->setModel(new MedicalRecordListModel(this));

    _ui->specifiedTests_tableView
        ->setModel(new ClinicalTestTableModel(this));
    _ui->specifiedTests_tableView->verticalHeader()
        ->setStyleSheet("QHeaderView::section { padding-right: 10px; }");

    setStyleSheet("");
    setConnections();
    updateView();
}

ParaclinicalView::~ParaclinicalView() {
    delete _ui;
}

void ParaclinicalView::setConnections() {
    connect(_ui->waiting_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto records = ServiceLocator::instance()
                ->testProcessingService()->getMedicalRecordsByTestState();
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->completed_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto records = ServiceLocator::instance()
                ->testProcessingService()->getMedicalRecordsByTestState(true);
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->allRecords_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto records = ServiceLocator::instance()
                ->testProcessingService()->getMedicalRecordsHaveTests();
            static_cast<MedicalRecordListModel*>(
                _ui->record_listView->model())->setData(records);
        });

    connect(_ui->notTestedYet_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto results = ServiceLocator::instance()
                ->testProcessingService()->getClinicalTestsByState(recordId);
            std::vector<const ClinicalTest*> tests;
            for (const auto& test : results) {
                tests.push_back(test.get());
            }
            static_cast<ClinicalTestTableModel*>(_ui->specifiedTests_tableView
                ->model())->setData(tests);
            pad(_ui->specifiedTests_tableView->horizontalHeader());
        });

    connect(_ui->tested_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto results = ServiceLocator::instance()
                ->testProcessingService()->getClinicalTestsByState(recordId, true);
            std::vector<const ClinicalTest*> tests;
            for (const auto& test : results) {
                tests.push_back(test.get());
            }
            static_cast<ClinicalTestTableModel*>(_ui->specifiedTests_tableView
                ->model())->setData(tests);
            pad(_ui->specifiedTests_tableView->horizontalHeader());
        });

    connect(_ui->allTests_radioButton, &QRadioButton::toggled, this,
        [this](bool checked) {
            if (!checked) {
                return;
            }

            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto record = ServiceLocator::instance()
                ->examinationService()->findRecordById(recordId);
            static_cast<ClinicalTestTableModel*>(_ui->specifiedTests_tableView
                ->model())->setData(record->clinicalTests());
            pad(_ui->specifiedTests_tableView->horizontalHeader());
        });

    connect(_ui->record_listView, &QListView::clicked, this,
        [this](const QModelIndex& index) {
            _ui->testSection_frame->setEnabled(1);
            _ui->recordId_lineEdit->setText(index.data().toString());
            triggerTestFilter();
        });

    connect(_ui->specifiedTests_tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this,
        [this](const QItemSelection&, const QItemSelection&) {
            auto selectedRows = _ui->specifiedTests_tableView
                ->selectionModel()->selectedRows();
            auto test = static_cast<ClinicalTest*>(
                selectedRows[0].data(Qt::UserRole).value<void*>());
            setClinicalTest(test);
        });

    connect(_ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked,
        this, [this](bool) {
            auto recordId = _ui->recordId_lineEdit->text().toStdString();
            auto record = ServiceLocator::instance()
                ->examinationService()->findRecordById(recordId);

            if (record->state()->getStateName() != ExaminationState::TestPending) {
                clearTestInfo();
                return warn("Không thể cập nhật kết quả kiểm tra với trạng thái hiện tại");
            }

            if (!_ui->id_lineEdit->text().length()) {
                return warn("Mã phiếu không hợp lệ!");
            }

            if (!_ui->result_plainTextEdit->toPlainText().length()) {
                return warn("Kết quả kiểm tra không thể để trống!");
            }

            auto tests = ServiceLocator::instance()
                ->testProcessingService()->getClinicalTestsByState(recordId);
            auto completed = tests.size() == 1;
            if (completed) {
                record->changeState(std::make_unique<ExaminingState>());
            }
            record->orderClinicalTest(getClinicalTest());
            ServiceLocator::instance()->medicalRecordRepository()->update(*record);

            if (completed) {
                triggerRecordFilter();
            }
            clearTestInfo();
            triggerTestFilter();
        });
}

void ParaclinicalView::triggerRecordFilter() {
    if (_ui->waiting_radioButton->isChecked()) {
        emit _ui->waiting_radioButton->toggled(1);
    }
    else if (_ui->completed_radioButton->isChecked()) {
        emit _ui->completed_radioButton->toggled(1);
    }
    else if (_ui->allRecords_radioButton->isChecked()) {
        emit _ui->allRecords_radioButton->toggled(1);
    }
}

void ParaclinicalView::triggerTestFilter() {
    if (_ui->notTestedYet_radioButton->isChecked()) {
        emit _ui->notTestedYet_radioButton->toggled(1);
    }
    else if (_ui->tested_radioButton->isChecked()) {
        emit _ui->tested_radioButton->toggled(1);
    }
    else if (_ui->allTests_radioButton->isChecked()) {
        emit _ui->allTests_radioButton->toggled(1);
    }
}

void ParaclinicalView::setClinicalTest(const ClinicalTest* test) {
    _ui->id_lineEdit->setText(QString::fromStdString(test->id()));
    _ui->testName_lineEdit->setText(QString::fromStdString(test->name()));
    _ui->testId_lineEdit->setText(QString::fromStdString(test->testId()));
    _ui->cost_doubleSpinBox->setValue(test->cost());
    _ui->state_lineEdit->setText(
        test->completed() ? "Đã kiểm tra" : "Chưa kiểm tra");
    _ui->result_plainTextEdit->setPlainText(
        QString::fromStdString(test->result()));
}

std::unique_ptr<ClinicalTest> ParaclinicalView::getClinicalTest() {
    return std::make_unique<ClinicalTest>(
        _ui->id_lineEdit->text().toStdString(),
        _ui->testName_lineEdit->text().toStdString(),
        _ui->testId_lineEdit->text().toStdString(),
        _ui->cost_doubleSpinBox->value(),
        _ui->result_plainTextEdit->toPlainText().toStdString(),
        true
    );
}

void ParaclinicalView::clearTestInfo() {
    _ui->id_lineEdit->clear();
    _ui->testName_lineEdit->clear();
    _ui->testId_lineEdit->clear();
    _ui->cost_doubleSpinBox->setValue(0.0);
    _ui->state_lineEdit->clear();
    _ui->result_plainTextEdit->clear();
}

void ParaclinicalView::updateView() {
    _ui->testSection_frame->setEnabled(0);
    _ui->recordId_lineEdit->clear();
    static_cast<ClinicalTestTableModel*>(_ui->specifiedTests_tableView
        ->model())->setData({});
    triggerRecordFilter();
}
