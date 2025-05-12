#ifndef DOCTOR_H
#define DOCTOR_H

#include "Employee.h"

class Doctor : public Employee {
private:
    std::string _specialty;
    std::string _license;

public:
    Doctor() = default;
    Doctor(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address,
        const std::string& education, double baseSalary, const std::string& specialty,
        const std::string& license);

public:
    std::string specialty() const;
    std::string license() const;

public:
    void setSpecialty(const std::string& specialty);
    void setLicense(const std::string& license);
};

#endif // !DOCTOR_H
