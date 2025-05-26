#ifndef TXT_MEDICINE_USAGE_PARSER_H
#define TXT_MEDICINE_USAGE_PARSER_H

#include <sstream>
#include "MedicineUsageParser.h"
#include "MedicineUsage.h"

class TxtMedicineUsageParser : public MedicineUsageParser {
private:
    char _delim;

public:
    TxtMedicineUsageParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_MEDICINE_USAGE_PARSER_H
