#include "Nurse.h"

Nurse::Nurse(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const Department& department,
    const Date& startWorkingAt,
    double salary
) : Employee(id, name, dob, department, startWorkingAt, salary) {}

double Nurse::calculateSalary() {
    // TODO: use an appropriate formula
    return _salary;
}
