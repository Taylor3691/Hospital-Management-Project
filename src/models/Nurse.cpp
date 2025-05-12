#include "Nurse.h"

Nurse::Nurse(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address,
    const std::string& education,
    double baseSalary,
    const std::string& duty
) : Employee(id, name, dob, gender, phone,
    address, education, baseSalary), _duty(duty) {}

std::string Nurse::duty() const {
    return _duty;
}

void Nurse::setDuty(const std::string& duty) {
    _duty = duty;
}
