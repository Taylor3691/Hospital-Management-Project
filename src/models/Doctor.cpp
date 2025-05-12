#include "Doctor.h"

Doctor::Doctor(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address,
    const std::string& education,
    double baseSalary,
    const std::string& specialty,
    const std::string& license
) : Employee(id, name, dob, gender, phone,
    address, education, baseSalary),
    _specialty(specialty), _license(license) {
}

std::string Doctor::specialty() const {
    return _specialty;
}

std::string Doctor::license() const {
    return _license;
}

void Doctor::specialty(const std::string& specialty) {
    _specialty = specialty;
}

void Doctor::license(const std::string& license) {
    _license = license;
}
