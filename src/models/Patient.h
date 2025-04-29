#ifndef PATIENT_H
#define PATIENT_H

#include <tuple>
#include <string>
#include <vector>
#include <iostream>
#include "../utils/Date.h"
#include "MedicalRecord.h"
#include "Appointment.h"
#include "Service.h"
#include "HealthInsurance.h"

class Patient {
private:
    std::string _patientId;
    std::string _name;
    Date _dateOfBirth;
    int _age;
    std::string _gender;
    std::string _phoneNumber;
    std::string _address;
    HealthInsurance* _insurance;
    std::vector<MedicalRecord*> _medicalRecords;
    std::vector<Appointment*> _appointments;
    std::vector<Service*> _usedServices;

public:
    Patient(const std::string& id, const std::string& name, const std::string& gender, const std::string& phone,
        const std::string& dob, const std::string& address, HealthInsurance* insurance);

    void updatePersonalInfo(const std::string& id, const std::string& name,
        const std::string& dob, const std::string& gender, HealthInsurance* insurance);
    void updateConnectInfo(const std::string& phone, const std::string& address);
    const std::tuple<std::string, std::string, Date, std::string, std::string, HealthInsurance*>& getPatientInfo();
    bool hasInsurance();
    void setInsurance(HealthInsurance* insurance);
    const std::vector<MedicalRecord*>& getMedicalRecords();
    const std::vector<Appointment*>& getAppointments();
    const std::vector<Service*>& getUsedServices();
    void addMedicalRecord(MedicalRecord* medicalRecord);
    void addAppointment(Appointment* appointment);
    void addUsedService(Service* service);
    void removeMedicalRecord(MedicalRecord* medicalRecord);
    void removeAppointment(Appointment* appointment);
    void removeUsedService(Service* service);
};

#endif
