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
