#ifndef TXTMEDICINEPARSER_H_
#define TXTMEDICINEPARSER_H_

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
