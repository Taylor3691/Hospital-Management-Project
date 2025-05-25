#ifndef TXTTESTSERVICEPARSER_H_
#define TXTTESTSERVICEPARSER_H_

#include "TestServiceParser.h"
#include <sstream>

class TxtTestServiceParser : public TestServiceParser {
private:
    char _delim;

public:
    TxtTestServiceParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXTTESTSERVICEPARSER_H_
