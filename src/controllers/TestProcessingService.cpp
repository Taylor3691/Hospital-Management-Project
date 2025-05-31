#include "TestProcessingService.h"
#include "../ServiceLocator.h"

TestProcessingService::TestProcessingService(IMedicalRecordRepository* record)
    : _records(record){}

std::vector<std::unique_ptr<MedicalRecord>> TestProcessingService::getMedicalRecordsHaveTests() {
    auto records = _records->data();
    Getter<MedicalRecord> getter = [](const MedicalRecord& record) {
        return record.clinicalTests().size() > 0;
    };
    auto results = from(records).where(getter, true).find();
    std::vector<std::unique_ptr<MedicalRecord>> copies;
    for (const auto& record : results) {
        copies.push_back(std::unique_ptr<MedicalRecord>(
            static_cast<MedicalRecord*>(record->clone())
        ));
    }

    return copies;
}

std::vector<std::unique_ptr<MedicalRecord>> TestProcessingService::getMedicalRecordsByTestState(
    bool completed
) {
    auto records = getMedicalRecordsHaveTests();
    Getter<MedicalRecord> getter = [](const MedicalRecord& record) {
        return record.state()->stateName() != ExaminationState::TestPending;
    };
    auto results = from(records).where(getter, completed).find();
    std::vector<std::unique_ptr<MedicalRecord>> copies;
    for (const auto& record : results) {
        copies.push_back(std::unique_ptr<MedicalRecord>(
            static_cast<MedicalRecord*>(record->clone())
        ));
    }

    return copies;
}

std::vector<std::unique_ptr<ClinicalTest>> TestProcessingService::getClinicalTestsByState(
    const std::string& recordId,
    bool completed
) {
    std::vector<std::unique_ptr<ClinicalTest>> copies;

    auto record = ServiceLocator::instance()
        ->examinationService()->findRecordById(recordId);
    std::vector<const ClinicalTest*> tests = record->clinicalTests();
    auto results = from(tests).where(&ClinicalTest::completed, completed).find();
    for (const auto& unit : results) {
        copies.push_back(std::unique_ptr<ClinicalTest>(
            static_cast<ClinicalTest*>(unit->clone())
        ));
    }

    return copies;
}

std::unique_ptr<ClinicalTest> TestProcessingService::findClinicalTestById(const std::string& id) {
    std::vector<const MedicalRecord*> records = _records->data();
    for (const auto& record : records) {
        std::vector<const ClinicalTest*> tests = record->clinicalTests();
        auto query = from(tests).where(&ClinicalTest::id, id).findOne();
        if (query) {
            return std::unique_ptr<ClinicalTest>(static_cast<ClinicalTest*>(query->clone()));
        }
    }
    throw std::runtime_error("Not Found Clinical Test");
}
