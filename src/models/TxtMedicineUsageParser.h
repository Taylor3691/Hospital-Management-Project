#ifndef TXTMEDICINEUSAGEPARSER_H_
#define TXTMEDICINEUSAGEPARSER_H_

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



#endif // !TXTMEDICINEUSAGEPARSER_H_
