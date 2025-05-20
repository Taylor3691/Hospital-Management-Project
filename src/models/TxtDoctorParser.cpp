#include "TxtDoctorParser.h"

TxtDoctorParser::TxtDoctorParser(char delim)
    : _delim(delim) {}

Object* TxtDoctorParser::parse(const std::string& str) const {
    auto doctor = new Doctor();

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    doctor->setId(buffer);

    std::getline(stream, buffer, _delim);
    doctor->setName(buffer);

    std::getline(stream, buffer, _delim);
    doctor->setGender(buffer);

    std::getline(stream, buffer, _delim);
    doctor->setAddress(buffer);

    std::getline(stream, buffer, _delim);
    doctor->setPhone(buffer);

    std::getline(stream, buffer, _delim);
    doctor->setDob(buffer);

    std::getline(stream, buffer, _delim);
    doctor->setEducation(buffer);

    std::getline(stream, buffer, _delim);
    doctor->setBaseSalary(stod(buffer));

    std::getline(stream, buffer, _delim);
    doctor->setSpecialty(buffer);

    std::getline(stream, buffer);
    doctor->setLicense(buffer);

    return doctor;
}
