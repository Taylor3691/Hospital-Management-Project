#ifndef TESTSERVICEPARSER_H_
#define TESTSERVICEPARSER_H_

#include "../interfaces/IParser.h"
#include "TestService.h"

class TestServiceParser : public IParser {
public:
    ~TestServiceParser() override = default;
};

#endif // !TESTSERVICEPARSER_H_
