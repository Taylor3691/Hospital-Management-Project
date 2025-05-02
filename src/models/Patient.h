#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "../utils/Date.h"
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

public:
    Patient(const std::string& id, const std::string& name, const std::string& gender,
        const std::string& phoneNumber, const std::string& dob, const std::string& address,
        HealthInsurance* insurance);

public:
    std::string id() const;
    std::string name() const;
    Date dob() const;
    int age() const;
    std::string gender() const;
    std::string phoneNumber() const;
    std::string address() const;
    HealthInsurance* insurance() const;

public:
    void setId(const std::string& id);
    void setName(const std::string& name);
    void setDOB(const Date& dob);
    void setGender(const std::string& gender);
    void setPhoneNumber(const std::string& phoneNumber);
    void setAddress(const std::string& address);
    void setInsurance(HealthInsurance* insurance);

public:
    bool hasInsurance();
};

#endif
