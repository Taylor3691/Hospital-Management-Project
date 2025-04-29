#include "Employee.h"

Employee::Employee(
    const std::string& employeeId,
    const std::string& name,
    const Date& dateOfBirth,
    const Department& department,
    const Date& startWorkingAt
) {
    _employeeId = employeeId;
    _name = name;
    _dateOfBirth = dateOfBirth;
    _department = department;
    _startWorkingAt = startWorkingAt;
    _salary = 0;
}

void Employee::updateDepartment(const Department& department) {
    _department = department;
}

