#include "Receipt.h"

Receipt::Receipt()
    : _totalPrice() {}

Receipt::Receipt(
    const std::string& id,
    const std::string& recordId,
    double totalPrice
)
    : Object(id, "")
    , _recordId(recordId)
    , _totalPrice(totalPrice) {}

void Receipt::setPaymentMethod(std::unique_ptr<IPaymentMethod> method) {
    _paymentMethod = std::move(method);
}

void Receipt::setStatus(const std::string& status) {
    _status = status;
}

double Receipt::processPayment() const {
    if (!_paymentMethod) {
        throw std::runtime_error("No payment method has been set yet");
    }
    return _paymentMethod->processPayment(_totalPrice);
}
