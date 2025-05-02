#include "HealthInsurance.h"

std::string HealthInsurance::id() const {
    return _insuranceId;
}

double HealthInsurance::serviceCoveragePercent() const {
    return _serviceCoveragePercent;
}

double HealthInsurance::medicineCoveragePercent() const {
    return _medicineCoveragePercent;
}

Date HealthInsurance::expiryDate() const {
    return _expiryDate;
}

void HealthInsurance::setId(const std::string& id) {
    _insuranceId = id;
}

void HealthInsurance::setServiceCoveragePercent(double percent) {
    _serviceCoveragePercent = percent;
}

void HealthInsurance::setMedicineCoveragePercent(double percent) {
    _medicineCoveragePercent = percent;
}

void HealthInsurance::setExpiryDate(const Date& date) {
    _expiryDate = date;
}

bool HealthInsurance::checkExpired() const {
    return _expiryDate <= Date::getDate();
}
