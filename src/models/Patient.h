#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <memory>
#include "Person.h"
#include "HealthInsurance.h"

class Patient : public Person {
private:
    std::vector<std::string> _allergies;
    std::unique_ptr<HealthInsurance> _insuranceCard;

public:
    Patient() = default;
    Patient(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& address,
        const std::string& phone, const Date& dob,
        const std::vector<std::string>& allergies,
        std::unique_ptr<HealthInsurance> insuranceCard = nullptr);

public:
    std::vector<std::string> allergies() const;
    const HealthInsurance* insuranceCard() const;

public:
    void allergies(const std::vector<std::string>& allergies);
    void insuranceCard(std::unique_ptr<HealthInsurance> insuranceCard);
};

#endif
