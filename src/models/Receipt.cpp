#include "Receipt.h"

Receipt::Receipt()
    : _totalPrice() {}

Receipt::Receipt(
    const std::string& id,
    const std::string& name,
    const std::string& recordId,
    double totalPrice
)
    : Object(id, name)
    , _recordId(recordId)
    , _totalPrice(totalPrice)
    ,_status(false)
    ,_createdDate(Date::toString((Date::getDate()))){}

Receipt::Receipt(const Receipt& other)
    : Object(other._id, other._name),
    _recordId(other._recordId),
    _totalPrice(other._totalPrice),
    _status(other._status),
    _createdDate(other._createdDate){}

void Receipt::setPaymentMethod(std::unique_ptr<IPaymentMethod> method) {
    _paymentMethod = std::move(method);
}

void Receipt::setStatus(const std::string& status) {
    _status = status;
}

double Receipt::totalPrice() const {
    return _totalPrice;
}

std::string Receipt::recordId() const {
    return _recordId;
}

double Receipt::processPayment() const {
    if (!_paymentMethod) {
        throw std::runtime_error("No payment method has been set yet");
    }
    return _paymentMethod->processPayment(_totalPrice);
}

void Receipt::acceptWrite(IVisitor* visitor, std::ostream& os) {

}

Object* Receipt::clone() const {
    return new Receipt(*this);
}
