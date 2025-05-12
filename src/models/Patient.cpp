#include "Patient.h"

Patient::Patient(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address,
    const std::vector<std::string>& allergies,
    const std::vector<std::string>& symptoms
) : Person(id, name, dob, gender, phone, address) {
    _allergies = allergies;
    _symptoms = symptoms;
}


Patient::~Patient() {
    _allergies.clear();
    _symptoms.clear();
}

std::vector<std::string> Patient::allergies() {
    return _allergies;
}

std::vector<std::string> Patient::symptoms() {
    return _symptoms;
}

