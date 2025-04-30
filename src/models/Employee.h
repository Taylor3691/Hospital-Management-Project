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
    Department* _department;
    Date _startWorkingDate;
    double _salary;

public:
    Employee(const std::string& employeeId, const std::string& name,
        const Date& dateOfBirth, Department* department, const Date& startWorkingDate);

public:
    std::string id() const;
    std::string name() const;
    Date dob() const;
    Department* department() const;
    Date startWorkingDate() const;

public:
    void setId(const std::string& id);
    void setName(const std::string& name);
    void setDOB(const Date& dob);
    void setDepartment(Department* department);
    void setStartWorkingDate(const Date& date);
};

#endif
