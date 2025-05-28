#include "TestProcessingService.h"

TestProcessingService::TestProcessingService(IMedicalRecordRepository* record) : _records(record){}

std::vector<std::unique_ptr<ClinicalTest>> TestProcessingService::getAllClinicalTest() {
    std::vector<std::unique_ptr<ClinicalTest>> result;

    for (auto record : _records->data()) {
        for (auto test : record->clinicalTests()) {
            result.push_back(std::unique_ptr<ClinicalTest>(
                dynamic_cast<ClinicalTest*>(test->clone())
            ));
        }
    }

    return result;
}

std::vector<std::unique_ptr<ClinicalTest>> TestProcessingService::getClinicalTestByState(bool completed) {
    std::vector<std::unique_ptr<ClinicalTest>> result;

    for (auto record : _records->data()) {
        std::vector<const ClinicalTest*> store = record->clinicalTests();
        auto query = from(store).where(&ClinicalTest::completed, completed).find();
        for (auto unit : query) {
            result.push_back(std::unique_ptr<ClinicalTest>(
                dynamic_cast<ClinicalTest*>(unit->clone())
            ));
        }
    }

    return result;
}

std::unique_ptr<MedicalRecord> TestProcessingService::getRecordById(const std::string& id){
    std::vector<const MedicalRecord*> store = _records->data();
    auto query = from(store).where(&MedicalRecord::id, id).findOne();
    if (query) {
        return std::unique_ptr<MedicalRecord>(dynamic_cast<MedicalRecord*>(query->clone()));
    }
    throw std::runtime_error("Not Found Medical Record ");
    return nullptr;
}

std::unique_ptr<ClinicalTest> TestProcessingService::getTestById(const std::string& id) {
    std::vector<const MedicalRecord*> store = _records->data();
    for (auto record : store) {
        std::vector<const ClinicalTest*> tests = record->clinicalTests();
        auto query = from(tests).where(&ClinicalTest::id, id).findOne();
        if (query) {
            return std::unique_ptr<ClinicalTest>(dynamic_cast<ClinicalTest*>(query->clone()));
        }
    }
    throw std::runtime_error("Not Found Clinical Test");
    return nullptr;
}

void TestProcessingService::setTestResult(std::unique_ptr<MedicalRecord> record, std::unique_ptr<ClinicalTest> test) {
    record.get()->orderClinicalTest(std::move(test));
}

void TestProcessingService::updateRecord(std::unique_ptr<MedicalRecord> record) {
    _records->update(*record.get());
}
