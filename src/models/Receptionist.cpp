#include "Receptionist.h"

Receptionist::Receptionist(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::string& education,
    double baseSalary,
    double subsidies,
    int workingDays
)
    : Employee(id, name, gender, address,
        phone, dob, education, baseSalary)
    , _subsidies(subsidies)
    , _workingDays(workingDays) {}

Receptionist::Receptionist(const Receptionist& other):
    Employee(other.id(), other.name(), other.gender(), other.address(), other.phone(),
        other.dob(), other.education(), other.baseSalary()),
    _subsidies(other.subsidies()),
    _workingDays(other.workingDays()) {}

double Receptionist::subsidies() const {
    return _subsidies;
}

int Receptionist::workingDays() const {
    return _workingDays;
}

void Receptionist::setSubsidies(double subsidies) {
    _subsidies = subsidies;
}

void Receptionist::setWorkingDays(int workingDays) {
    _workingDays = workingDays;
}

void Receptionist::acceptWrite(IVisitor* visitor, std::ostream& os) {
    dynamic_cast<TxtWritingVisitor*>(visitor)->write(this, os);
}

Object* Receptionist::clone() const {
    return new Receptionist(*this);
}
