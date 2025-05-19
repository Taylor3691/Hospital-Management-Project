#ifndef TXT_NURSE_PARSER_H
#define TXT_NURSE_PARSER_H

#include <sstream>
#include "NurseParser.h"
#include "Nurse.h"

class TxtNurseParser : public NurseParser {
private:
    char _delim;

public:
    TxtNurseParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_NURSE_PARSER_H
