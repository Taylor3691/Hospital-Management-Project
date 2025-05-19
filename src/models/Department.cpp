#include "Department.h"

Department::Department(
    const std::string& id,
    const std::string& name,
    const std::string& headId,
    const Date& date,
    const std::string& description
)
    : Object(id, name)
    , _headId(headId)
    , _foundationDate(date)
    , _description(description) {}

std::string Department::headId() const {
    return _headId;
}

Date Department::foundationDate() const {
    return _foundationDate;
}

std::string Department::description() const {
    return _description;
}

void Department::setHeadId(const std::string& id) {
    _headId = id;
}

void Department::setFoundationDate(const Date& date) {
    _foundationDate = date;
}

void Department::setDescription(const std::string& description) {
    _description = description;
}

void Department::acceptWrite(IVisitor* visitor, std::ostream& os) {
    dynamic_cast<TxtWritingVisitor*>(visitor)->write(this, os);
}
