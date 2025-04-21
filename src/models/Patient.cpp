#include "Patient.h"

Patient::Patient(const std::string& id, const std::string& name, const std::string& gender, const std::string& phone, const std::string& dob, const std::string& address) {
    _patientId = id;
    _name = name;
    _gender = gender;
    _phoneNumber = phone;
    _dateOfBirth = dob;
    _age = Date::getYear() - _dateOfBirth.year();
    _address = address;
}

void Patient::updatePersonalInfo(const std::string& id, const std::string& name, const std::string& dob, const std::string& gender) {
    _patientId = id;
    _name = name;
    _dateOfBirth = dob;
    _gender = gender;
}

void Patient::updateConnectInfo(const std::string& phone, const std::string& address) {
    _phoneNumber = phone;
    _address = address;
}

const std::tuple<std::string, std::string, Date, std::string, std::string>& Patient::getPatientInfo() {
    return { _patientId, _name, _dateOfBirth, _phoneNumber, _address };
}

void Patient::viewMedicalRecords() {
    for (const auto& record : _medicalRecords) {
        std::cout << *record << std::endl;
    }
}

void Patient::viewAppointments() {
    for (const auto& appointment : _appointments) {
        std::cout << *appointment << std::endl;
    }
}
