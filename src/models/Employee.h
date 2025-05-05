#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    Date _startWorkingAt;
    std::string _education;
    double _baseSalary;

public:
    Employee(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address,
        const Date& startWorkingAt, const std::string& education, double baseSalary);

public:
    Date startWorkingAt() const;
    std::string education() const;
    double baseSalary() const;
};

#endif
