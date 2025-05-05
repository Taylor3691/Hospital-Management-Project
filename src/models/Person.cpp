#include "Person.h"

Person::Person(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address
) {
    _id = id;
    _fullname = name;
    _dateOfBirth = dob;
    _gender = gender;
    _phone = phone;
    _homeAdress = address;
}

std::string Person::id() const {
    return _id;
}

std::string Person::name() const {
    return _fullname;
}

Date Person::dateOfBirth() const {
    return _dateOfBirth;
}

int Person::age() const {
    return Date::getYear() - _dateOfBirth.getYear();
}

std::string Person::gender() const {
    return _gender;
}

std::string Person::phone() const {
    return _phone;
}

std::string Person::address() const {
    return _homeAdress;
}
