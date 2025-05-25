#ifndef TXTCLINICALTESTPARSER_H_
#define TXTCLINICALTESTPARSER_H_

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


#endif // !TXTCLINICALTESTPARSER_H_
