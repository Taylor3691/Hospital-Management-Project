#ifndef TXT_MEDICAL_RECORD_PARSER_H
#define TXT_MEDICAL_RECORD_PARSER_H

#include "MedicalRecordParser.h"
#include "TxtClinicalTestParser.h"
#include "TxtMedicineUsageParser.h"
#include "MedicalRecord.h"
#include "RegisteredState.h"
#include "ExaminingState.h"
#include "CompletedState.h"
#include "WaitingState.h"
#include "PendingTestState.h"
#include <sstream>

class TxtMedicalRecordParser : public MedicalRecordParser {
private:
    char _delim;
public:
    TxtMedicalRecordParser(char delim = '|');
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_MEDICAL_RECORD_PARSER_H
