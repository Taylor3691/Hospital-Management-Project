#include "TxtMedicalRecordParser.h"

TxtMedicalRecordParser::TxtMedicalRecordParser(char delim ) : _delim(delim) {}

Object* TxtMedicalRecordParser::parse(const std::string& str) const {
    MedicalRecord* record = new MedicalRecord();

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    record->setId(buffer);

    std::getline(stream, buffer, _delim);
    record->setName(buffer);

    std::getline(stream, buffer, _delim);
    record->setPatientId(buffer);

    std::getline(stream, buffer, _delim);
    record->assignToRoom(buffer);

    std::getline(stream, buffer, _delim);
    record->startExamination(buffer);

    std::getline(stream, buffer, _delim);
    int numberOfMedicineUsages = std::stoi(buffer);

    IParser* parse = new TxtMedicineUsageParser(_delim);
    while (numberOfMedicineUsages--) {
        std::getline(stream, buffer, _delim);
        MedicineUsage* unit = dynamic_cast<MedicineUsage*>(parse->parse(buffer));
        record->prescribeMedicine(unit);
    }
    delete parse;

    std::getline(stream, buffer, _delim);
    int numberOfClinicalTests = std::stoi(buffer);

    parse = new TxtClinicalTestParser(_delim);
    while (numberOfClinicalTests--) {
        std::getline(stream, buffer, _delim);
        ClinicalTest* unit = dynamic_cast<ClinicalTest*>(parse->parse(buffer));
        record->orderClinicalTest(unit);
    }
    delete parse;

    std::getline(stream, buffer, _delim);
    record->setDiagnosisResult(buffer);

    return record;
}
