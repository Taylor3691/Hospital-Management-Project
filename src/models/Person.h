#ifndef PERSON_H
#define PERSON_H

#include "Object.h"
#include "../utils/Date.h"

class Person : public Object {
protected:
    Date _dateOfBirth;
    std::string _gender;
    std::string _phone;
    std::string _address;

public:
    Person(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address);
    virtual ~Person() = default;

public:
    virtual Date dob() const;
    virtual std::string gender() const;
    virtual std::string phone() const;
    virtual std::string address() const;

public:
    virtual int age() const;
};

#endif
