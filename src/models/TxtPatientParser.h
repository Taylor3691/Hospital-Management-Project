#ifndef TXT_PATIENT_PARSER_H
#define TXT_PATIENT_PARSER_H

#include <sstream>
#include "PatientParser.h"
#include "Patient.h"

class TxtPatientParser : public PatientParser {
protected:
   char _delim;
public:
   TxtPatientParser(char delim = '|');
   Object* parse(const std::string& str) const override;
};

#endif // !TXT_PATIENT_PARSER_H
