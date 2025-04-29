#include "Patient.h"

Patient::Patient(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& phone,
    const std::string& dob,
    const std::string& address,
    HealthInsurance* insurance
) {
    _patientId = id;
    _name = name;
    _gender = gender;
    _phoneNumber = phone;
    _dateOfBirth = dob;
    _age = Date::getYear() - _dateOfBirth.year();
    _address = address;
    _insurance = insurance;
}

void Patient::updatePersonalInfo(
    const std::string& id,
    const std::string& name,
    const std::string& dob,
    const std::string& gender,
    HealthInsurance* insurance
) {
    _patientId = id;
    _name = name;
    _dateOfBirth = dob;
    _gender = gender;
    _insurance = insurance;
}

void Patient::updateConnectInfo(const std::string& phone, const std::string& address) {
    _phoneNumber = phone;
    _address = address;
}

const std::tuple<std::string, std::string, Date, std::string, std::string, HealthInsurance*>& Patient::getPatientInfo() {
    return { _patientId, _name, _dateOfBirth, _phoneNumber, _address, _insurance };
}

bool Patient::hasInsurance() {
    return _insurance != nullptr;
}

void Patient::setInsurance(HealthInsurance* insurance) {
    _insurance = insurance;
}

const std::vector<MedicalRecord*>& Patient::getMedicalRecords() {
    return _medicalRecords;
}

const std::vector<Appointment*>& Patient::getAppointments() {
    return _appointments;
}

const std::vector<Service*>& Patient::getUsedServices() {
    return _usedServices;
}

void Patient::addMedicalRecord(MedicalRecord* medicalRecord) {
    _medicalRecords.push_back(medicalRecord);
}

void Patient::addAppointment(Appointment* appointment) {
    _appointments.push_back(appointment);
}

void Patient::addUsedService(Service* service) {
    _usedServices.push_back(service);
}

void Patient::removeMedicalRecord(MedicalRecord* medicalRecord) {
    for (auto it = _medicalRecords.begin(); it != _medicalRecords.end(); ++it) {
        if ((*it) == medicalRecord) {
            _medicalRecords.erase(it);
            return;
        }
    }
}

void Patient::removeAppointment(Appointment* appointment) {
    for (auto it = _appointments.begin(); it != _appointments.end(); ++it) {
        if ((*it) == appointment) {
            _appointments.erase(it);
            return;
        }
    }
}

void Patient::removeUsedService(Service* service) {
    for (auto it = _usedServices.begin(); it != _usedServices.end(); ++it) {
        if ((*it) == service) {
            _usedServices.erase(it);
            return;
        }
    }
}
