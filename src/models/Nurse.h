#ifndef NURSE_H
#define NURSE_H

#include "Employee.h"

class Nurse : public Employee {
private:
    std::string _duty;

public:
    Nurse() = default;
    Nurse(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& address,
        const std::string& phone, const Date& dob, 
        const std::string& education, double baseSalary,
        const std::string& duty);

public:
    std::string duty() const;

public:
    void setDuty(const std::string& duty);
};

#endif // !NURSE_H
