#include "TestService.h"

TestService::TestService(
    const std::string& id,
    const std::string& name,
    double cost
)
    : Object(id, name), _cost(cost) {}

TestService::TestService(const TestService& other)
    : Object(other), _cost(other._cost) {}

double TestService::cost() const {
    return _cost;
}

void TestService::setCost(double cost) {
    _cost = cost;
}

void TestService::acceptWrite(IVisitor* visitor, std::ostream& os) {
    (dynamic_cast<IWritingVisitor*>(visitor))->write(this, os);
}

Object* TestService::clone() const {
    return new TestService(*this);
}
