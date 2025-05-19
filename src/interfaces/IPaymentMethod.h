#ifndef IPAYMENT_METHOD_H
#define IPAYMENT_METHOD_H

class IPaymentMethod {
public:
    virtual ~IPaymentMethod() = default;

public:
    virtual double processPayment(double amount) const = 0;
};

#endif // !IPAYMENT_METHOD_H
