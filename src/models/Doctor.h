#ifndef DOCTOR_H
#define DOCTOR_H

#include <vector>
#include "Employee.h"

class Doctor : public Employee {
private:
    std::vector<std::string> _specialty;

public:
    Doctor(const std::string& id, const std::string& name, const Date& dob, const std::string& gender,
        const std::string& phone, const std::string& address, const Date& startWorkingAt,
        const std::string& education, double baseSalary, const std::vector<std::string>& specialty);

public:
    std::vector<std::string>& specialty();
};

#endif
