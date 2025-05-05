#include "Doctor.h"

Doctor::Doctor(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address,
    const Date& startWorkingAt,
    const std::string& education,
    double baseSalary,
    const std::vector<std::string>& specialty
) : Employee(id, name, dob, gender, phone, address, startWorkingAt, education, baseSalary) {
    _specialty = specialty;
}

std::vector<std::string>& Doctor::specialty() {
    return _specialty;
}
