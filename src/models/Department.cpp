#include "Department.h"

Department::Department(const std::string& id, const std::string& name, const std::string& headId,
                       const std::tm& foundedDay, const std::string& subscription) {
    _id = id;
    _name = name;
    _headId = headId;
    _foundedDay = foundedDay;
    _subscription = subscription;
}

std::string Department::name() const {
    return _name;
}

std::string Department::id() const {
    return _id;
}

// Getter
std::string Department::getHeadId() const {
    return _headId;
}

std::tm Department::getFoundedDay() const {
    return _foundedDay;
}

std::string Department::getSubscription() const {
    return _subscription;
}

// Setter
void Department::setHeadId(const std::string& headId) {
    _headId = headId;
}

void Department::setFoundedDay(const std::tm& foundedDay) {
    _foundedDay = foundedDay;
}

void Department::setSubscription(const std::string& subscription) {
    _subscription = subscription;
}