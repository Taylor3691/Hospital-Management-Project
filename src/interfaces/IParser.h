#ifndef IPARSER_H
#define IPARSER_H

#include "../models/Object.h"

class IParser {
public:
    virtual ~IParser() = default;

public:
    virtual Object* parse(const std::string& str) const = 0;
};

#endif // !IPARSER_H
