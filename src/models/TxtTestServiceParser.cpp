#include "TxtTestServiceParser.h"

TxtTestServiceParser::TxtTestServiceParser(char delim)
    : _delim(delim) {}

Object* TxtTestServiceParser::parse(const std::string& str) const {
    auto testService = new TestService();

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    testService->setId(buffer);

    std::getline(stream, buffer, _delim);
    testService->setName(buffer);

    std::getline(stream, buffer, _delim);
    testService->setCost(std::stod(buffer));

    return testService;
}
