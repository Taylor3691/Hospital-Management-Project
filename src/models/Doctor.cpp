#include "Doctor.h"

Doctor::Doctor(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    Department* department,
    const Date& startWorkingDate,
    const std::string& specialty
) : Employee(id, name, dob, department, startWorkingDate), _specialty(specialty) {}

std::string Doctor::specialty() {
    return _specialty;
}

std::vector<Patient*> Doctor::patients() {
    return _patients;
}

std::vector<Appointment*> Doctor::appointments() {
    return _appointments;
}

void Doctor::setSpecialty(const std::string& specialty) {
    _specialty = specialty;
}

void Doctor::addPatients(Patient* patient) {
    _patients.push_back(patient);
}

void Doctor::addAppointments(Appointment* appointment) {
    _appointments.push_back(appointment);
}

void Doctor::removePatients(Patient* patient) {
    std::erase_if(_patients, [&patient](Patient* p) { return p == patient; });
}

void Doctor::removeAppointments(Appointment* appointment) {
    std::erase_if(_appointments, [&appointment](Appointment* a) { return a == appointment; });
}
