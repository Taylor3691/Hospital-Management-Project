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
    Doctor(const std::string& id, const std::string& name, const Date& dob, const Department& department,
        const Date& startWorkingAt, const std::string& specialty);

    std::string getSpecialty();
    const std::vector<Patient*>& getPatients();
    const std::vector<Appointment*>& getAppointments();
    void setSpecialty(const std::string& specialty);
    void addPatients(Patient* patient);
    void addAppointments(Appointment* appointment);
    void removePatients(Patient* patient);
    void removeAppointments(Appointment* appointment);
};

#endif
