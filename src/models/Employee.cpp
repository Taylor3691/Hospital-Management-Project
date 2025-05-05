#include "Employee.h"

Employee::Employee(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address,
    const Date& startWorkingAt,
    const std::string& education,
    double baseSalary
) : Person(id, name, dob, gender, phone, address) {
    _startWorkingAt = startWorkingAt;
    _education = education;
    _baseSalary = baseSalary;
}

Date Employee::startWorkingAt() const {
    return _startWorkingAt;
}

std::string Employee::education() const {
    return _education;
}

double Employee::baseSalary() const {
    return _baseSalary;
}
