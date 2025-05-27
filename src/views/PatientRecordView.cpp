#include "PatientRecordView.h"

PatientRecordView::PatientRecordView(
    const QString& styleSheet,
    Role role,
    QWidget* parent
)
    : QDialog(parent)
    , _ui(new Ui::PatientRecordView)
{
    setup(styleSheet, role);
    setConnections();
}

PatientRecordView::~PatientRecordView() {
    delete _ui;
}

void PatientRecordView::setup(const QString& styleSheet, Role role) {
    _ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::Sheet);
    setStyleSheet(styleSheet);

    setInsuranceFieldsEnabled(0);

    _ui->buttonBox->button(QDialogButtonBox::StandardButton::Cancel)->setText("Hủy");

    _ui->id_label->setEnabled(0);
    _ui->id_lineEdit->setEnabled(0);

    if (role == Role::Add) {
        setWindowTitle("Thêm bệnh nhân");
        setAcceptButtonText("Thêm");

        auto data = ServiceLocator::getInstance()->patientManager()->getAll();
        std::vector<const Object*> objectData(data.begin(), data.end());
        auto newId = createId(objectData, getFormat<Patient>());
        _ui->id_lineEdit->setText(QString::fromStdString(newId));
    }
    else if (role == Role::Update) {
        setWindowTitle("Cập nhật thông tin");
        setAcceptButtonText("Lưu");
    }
}

void PatientRecordView::setConnections() {
    connect(_ui->cardId_lineEdit, &QLineEdit::textChanged, this,
        [this](const QString& text) {
            setInsuranceFieldsEnabled(text.size());
        });
}

void PatientRecordView::setInsuranceFieldsEnabled(bool enable) {
    _ui->issueDate_label->setEnabled(enable);
    _ui->issueDate_dateEdit->setEnabled(enable);
    _ui->expiryDate_label->setEnabled(enable);
    _ui->expiryDate_dateEdit->setEnabled(enable);
    _ui->coveragePercent_label->setEnabled(enable);
    _ui->coveragePercent_doubleSpinBox->setEnabled(enable);
}

std::unique_ptr<Patient> PatientRecordView::getPatient() const {
    auto patient = std::make_unique<Patient>();

    patient->setId(_ui->id_lineEdit->text().toStdString());
    patient->setName(_ui->name_lineEdit->text().toStdString());
    patient->setGender(_ui->gender_comboBox->currentIndex() ? "Nu" : "Nam");
    patient->setAddress(_ui->address_lineEdit->text().toStdString());
    patient->setPhone(_ui->phone_lineEdit->text().toStdString());
    auto date = _ui->dob_dateEdit->date();
    patient->setDob({ date.day(), date.month(), date.year() });

    auto insuranceId = _ui->cardId_lineEdit->text();
    if (insuranceId != "") {
        auto insurance = std::make_unique<HealthInsurance>();
        insurance->setId(insuranceId.toStdString());
        date = _ui->issueDate_dateEdit->date();
        insurance->setIssueDate({ date.day(), date.month(), date.year() });
        date = _ui->expiryDate_dateEdit->date();
        insurance->setExpiryDate({ date.day(), date.month(), date.year() });
        insurance->setCoveragePercent(_ui->coveragePercent_doubleSpinBox->value());

        patient->setInsuranceCard(std::move(insurance));
    }

    return std::move(patient);
}

void PatientRecordView::setPatient(const Patient* patient) {
    if (!patient) {
        return;
    }

    _ui->id_lineEdit->setText(QString::fromStdString(patient->id()));
    _ui->name_lineEdit->setText(QString::fromStdString(patient->name()));
    _ui->gender_comboBox->setCurrentIndex(patient->gender() == "Nu");
    _ui->address_lineEdit->setText(QString::fromStdString(patient->address()));
    _ui->phone_lineEdit->setText(QString::fromStdString(patient->phone()));
    auto dob = patient->dob();
    _ui->dob_dateEdit->setDate({ dob.year(), dob.month(), dob.day() });

    auto insurance = patient->insuranceCard();
    if (insurance) {
        _ui->cardId_lineEdit->setText(QString::fromStdString(insurance->id()));
        auto date = insurance->issueDate();
        _ui->issueDate_dateEdit->setDate({ date.year(), date.month(), date.day() });
        date = insurance->expiryDate();
        _ui->expiryDate_dateEdit->setDate({ date.year(), date.month(), date.day() });
        _ui->coveragePercent_doubleSpinBox->setValue(insurance->coveragePercent());
    }
    setInsuranceFieldsEnabled(insurance);
}

void PatientRecordView::setAcceptButtonText(const QString& text) {
    _ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setText(text);
}

void PatientRecordView::disableNotEditableFields() {
    _ui->id_label->setEnabled(0);
    _ui->id_lineEdit->setEnabled(0);
}
