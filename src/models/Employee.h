#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    std::string _education;
    double _baseSalary;

public:
    Employee() = default;
    Employee(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& address,
        const std::string& phone, const Date& dob,
        const std::string& education, double baseSalary);
    Employee(const Employee& other);
    virtual ~Employee() = default;

public:
    std::string education() const;
    double baseSalary() const;

public:
    void setEducation(const std::string& education);
    void setBaseSalary(double salary);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) = 0;
    Object* clone() const = 0;

};

#endif // !EMPLOYEE_H
