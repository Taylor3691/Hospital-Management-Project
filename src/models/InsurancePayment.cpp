#include "InsurancePayment.h"

InsuranceMethod::InsuranceMethod()
    : _coveragePercent() {}

InsuranceMethod::InsuranceMethod(double percent)
    : _coveragePercent(percent) {}

double InsuranceMethod::processPayment(double amount) const {
    return amount * (100 - _coveragePercent) / 100;
}
