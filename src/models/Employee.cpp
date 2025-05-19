#include "Employee.h"

Employee::Employee(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::string& education,
    double baseSalary
)
    : Person(id, name, gender, address, phone, dob)
    , _education(education)
    , _baseSalary(baseSalary) {}

std::string Employee::education() const {
    return _education;
}

double Employee::baseSalary() const {
    return _baseSalary;
}

void Employee::setEducation(const std::string& education) {
    _education = education;
}

void Employee::setBaseSalary(double salary) {
    _baseSalary = salary;
}
