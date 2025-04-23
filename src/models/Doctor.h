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

    double calculateSalary() override;
    void viewPatientHistory(const Patient& patient); // should be in `Patient` class
    void prescribeMedicine(const Patient& patient, const Medicine& medicine); // should be in `Medicine` class
    void addAppointment(Appointment* appointment);
    void viewAppointments();
};

#endif
