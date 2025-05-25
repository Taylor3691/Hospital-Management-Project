#include "TxtMedicalRecordParser.h"

TxtMedicalRecordParser::TxtMedicalRecordParser(char delim ) : _delim(delim) {}

Object* TxtMedicalRecordParser::parse(const std::string& str) const {
    MedicalRecord* record = new MedicalRecord();
    return record;
}
