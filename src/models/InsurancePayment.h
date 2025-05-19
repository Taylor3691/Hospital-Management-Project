#ifndef INSURANCE_PAYMENT_H
#define INSURANCE_PAYMENT_H

#include "../interfaces/IPaymentMethod.h"

class InsuranceMethod : public IPaymentMethod {
private:
    double _coveragePercent;

public:
    InsuranceMethod();
    InsuranceMethod(double percent);

public:
    double processPayment(double amount) const override;
};

#endif // !INSURANCE_PAYMENT_H
