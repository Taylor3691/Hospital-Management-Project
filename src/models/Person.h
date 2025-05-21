#ifndef PERSON_H
#define PERSON_H

#include "Object.h"
#include "../utils/Date.h"

class Person : public Object {
protected:
    std::string _gender;
    std::string _address;
    std::string _phone;
    Date _dateOfBirth;

public:
    Person() = default;
    Person(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& address,
        const std::string& phone, const Date& dob);
    Person(const Person&);
    virtual ~Person() = default;

public:
    std::string gender() const;
    std::string address() const;
    std::string phone() const;
    Date dob() const;

public:
    void setGender(const std::string& gender);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);
    void setDob(const Date& dob);

public:
    int age() const;
};

#endif // !PERSON_H
