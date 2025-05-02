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

void Doctor::setSpecialty(const std::string& specialty) {
    _specialty = specialty;
}
