#ifndef RECEIPT_H
#define RECEIPT_H

#include <memory>
#include "Object.h"
#include "../interfaces/IPaymentMethod.h"
#include "../utils/Date.h"

class Receipt : public Object {
private:
    std::string _recordId;
    Date _createdDate;
    double _totalPrice;
    std::unique_ptr<IPaymentMethod> _paymentMethod;
    std::string _status;

public:
    Receipt();
    Receipt(const std::string& id,
        const std::string& recordId, double totalPrice);

public:
    void setPaymentMethod(std::unique_ptr<IPaymentMethod> method);
    void setStatus(const std::string& status);
    double processPayment() const;
};

#endif // !RECEIPT_H
