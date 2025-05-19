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

void Patient::setAllergies(const std::vector<std::string>& allergies) {
    _allergies = allergies;
}

void Patient::setSymptoms(const std::vector<std::string>& symptoms) {
    _symptoms = symptoms;
}

void Patient::addAllergy(const std::string& allergy) {
    _allergies.push_back(allergy);
}

void Patient::addSymptom(const std::string& symptom) {
    _symptoms.push_back(symptom);
}

void Patient::removeAllergy(const std::string& allergy) {
    auto it = std::remove(_allergies.begin(), _allergies.end(), allergy);
    _allergies.erase(it, _allergies.end());
}

void Patient::removeSymptom(const std::string& symptom) {
    auto it = std::remove(_symptoms.begin(), _symptoms.end(), symptom);
    _symptoms.erase(it, _symptoms.end());
}

void Patient::clearAllergies() {
    _allergies.clear();
}

void Patient::clearSymptoms() {
    _symptoms.clear();
}
