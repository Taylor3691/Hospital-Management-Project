#include "Patient.h"

Patient::Patient(const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::vector<std::string>& allergies,
    std::unique_ptr<HealthInsurance> insuranceCard
)
    : Person(id, name, gender, address, phone, dob)
    , _allergies(allergies)
    , _insuranceCard(std::move(insuranceCard)) {}

Patient::Patient(const Patient& other) :
    Person(other.id(), other.name(), other.gender(), other.address(), other.phone(), other.dob()),
    _allergies(other.allergies()),
    _insuranceCard(other.insuranceCard() ? std::make_unique<HealthInsurance>(*other.insuranceCard()) : nullptr)
{}

std::vector<std::string> Patient::allergies() const {
    return _allergies;
}

const HealthInsurance* Patient::insuranceCard() const {
    return _insuranceCard.get();
}

void Patient::allergies(
    const std::vector<std::string>& allergies
) {
    _allergies = allergies;
}

void Patient::insuranceCard(
    std::unique_ptr<HealthInsurance> insuranceCard
) {
    _insuranceCard = std::move(insuranceCard);
}

Object* Patient::clone() {
    return new Patient(*this);
}

void Patient::acceptWrite(IVisitor* visitor, std::ostream& os) {
    
}
