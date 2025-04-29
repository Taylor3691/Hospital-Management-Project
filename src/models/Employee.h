#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include <tuple>
#include "../utils/Date.h"
#include "Department.h"

class Employee {
protected:
    std::string _employeeId;
    std::string _name;
    Date _dateOfBirth;
    Department _department;
    Date _startWorkingAt;
    double _salary;

public:
    Employee(const std::string& employeeId, const std::string& name, const Date& dateOfBirth,
        const Department& department, const Date& startWorkingAt);

    void updateDepartment(const Department& department);
};

#endif
