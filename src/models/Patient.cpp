#include "Patient.h"

Patient::Patient(const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::vector<std::string>& symptoms,
    std::unique_ptr<HealthInsurance> insuranceCard
)
    : Person(id, name, gender, address, phone, dob)
    , _symptoms(symptoms)
    , _insuranceCard(std::move(insuranceCard)) {}

Patient::Patient(const Patient& other) :
    Person(other.id(), other.name(), other.gender(), other.address(), other.phone(), other.dob()),
    _symptoms(other.symptoms()),
    _insuranceCard(other.insuranceCard() ? std::make_unique<HealthInsurance>(*other.insuranceCard()) : nullptr)
{}
std::vector<std::string> Patient::symptoms() const {
    return _symptoms;
}

const HealthInsurance* Patient::insuranceCard() const {
    return _insuranceCard.get();
}

void Patient::setSymptoms(
    const std::vector<std::string>& symptoms
) {
    _symptoms = symptoms;
}

void Patient::setInsuranceCard(
    std::unique_ptr<HealthInsurance> insuranceCard
) {
    _insuranceCard = std::move(insuranceCard);
}

void Patient::acceptWrite(IVisitor* visitor, std::ostream& os) {
    dynamic_cast<TxtWritingVisitor*>(visitor)->write(this, os);
}

Object* Patient::clone() const {
    return new Patient(*this);
}

Patient& Patient::operator=(
    const Patient& other
    ) {
    if (this != &other) {
        Person::operator=(other);
        _symptoms = other._symptoms;
        _insuranceCard = std::make_unique<HealthInsurance>(*other._insuranceCard);
    }
    return *this;
}
