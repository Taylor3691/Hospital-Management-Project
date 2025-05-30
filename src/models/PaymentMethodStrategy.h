#ifndef PAYMENT_METHOD_STRATEGY_H
#define PAYMENT_METHOD_STRATEGY_H

#include "NormalPayment.h"
#include "InsurancePayment.h"
#include "Patient.h"
#include "HealthInsurance.h"

class PaymentMethodStrategy {
public:
    static IPaymentMethod* getPaymentMethod(Patient* patient);
};

#endif // !PAYMENT_METHOD_STRATEGY_H
