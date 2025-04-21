#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "../utils/Date.h"
#include "Assignment.h"
#include "Department.h"

class Employee {
private:
    std::string _employeeId;
    std::string _name;
    Date _dateOfBirth;
    Date _startWorkingAt;
    double _salary;
    std::vector<Assignment*> _shiftList;

public:
    Employee(const std::string& employeeId, const std::string& name, const Date& dateOfBirth,
        const Date& startWorkingAt, double salary, const std::vector<Assignment*>& shiftList);

    void getEmployeeInfo();
    void updateDepartment(const Department&);
    void showShifts();
    void addAssignment(const Assignment&);
    
    virtual double calculateSalary() = 0;
};

#endif
