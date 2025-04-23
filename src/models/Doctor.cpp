#include "Doctor.h"

Doctor::Doctor(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const Department& department,
    const Date& startWorkingAt,
    const std::string& specialty
) : Employee(id, name, dob, department, startWorkingAt), _specialty(specialty) {}

double Doctor::calculateSalary() {
    // TODO: use an appropriate formula
    return _salary;
}

void Doctor::addAppointment(Appointment* appointment) {
    _appointments.push_back(appointment);
}

void Doctor::viewAppointments() {
    std::cout << "Doctor's Apppointments:\n";
    for (const auto& appointment : _appointments) {
        std::cout << *appointment << std::endl;
    }
}
