#include "BillService.h"
#include "../ServiceLocator.h"

BillService::BillService(
    IMedicalRecordRepository* records,
    IPatientRepository* patients,
    IRoomExaminationRepository* rooms
)
    : _records(records), _patients(patients), _rooms(rooms) {}

std::vector<std::unique_ptr<MedicalRecord>>BillService::getAllRecords() {
    std::vector<std::unique_ptr<MedicalRecord>> results;

    for (auto record : _records->data()) {
        results.push_back(std::unique_ptr<MedicalRecord>(
            static_cast<MedicalRecord*>(record->clone())
        ));
    }

    return results;
}

std::vector<std::unique_ptr<MedicalRecord>> BillService::getAllRecordsByState(
    ExaminationState::State state
) {
    auto records = _records->data();
    std::vector<std::unique_ptr<MedicalRecord>> results;
    for (auto record : records) {
        if (record->state()->stateName() == state) {
            results.push_back(std::unique_ptr<MedicalRecord>(
                static_cast<MedicalRecord*>(record->clone())
            ));
        }
    }
    return results;
}

std::unique_ptr<Patient> BillService::findPatientById(const std::string& id) {
    auto patients = _patients->data();
    auto patient = from(patients).where(&Patient::id, id).findOne();
    if (patient == nullptr) {
        return nullptr;
    }
    auto results = static_cast<Patient*>(patient->clone());
    return std::unique_ptr<Patient>(results);
}

std::vector<std::unique_ptr<MedicineUsage>>
BillService::getAllMedicineUsagesInRecord(const std::string& recordId) {
    auto records = _records->data();
    std::vector<std::unique_ptr<MedicineUsage>> results;
    auto record = from(records).where(&MedicalRecord::id, recordId).findOne();
    for (auto usage : record->prescribedMedicines()) {
        results.push_back(std::unique_ptr<MedicineUsage>(
            static_cast<MedicineUsage*>(usage->clone())
        ));
    }
    return results;
}

std::vector<std::unique_ptr<ClinicalTest>>
BillService::getAllClinicalTestsInRecord(const std::string& recordId) {
    auto records = _records->data();
    std::vector<std::unique_ptr<ClinicalTest>> results;
    auto record = from(records).where(&MedicalRecord::id, recordId).findOne();
    for (auto test : record->clinicalTests()) {
        results.push_back(std::unique_ptr<ClinicalTest>(
            static_cast<ClinicalTest*>(test->clone())
        ));
    }
    return results;
}

std::unique_ptr<Receipt> BillService::generateReceipt(
    std::unique_ptr<MedicalRecord> record
) {
    double totalPrice = record->calculateFee();
    std::string id = "HD-" + Date::toString(Date::getDate())
        + "-" + Time::getCurrentTime().toString();
    auto patient = findPatientById(record->patientId());
    std::unique_ptr<IPaymentMethod> method(
        PaymentMethodStrategy::getPaymentMethod(patient.get()));
    auto receipt = std::make_unique<Receipt>(
        id, patient->name(), record->id(), totalPrice);
    receipt->setPaymentMethod(std::move(method));
    return std::move(receipt);
}
