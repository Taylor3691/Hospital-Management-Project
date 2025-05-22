#ifndef TXTMEDICINEPARSER_H
#define TXTMEDICINEPARSER_H

#include <sstream>
#include "MedicineParser.h"
#include "Medicine.h"

class TxtMedicineParser : public MedicineParser {
private:
    char _delim;

public:
    TxtMedicineParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXTMEDICINEPARSER_H
