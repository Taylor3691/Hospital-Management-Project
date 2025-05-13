#include "Receptionist.h"

Receptionist::Receptionist(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address,
    const std::string& education,
    double baseSalary,
    double subsidies,
    int workingDays
) : Employee(id, name, dob, gender, phone, address,
    education, baseSalary), _subsidies(subsidies),
    _workingDays(workingDays) {}

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
