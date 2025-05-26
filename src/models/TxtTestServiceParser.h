#ifndef TXT_TEST_SERVICE_PARSER_H
#define TXT_TEST_SERVICE_PARSER_H

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

#endif // !TXT_TEST_SERVICE_PARSER_H
