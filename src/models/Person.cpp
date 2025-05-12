#include "Person.h"

Person::Person(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address
) : Object(id, name), _dateOfBirth(dob), _gender(gender),
_phone(phone), _address(address) {}

Date Person::dob() const {
    return _dateOfBirth;
}

std::string Person::gender() const {
    return _gender;
}

std::string Person::phone() const {
    return _phone;
}

std::string Person::address() const {
    return _address;
}

void Person::setDob(const Date& dob) {
    _dateOfBirth = dob;
}

void Person::setGender(const std::string& gender) {
    _gender = gender;
}

void Person::setPhone(const std::string& phone) {
    _phone = phone;
}

void Person::setAddress(const std::string& address) {
    _address = address;
}

int Person::age() const {
    return Date::getYear() - _dateOfBirth.getYear();
}
