#include "Doctor.h"

Doctor::Doctor(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const Department& department,
    const Date& startWorkingAt,
    const std::string& specialty
) : Employee(id, name, dob, department, startWorkingAt), _specialty(specialty) {}

std::string Doctor::getSpecialty() {
    return _specialty;
}

const std::vector<Patient*>& Doctor::getPatients() {
    return _patients;
}

const std::vector<Appointment*>& Doctor::getAppointments() {
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
    for (auto it = _patients.begin(); it != _patients.end(); ++it) {
        if ((*it) == patient) {
            _patients.erase(it);
            return;
        }
    }
}

void Doctor::removeAppointments(Appointment* appointment) {
    for (auto it = _appointments.begin(); it != _appointments.end(); ++it) {
        if ((*it) == appointment) {
            _appointments.erase(it);
            return;
        }
    }
}
