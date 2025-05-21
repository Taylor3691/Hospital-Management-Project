#include "Person.h"

Person::Person(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob
)
    : Object(id, name)
    , _gender(gender)
    , _address(address)
    , _phone(phone)
    , _dateOfBirth(dob) {}

std::string Person::gender() const {
    return _gender;
}

std::string Person::address() const {
    return _address;
}

std::string Person::phone() const {
    return _phone;
}

Date Person::dob() const {
    return _dateOfBirth;
}

void Person::setGender(const std::string& gender) {
    _gender = gender;
}

void Person::setAddress(const std::string& address) {
    _address = address;
}

void Person::setPhone(const std::string& phone) {
    _phone = phone;
}

void Person::setDob(const Date& dob) {
    _dateOfBirth = dob;
}

int Person::age() const {
    return Date::getYear() - _dateOfBirth.getYear();
}
