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
    std::vector<std::unique_ptr<MedicalRecord>> getMedicalRecordsHaveTests();
    std::vector<std::unique_ptr<MedicalRecord>> getMedicalRecordsByTestState(
        bool completed = false);
    std::vector<std::unique_ptr<ClinicalTest>> getClinicalTestsByState(
        const std::string& recordId, bool completed = false);
    std::unique_ptr<ClinicalTest> findClinicalTestById(const std::string& id);
};

#endif // !TEST_PROCESSING_SERVICE_H
