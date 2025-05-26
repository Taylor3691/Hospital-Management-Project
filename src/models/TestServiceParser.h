#ifndef TEST_SERVICE_PARSER_H
#define TEST_SERVICE_PARSER_H

#include "../interfaces/IParser.h"
#include "TestService.h"

class TestServiceParser : public IParser {
public:
    ~TestServiceParser() override = default;
};

#endif // !TEST_SERVICE_PARSER_H
