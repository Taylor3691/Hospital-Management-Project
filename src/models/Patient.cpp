#include "Patient.h"

Patient::Patient(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& phoneNumber,
    const std::string& dob,
    const std::string& address,
    HealthInsurance* insurance
) {
    _patientId = id;
    _name = name;
    _gender = gender;
    _phoneNumber = phoneNumber;
    _dateOfBirth = dob;
    _age = Date::getYear() - _dateOfBirth.year();
    _address = address;
    _insurance = insurance;
}

std::string Patient::id() const {
    return _patientId;
}

std::string Patient::name() const {
    return _name;
}

Date Patient::dob() const {
    return _dateOfBirth;
}

int Patient::age() const {
    return _age;
}

std::string Patient::gender() const {
    return _gender;
}

std::string Patient::phoneNumber() const {
    return _phoneNumber;
}

std::string Patient::address() const {
    return _address;
}

HealthInsurance* Patient::insurance() const {
    return _insurance;
}

void Patient::setId(const std::string& id) {
    _patientId = id;
}

void Patient::setName(const std::string& name) {
    _name = name;
}

void Patient::setDOB(const Date& dob) {
    _dateOfBirth = dob;
}

void Patient::setGender(const std::string& gender) {
    _gender = gender;
}

void Patient::setPhoneNumber(const std::string& phoneNumber) {
    _phoneNumber = phoneNumber;
}

void Patient::setAddress(const std::string& address) {
    _address = address;
}

void Patient::setInsurance(HealthInsurance* insurance) {
    _insurance = insurance;
}

bool Patient::hasInsurance() {
    return _insurance != nullptr;
}
