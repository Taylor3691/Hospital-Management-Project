#include "TxtReceptionistParser.h"

TxtReceptionistParser::TxtReceptionistParser(char delim)
    : _delim(delim) {}

Object* TxtReceptionistParser::parse(const std::string& str) const {
    auto receptionist = new Receptionist();

    std::istringstream stream;
    std::string buffer;

    std::getline(stream, buffer, _delim);
    receptionist->setId(buffer);

    std::getline(stream, buffer, _delim);
    receptionist->setName(buffer);

    std::getline(stream, buffer, _delim);
    receptionist->setGender(buffer);

    std::getline(stream, buffer, _delim);
    receptionist->setAddress(buffer);

    std::getline(stream, buffer, _delim);
    receptionist->setPhone(buffer);

    std::getline(stream, buffer, _delim);
    receptionist->setDob(buffer);

    std::getline(stream, buffer, _delim);
    receptionist->setEducation(buffer);

    std::getline(stream, buffer, _delim);
    receptionist->setBaseSalary(stod(buffer));

    std::getline(stream, buffer, _delim);
    receptionist->setSubsidies(stod(buffer));

    std::getline(stream, buffer);
    receptionist->setWorkingDays(stoi(buffer));

    return receptionist;
}
