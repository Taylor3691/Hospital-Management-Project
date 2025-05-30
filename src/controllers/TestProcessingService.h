#ifndef TEST_PROCESSING_SERVICE_H
#define TEST_PROCESSING_SERVICE_H

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
    std::vector<std::unique_ptr<ClinicalTest>> getClinicalTestByState(
        bool completed = false);
    std::unique_ptr<MedicalRecord> findRecordById(const std::string& id);
    std::unique_ptr<ClinicalTest> findTestUsageById(const std::string& id);
    void updateRecord(std::unique_ptr<MedicalRecord> record);

};

#endif // !TEST_PROCESSING_SERVICE_H
