#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Employee.h"
#include "TxtWritingVisitor.h"

class Receptionist : public Employee {
private:
    double _subsidies;
    int _workingDays;

public:
    Receptionist() = default;
    Receptionist(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& address,
        const std::string& phone, const Date& dob,
        const std::string& education, double baseSalary,
        double subsidies, int workingDays);
    Receptionist(const Receptionist& other);

public:
    double subsidies() const;
    int workingDays() const;

public:
    void setSubsidies(double subsidies);
    void setWorkingDays(int workingDays);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;
};

#endif // !RECEPTIONIST_H
