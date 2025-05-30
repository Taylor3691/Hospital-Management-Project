#ifndef PAYMENTMETHODSTRATEGY_H_
#define PAYMENTMETHODSTRATEGY_H_

#include "NormalPayment.h"
#include "InsurancePayment.h"
#include "Patient.h"
#include "HealthInsurance.h"

class PaymentMethodStrategy {
public:
    static IPaymentMethod* getPaymentMethod(Patient* patient);
};

#endif // !PAYMENTMETHODSTRATEGY_H_
