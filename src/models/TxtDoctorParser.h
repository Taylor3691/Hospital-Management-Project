#ifndef TXT_DOCTOR_PARSER_H
#define TXT_DOCTOR_PARSER_H

#include <sstream>
#include "DoctorParser.h"
#include "Doctor.h"

class TxtDoctorParser : public DoctorParser {
private:
    char _delim;

public:
    TxtDoctorParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_DOCTOR_PARSER_H
