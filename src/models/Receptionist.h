#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Employee.h"

class Receptionist : public Employee {
private:
    double _subsidies;
    int _workingDays;

public:
    Receptionist() = default;
    Receptionist(const std::string& id, const std::string& name,
        const Date& dob, const std::string& gender, const std::string& phone,
        const std::string& address, const std::string& education,
        double baseSalary, double subsidies, int workingDays);

public:
    double subsidies() const;
    int workingDays() const;

public:
    void setSubsidies(double subsidies);
    void setWorkingDays(int workingDays);
};

#endif // !RECEPTIONIST_H
