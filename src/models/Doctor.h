#ifndef DOCTOR_H
#define DOCTOR_H

#include "Employee.h"
#include "Patient.h"
#include "Medicine.h"

class Doctor : public Employee {
private:
    std::string _specialty;
    std::vector<Patient*> _patients;
    std::vector<Appointment*> _appointments;

public:
    Doctor(const std::string& id, const std::string& name, const Date& dob, Department* department,
        const Date& startWorkingDate, const std::string& specialty);

public:
    std::string specialty();
    std::vector<Patient*> patients();
    std::vector<Appointment*> appointments();

public:
    void setSpecialty(const std::string& specialty);

public:
    void addPatients(Patient* patient);
    void addAppointments(Appointment* appointment);
    void removePatients(Patient* patient);
    void removeAppointments(Appointment* appointment);
};

#endif
