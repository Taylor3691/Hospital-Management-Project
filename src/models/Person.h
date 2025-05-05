#ifndef PERSON_H
#define PERSON_H

#include "../interfaces/IPerson.h"

class Person : public IPerson {
private:
    std::string _id;
    std::string _fullname;
    Date _dateOfBirth;
    std::string _gender;
    std::string _phone;
    std::string _homeAdress;

public:
    Person(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address);

public:
    std::string id() const override;
    std::string name() const override;
    Date dateOfBirth() const override;
    int age() const override;
    std::string gender() const override;
    std::string phone() const override;
    std::string address() const override;
};

#endif
