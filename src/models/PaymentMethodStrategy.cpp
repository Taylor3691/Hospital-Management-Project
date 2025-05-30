#include "PaymentMethodStrategy.h"

IPaymentMethod* PaymentMethodStrategy::getPaymentMethod(Patient * patient) {
    if (!patient->insuranceCard()) {
        return new NormalPayment();
    }
    else if (patient->insuranceCard()->checkValid()) {
        return new InsuranceMethod(patient->insuranceCard()->coveragePercent());
    }
    return new NormalPayment();
}
