#include "TxtClinicalTestParser.h"

TxtClinicalTestParser::TxtClinicalTestParser(char delim) : _delim(delim){}

Object* TxtClinicalTestParser::parse(const std::string& line) const {
    ClinicalTest* test = new ClinicalTest();

    std::string str = line;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') str[i] = _delim;
    }

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    test->setId(buffer);

    std::getline(stream, buffer, _delim);
    test->setName(buffer);

    std::getline(stream, buffer, _delim);
    test->setTestId(buffer);

    std::getline(stream, buffer, _delim);
    test->setCost(std::stod(buffer));

    std::getline(stream, buffer, _delim);
    test->setResult(buffer);

    std::getline(stream, buffer, _delim);
    test->setCompleted(std::stoi(buffer));

    return test;
}
