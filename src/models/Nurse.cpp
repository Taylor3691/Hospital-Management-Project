#include "Nurse.h"

Nurse::Nurse(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::string& education,
    double baseSalary,
    const std::string& duty
)
    : Employee(id, name, gender, address,
        phone, dob, education, baseSalary)
    , _duty(duty) {}

Nurse::Nurse(const Nurse& other) :
    Employee(other.id(), other.name(), other.gender(), other.address(), other.phone(),
        other.dob(), other.education(), other.baseSalary()),
    _duty(other.duty()) {}

std::string Nurse::duty() const {
    return _duty;
}

void Nurse::setDuty(const std::string& duty) {
    _duty = duty;
}

void Nurse::acceptWrite(IVisitor* visitor, std::ostream& os) {
    dynamic_cast<TxtWritingVisitor*>(visitor)->write(this, os);
}

Object* Nurse::clone() const {
    return new Nurse(*this);
}
