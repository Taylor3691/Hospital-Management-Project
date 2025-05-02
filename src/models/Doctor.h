#ifndef DOCTOR_H
#define DOCTOR_H

#include "Employee.h"
#include "Patient.h"
#include "Medicine.h"

class Doctor : public Employee {
private:
    std::string _specialty;

public:
    Doctor(const std::string& id, const std::string& name, const Date& dob, Department* department,
        const Date& startWorkingDate, const std::string& specialty);

public:
    std::string specialty();

public:
    void setSpecialty(const std::string& specialty);
};

#endif
