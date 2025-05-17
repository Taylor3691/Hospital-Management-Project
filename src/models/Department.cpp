#include "Department.h"
#include "TxtWritingVisitor.h"

Department::Department(
    const std::string& id,
    const std::string& name,
    const std::string& headId,
    const Date& date,
    const std::string& subscription
)
    : Object(id, name)
    , _headId(headId)
    , _foundationDate(date)
    , _subscription(subscription) {}

std::string Department::headId() const {
    return _headId;
}

Date Department::foundationDate() const {
    return _foundationDate;
}

std::string Department::subscription() const {
    return _subscription;
}

void Department::setHeadId(const std::string& id) {
    _headId = id;
}

void Department::setFoundationDate(const Date& date) {
    _foundationDate = date;
}

void Department::setSubscription(const std::string& subscription) {
    _subscription = subscription;
}

void Department::acceptWrite(IVisitor* visitor, std::ostream& os) {
    dynamic_cast<TxtWritingVisitor*>(visitor)->write(this, os);
}
