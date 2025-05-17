#include "TxtDepartmentParser.h"

TxtDepartmentParser::TxtDepartmentParser(char delim)
    : _delim(delim) {}

Object* TxtDepartmentParser::parse(const std::string& str) const {
    auto department = new Department();

    std::istringstream stream;
    std::string buffer;

    std::getline(stream, buffer, _delim);
    department->setId(buffer);

    std::getline(stream, buffer, _delim);
    department->setName(buffer);

    std::getline(stream, buffer, _delim);
    department->setHeadId(buffer);

    std::getline(stream, buffer, _delim);
    department->setFoundationDate(buffer);

    std::getline(stream, buffer);
    department->setSubscription(buffer);

    return department;
}
