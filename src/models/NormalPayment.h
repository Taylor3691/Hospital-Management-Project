#ifndef NORMAL_PAYMENT_H
#define NORMAL_PAYMENT_H

#include "../interfaces/IPaymentMethod.h"

class NormalPayment : public IPaymentMethod {
public:
    double processPayment(double amount) const override;
};

#endif // !NORMAL_PAYMENT_H
