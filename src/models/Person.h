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
    Person() = default;
    Person(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address);
    virtual ~Person() = default;

public:
    Date dob() const;
    std::string gender() const;
    std::string phone() const;
    std::string address() const;

public:
    void setDob(const Date& dob);
    void setGender(const std::string& gender);
    void setPhone(const std::string& phone);
    void setAddress(const std::string& address);

public:
    int age() const;
};

#endif // !PERSON_H
