#include "Person.h"

Person::Person(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address
) : Object(id, name), _dateOfBirth(dob), _gender(gender), _phone(phone), _address(address) {}

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

int Person::age() const {
    return Date::getYear() - _dateOfBirth.getYear();
}
