#ifndef IPARSER_FACTORY_H
#define IPARSER_FACTORY_H

#include "IParser.h"

class IParserFactory {
public:
    virtual ~IParserFactory() = default;

public:
    virtual IParser* getParser(const std::string& type) const = 0;
};

#endif // !IPARSER_FACTORY_H
