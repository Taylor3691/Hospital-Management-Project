#include "Employee.h"

Employee::Employee(const std::string& employeeId, const std::string& name, const Date& dateOfBirth,
    const Department& department, const Date& startWorkingAt, double salary
) {
    _employeeId = employeeId;
    _name = name;
    _dateOfBirth = dateOfBirth;
    _department = department;
    _startWorkingAt = startWorkingAt;
    _salary = salary;
}

const std::tuple<std::string, std::string, Date, Date, double, std::vector<Assignment*>> Employee::getEmployeeInfo() {
    return { _employeeId, _name, _dateOfBirth, _startWorkingAt, _salary, _shiftList };
}

void Employee::updateDepartment(const Department& department) {
    _department = department;
}

void Employee::showShifts() {
    std::cout << "Employee's Shifts:\n";
    for (const auto& shift : _shiftList) {
        std::cout << *shift << std::endl;
    }
}

void Employee::addAssignment(Assignment* assignment) {
    _shiftList.push_back(assignment);
}
