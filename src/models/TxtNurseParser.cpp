#include "TxtNurseParser.h"

TxtNurseParser::TxtNurseParser(char delim)
    : _delim(delim) {}

Object* TxtNurseParser::parse(const std::string& str) const {
    auto nurse = new Nurse();

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    nurse->setId(buffer);

    std::getline(stream, buffer, _delim);
    nurse->setName(buffer);

    std::getline(stream, buffer, _delim);
    nurse->setGender(buffer);

    std::getline(stream, buffer, _delim);
    nurse->setAddress(buffer);

    std::getline(stream, buffer, _delim);
    nurse->setPhone(buffer);

    std::getline(stream, buffer, _delim);
    nurse->setDob(buffer);

    std::getline(stream, buffer, _delim);
    nurse->setEducation(buffer);

    std::getline(stream, buffer, _delim);
    nurse->setBaseSalary(stod(buffer));

    std::getline(stream, buffer);
    nurse->setDuty(buffer);

    return nurse;
}
