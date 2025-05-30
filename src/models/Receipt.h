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
    Receipt(const std::string& id, const std::string& name,
        const std::string& recordId, double totalPrice);
    Receipt(const Receipt& other);
public:
    void setPaymentMethod(std::unique_ptr<IPaymentMethod> method);
    void setStatus(const std::string& status);
    double totalPrice() const;
    std::string recordId() const;

public:
    double processPayment() const;
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;
};

#endif // !RECEIPT_H
