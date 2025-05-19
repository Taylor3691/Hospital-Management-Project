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
    Patient() = default;
    Patient(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address,
        const std::vector<std::string>& allergies, const std::vector<std::string>& symtoms);
    ~Patient();

public:
    std::vector<std::string> allergies();
    std::vector<std::string> symptoms();

public:
    void setAllergies(const std::vector<std::string>& allergies);
    void setSymptoms(const std::vector<std::string>& symptoms);
    void addAllergy(const std::string& allergy);
    void addSymptom(const std::string& symptom);
    void removeAllergy(const std::string& allergy);
    void removeSymptom(const std::string& symptom);
    void clearAllergies();
    void clearSymptoms();
};

#endif
