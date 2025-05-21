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

Employee::Employee(const Employee& other)
    : Person(other.id(), other.name(), other.gender(), other.address(), other.phone(), other.dob()),
    _education(other.education()),
    _baseSalary(other.baseSalary()) {}

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

Object* Employee::clone() {
    return new Employee(*this);
}

void Employee::acceptWrite(IVisitor* visitor, std::ostream& os) {

}
