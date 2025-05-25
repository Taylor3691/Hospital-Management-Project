#ifndef TXTMEDICALRECORDPARSER_H_
#define TXTMEDICALRECORDPARSER_H_

#include "MedicalRecordParser.h"
#include "TxtClinicalTestParser.h"
#include "TxtMedicineUsageParser.h"
#include "MedicalRecord.h"

class TxtMedicalRecordParser : public MedicalRecordParser {
private:
    char _delim;
public:
    TxtMedicalRecordParser(char delim = '|');
    Object* parse(const std::string& str) const override;
};

#endif // !TXTMEDICALRECORDPARSER_H_
