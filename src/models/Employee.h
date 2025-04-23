#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include <tuple>
#include "../utils/Date.h"
#include "Assignment.h"
#include "Department.h"

class Employee {
protected:
    std::string _employeeId;
    std::string _name;
    Date _dateOfBirth;
    Department _department;
    Date _startWorkingAt;
    double _salary;
    std::vector<Assignment*> _shiftList;

public:
    Employee(const std::string& employeeId, const std::string& name, const Date& dateOfBirth,
        const Department& department, const Date& startWorkingAt);

    const std::tuple<std::string, std::string, Date, Date, double, std::vector<Assignment*>> getEmployeeInfo();
    void updateDepartment(const Department& department);
    void showShifts();
    void addAssignment(Assignment* assignment);
    
    virtual double calculateSalary() = 0;
};

#endif
