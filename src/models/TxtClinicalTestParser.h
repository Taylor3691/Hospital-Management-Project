#ifndef TXT_CLINICAL_TEST_PARSER_H
#define TXT_CLINICAL_TEST_PARSER_H

#include "ClinicalTestParser.h"
#include "ClinicalTest.h"
#include <sstream>

class TxtClinicalTestParser : public ClinicalTestParser {
private:
    char _delim;

public:
    TxtClinicalTestParser(char delim = '|');
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_CLINICAL_TEST_PARSER_H
