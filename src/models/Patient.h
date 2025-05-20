#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <memory>
#include "Person.h"
#include "HealthInsurance.h"
#include "TxtWritingVisitor.h"
class Patient : public Person {
protected:
    std::vector<std::string> _symptoms;
    std::unique_ptr<HealthInsurance> _insuranceCard;

public:
    Patient() = default;
    Patient(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& address,
        const std::string& phone, const Date& dob,
        const std::vector<std::string>& allergies,
        std::unique_ptr<HealthInsurance> insuranceCard = nullptr);
    virtual ~Patient() = default;

public:
    std::vector<std::string> symptoms() const;
    const HealthInsurance* insuranceCard() const;

public:
    void setSymptoms(const std::vector<std::string>& allergies);
    void setInsuranceCard(std::unique_ptr<HealthInsurance> insuranceCard);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;

public:
    Patient& operator=(const Patient& other);
};

#endif
