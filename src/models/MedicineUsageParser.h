#ifndef MEDICINE_USAGE_PARSER_H
#define MEDICINE_USAGE_PARSER_H

#include "../interfaces/IParser.h"

class MedicineUsageParser : public IParser {
public:
    virtual ~MedicineUsageParser() = default;
};

#endif // !MEDICINE_USAGE_PARSER_H
