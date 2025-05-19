#ifndef TXT_RECEPTIONIST_PARSER_H
#define TXT_RECEPTIONIST_PARSER_H

#include <sstream>
#include "ReceptionistParser.h"
#include "Receptionist.h"

class TxtReceptionistParser : public ReceptionistParser {
private:
    char _delim;

public:
    TxtReceptionistParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_RECEPTIONIST_PARSER_H
