#include "Employee.h"

Employee::Employee(
    const std::string& employeeId,
    const std::string& name,
    const Date& dateOfBirth,
    Department* department,
    const Date& startWorkingDate
) {
    _employeeId = employeeId;
    _name = name;
    _dateOfBirth = dateOfBirth;
    _department = department;
    _startWorkingDate = startWorkingDate;
    _salary = 0;
}

std::string Employee::id() const {
    return _employeeId;
}

std::string Employee::name() const {
    return _name;
}

Date Employee::dob() const {
    return _dateOfBirth;
}

Department* Employee::department() const {
    return _department;
}

Date Employee::startWorkingDate() const {
    return _startWorkingDate;
}

void Employee::setId(const std::string& id) {
    _employeeId = id;
}

void Employee::setName(const std::string& name) {
    _name = name;
}

void Employee::setDOB(const Date& dob) {
    _dateOfBirth = dob;
}

void Employee::setDepartment(Department* department) {
    _department = department;
}

void Employee::setStartWorkingDate(const Date& date) {
    _startWorkingDate = date;
}
