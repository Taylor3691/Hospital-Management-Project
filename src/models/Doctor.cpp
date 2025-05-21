#include "Doctor.h"

Doctor::Doctor(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::string& education,
    double baseSalary,
    const std::string& specialty,
    const std::string& license
)
    : Employee(id, name, gender, address,
        phone, dob, education, baseSalary)
    , _specialty(specialty)
    , _license(license) {}

Doctor::Doctor(const Doctor& other)
    : Employee(other.id(), other.name(), other.gender(), other.address(), other.phone(),
        other.dob(), other.education(), other.baseSalary()),
    _specialty(other.specialty()),
    _license(other.license()) {}

std::string Doctor::specialty() const {
    return _specialty;
}

std::string Doctor::license() const {
    return _license;
}

void Doctor::setSpecialty(const std::string& specialty) {
    _specialty = specialty;
}

void Doctor::setLicense(const std::string& license) {
    _license = license;
}

void Doctor::acceptWrite(IVisitor* visitor, std::ostream& os) {
    dynamic_cast<TxtWritingVisitor*>(visitor)->write(this, os);
}

Object* Doctor::clone() const {
    return new Doctor(*this);
}
