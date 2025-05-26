#ifndef PATIENT_PARSER_H
#define PATIENT_PARSER_H

#include "../interfaces/IParser.h"

class PatientParser : public IParser {
public:
    virtual ~PatientParser() = default;
};

#endif // !PATIENT_PARSER_H
