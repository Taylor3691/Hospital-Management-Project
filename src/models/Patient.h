#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <memory>
#include "Person.h"

class Patient : public Person {
private:
    std::vector<std::string> _allergies;
    std::vector<std::string> _symptoms;
public:
    Patient(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address,
        const std::vector<std::string>& allergies, const std::vector<std::string>& symtoms);
    ~Patient();
public:
    std::vector<std::string> allergies();
    std::vector<std::string> symptoms();
};

#endif
