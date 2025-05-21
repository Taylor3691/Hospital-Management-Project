#ifndef DOCTOR_H
#define DOCTOR_H

#include "Employee.h"
#include "TxtWritingVisitor.h"

class Doctor : public Employee {
private:
    std::string _specialty;
    std::string _license;

public:
    Doctor() = default;
    Doctor(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& address,
        const std::string& phone, const Date& dob,
        const std::string& education, double baseSalary,
        const std::string& specialty, const std::string& license);

public:
    std::string specialty() const;
    std::string license() const;

public:
    void setSpecialty(const std::string& specialty);
    void setLicense(const std::string& license);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
};

#endif // !DOCTOR_H
