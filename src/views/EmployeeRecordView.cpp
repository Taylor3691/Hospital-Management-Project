#include "EmployeeRecordView.h"

EmployeeRecordView::EmployeeRecordView(const QString& styleSheet, QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::EmployeeRecordView)
{
    setup(styleSheet);
    setConnections();
}

EmployeeRecordView::~EmployeeRecordView() {
    delete _ui;
}

void EmployeeRecordView::setup(const QString& styleSheet) {
    _ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::Sheet);
    setStyleSheet(styleSheet);

    _ui->buttonBox->button(QDialogButtonBox::StandardButton::Cancel)->setText("Hủy");

    _ui->duty_label->setEnabled(0);
    _ui->duty_lineEdit->setEnabled(0);
    _ui->subsidies_label->setEnabled(0);
    _ui->subsidies_doubleSpinBox->setEnabled(0);
    _ui->workingDays_label->setEnabled(0);
    _ui->workingDays_spinBox->setEnabled(0);
}

void EmployeeRecordView::setConnections() {
    connect(_ui->role_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
        [this](int index) {
            auto isDoctor = (EmployeeType)index == EmployeeType::Doctor;
            auto isNurse = (EmployeeType)index == EmployeeType::Nurse;
            auto isReceptionist = (EmployeeType)index == EmployeeType::Receptionist;

            _ui->specialty_label->setEnabled(isDoctor);
            _ui->specialty_lineEdit->setEnabled(isDoctor);
            _ui->license_label->setEnabled(isDoctor);
            _ui->license_lineEdit->setEnabled(isDoctor);

            _ui->duty_label->setEnabled(isNurse);
            _ui->duty_lineEdit->setEnabled(isNurse);

            _ui->subsidies_label->setEnabled(isReceptionist);
            _ui->subsidies_doubleSpinBox->setEnabled(isReceptionist);
            _ui->workingDays_label->setEnabled(isReceptionist);
            _ui->workingDays_spinBox->setEnabled(isReceptionist);
        });
}

std::unique_ptr<Employee> EmployeeRecordView::getEmployee() const {
    auto index = (EmployeeType)_ui->role_comboBox->currentIndex();
    if (index == EmployeeType::Doctor) {
        auto doctor = std::make_unique<Doctor>();

        doctor->setId(_ui->id_lineEdit->text().toStdString());
        doctor->setName(_ui->name_lineEdit->text().toStdString());
        doctor->setGender(_ui->gender_comboBox->currentText().toStdString());
        doctor->setAddress(_ui->address_lineEdit->text().toStdString());
        doctor->setPhone(_ui->phone_lineEdit->text().toStdString());
        auto date = _ui->dob_dateEdit->date();
        doctor->setDob({ date.day(), date.month(), date.year() });
        doctor->setEducation(_ui->education_lineEdit->text().toStdString());
        doctor->setBaseSalary(_ui->salary_doubleSpinBox->value());
        doctor->setSpecialty(_ui->specialty_lineEdit->text().toStdString());
        doctor->setLicense(_ui->license_lineEdit->text().toStdString());

        return std::move(doctor);
    }
    else if (index == EmployeeType::Nurse) {
        auto nurse = std::make_unique<Nurse>();

        nurse->setId(_ui->id_lineEdit->text().toStdString());
        nurse->setName(_ui->name_lineEdit->text().toStdString());
        nurse->setGender(_ui->gender_comboBox->currentText().toStdString());
        nurse->setAddress(_ui->address_lineEdit->text().toStdString());
        nurse->setPhone(_ui->phone_lineEdit->text().toStdString());
        auto date = _ui->dob_dateEdit->date();
        nurse->setDob({ date.day(), date.month(), date.year() });
        nurse->setEducation(_ui->education_lineEdit->text().toStdString());
        nurse->setBaseSalary(_ui->salary_doubleSpinBox->value());
        nurse->setDuty(_ui->duty_lineEdit->text().toStdString());

        return std::move(nurse);
    }
    else {
        auto receptionist = std::make_unique<Receptionist>();

        receptionist->setId(_ui->id_lineEdit->text().toStdString());
        receptionist->setName(_ui->name_lineEdit->text().toStdString());
        receptionist->setGender(_ui->gender_comboBox->currentText().toStdString());
        receptionist->setAddress(_ui->address_lineEdit->text().toStdString());
        receptionist->setPhone(_ui->phone_lineEdit->text().toStdString());
        auto date = _ui->dob_dateEdit->date();
        receptionist->setDob({ date.day(), date.month(), date.year() });
        receptionist->setEducation(_ui->education_lineEdit->text().toStdString());
        receptionist->setBaseSalary(_ui->salary_doubleSpinBox->value());
        receptionist->setSubsidies(_ui->subsidies_doubleSpinBox->value());
        receptionist->setWorkingDays(_ui->workingDays_spinBox->value());

        return std::move(receptionist);
    }
}

void EmployeeRecordView::setEmployee(const Employee* employee) {
    if (!employee) {
        return;
    }

    _ui->id_lineEdit->setText(QString::fromStdString(employee->id()));
    _ui->name_lineEdit->setText(QString::fromStdString(employee->name()));
    _ui->gender_comboBox->setCurrentText(QString::fromStdString(employee->gender()));
    _ui->address_lineEdit->setText(QString::fromStdString(employee->address()));
    _ui->phone_lineEdit->setText(QString::fromStdString(employee->phone()));
    auto dob = employee->dob();
    _ui->dob_dateEdit->setDate({ dob.year(), dob.month(), dob.day() });
    _ui->education_lineEdit->setText(QString::fromStdString(employee->education()));
    _ui->salary_doubleSpinBox->setValue(employee->baseSalary());

    if (auto doctor = dynamic_cast<const Doctor*>(employee)) {
        _ui->role_comboBox->setCurrentIndex((int)EmployeeType::Doctor);
        _ui->specialty_lineEdit->setText(QString::fromStdString(doctor->specialty()));
        _ui->license_lineEdit->setText(QString::fromStdString(doctor->license()));
    }
    else if (auto nurse = dynamic_cast<const Nurse*>(employee)) {
        _ui->role_comboBox->setCurrentIndex((int)EmployeeType::Nurse);
        _ui->duty_lineEdit->setText(QString::fromStdString(nurse->duty()));
    }
    else if (auto receptionist = dynamic_cast<const Receptionist*>(employee)) {
        _ui->role_comboBox->setCurrentIndex((int)EmployeeType::Receptionist);
        _ui->subsidies_doubleSpinBox->setValue(receptionist->subsidies());
        _ui->workingDays_spinBox->setValue(receptionist->workingDays());
    }
}

void EmployeeRecordView::setAcceptButtonText(const QString& text) {
    _ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setText(text);
}

void EmployeeRecordView::disableNotEditableFields() {
    _ui->id_label->setEnabled(0);
    _ui->id_lineEdit->setEnabled(0);
    _ui->role_label->setEnabled(0);
    _ui->role_comboBox->setEnabled(0);
}
