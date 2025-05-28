#ifndef TESTPROCESSINGSERVICE_H
#define TESTPROCESSINGSERVICE_H

#include "../utils/utils.h"
#include "../utils/Date.h"
#include "../utils/Time.h"
#include "../utils/QueryBuilder.h"
#include "../models/TxtMedicalRecordRepository.h"
#include "../models/TxtTestServiceRepository.h"

class TestProcessingService {
private:
    IMedicalRecordRepository* _records;

public:
    TestProcessingService(IMedicalRecordRepository* records);

public:
    std::vector<std::unique_ptr<ClinicalTest>> getAllClinicalTest();
    std::vector<std::unique_ptr<ClinicalTest>> getClinicalTestByState(bool completed = false);
    std::unique_ptr<MedicalRecord> getRecordById(const std::string& id);
    std::unique_ptr<ClinicalTest> getTestById(const std::string& id);
    void setTestResult(std::unique_ptr<MedicalRecord> record, std::unique_ptr<ClinicalTest> test);
    void updateRecord(std::unique_ptr<MedicalRecord> record);

};

#endif // !TESTPROCESSINGSERVICE_H
