#ifndef MEDICAL_RECORD_PARSER_H
#define MEDICAL_RECORD_PARSER_H

#include "../interfaces/IParser.h"

class MedicalRecordParser : public IParser {
public:
    virtual ~MedicalRecordParser() = default;
};

#endif // !MEDICAL_RECORD_PARSER_H
