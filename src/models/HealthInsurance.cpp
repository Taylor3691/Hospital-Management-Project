#include "HealthInsurance.h"

HealthInsurance::HealthInsurance()
    : _coveragePercent() {}

HealthInsurance::HealthInsurance(
    const std::string& id,
    const Date& issueDate,
    const Date& expiryDate,
    double percent
)
    : Object(id, "")
    , _issueDate(issueDate)
    , _expiryDate(expiryDate)
    , _coveragePercent(percent) {}

Date HealthInsurance::issueDate() const {
    return _issueDate;
}

Date HealthInsurance::expiryDate() const {
    return _expiryDate;
}

double HealthInsurance::coveragePercent() const {
    return _coveragePercent;
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

Object* HealthInsurance::clone() const {
    return new HealthInsurance(*this);
}

