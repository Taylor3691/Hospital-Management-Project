#include "HealthInsurance.h"

HealthInsurance::HealthInsurance()
    : _coveragePercent() {}

HealthInsurance::HealthInsurance(
    const std::string& id,
    const std::string& name,
    const std::string& cardNumber,
    const Date& issueDate,
    const Date& expiryDate,
    double percent
)
    : Object(id, name)
    , _cardNumber(cardNumber)
    , _issueDate(issueDate)
    , _expiryDate(expiryDate)
    , _coveragePercent(percent) {}

std::string HealthInsurance::cardNumber() const {
    return _cardNumber;
}

Date HealthInsurance::issueDate() const {
    return _issueDate;
}

Date HealthInsurance::expiryDate() const {
    return _expiryDate;
}

double HealthInsurance::coveragePercent() const {
    return _coveragePercent;
}

void HealthInsurance::setCardNumber(const std::string& cardNumber) {
    _cardNumber = cardNumber;
}

void HealthInsurance::setIssueDate(const Date& date) {
    _issueDate = date;
}

void HealthInsurance::setExpiryDate(const Date& date) {
    _expiryDate = date;
}

void HealthInsurance::setCoveragePercent(const double& percent) {
    _coveragePercent = percent;
}

bool HealthInsurance::checkValid() const {
    return _expiryDate > Date::getDate();
}
