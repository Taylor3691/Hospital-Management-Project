#ifndef DOCTOR_H
#define DOCTOR_H

#include "Employee.h"
#include "Patient.h"
#include "Medicine.h"

class Doctor : public Employee {
private:
    std::string _specialty;
    std::vector<Patient*> _patients;

public:
    Doctor(const std::string& name);

    double calculateSalary() override;
    void viewPatientHistory(const Patient& patient);
    void prescribeMedicine(const Patient& patient, const Medicine& medicine);
    void addAppointment(const Appointment& appointment);
    void viewSchedule();
};

#endif
