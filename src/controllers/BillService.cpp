#include "BillService.h"

BillService::BillService(IMedicalRecordRepository* records, IPatientRepository* patients,
    IRoomExaminationRepository* rooms) : _records(records), _patients(patients), _rooms(rooms){}

std::vector<std::unique_ptr<MedicalRecord>>BillService::getAllRecord() {
    std::vector<std::unique_ptr<MedicalRecord>> result;

    for (auto record : _records->data()) {
        result.push_back(std::unique_ptr<MedicalRecord>(
            dynamic_cast<MedicalRecord*>(record->clone())
        ));
    }

    return result;
}

std::vector<std::unique_ptr<MedicalRecord>> BillService::getAllRecordByState(const std::string& state) {
    auto store = _records->data();
    std::vector<std::unique_ptr<MedicalRecord>> result;
    for (auto record : store) {
        if (record->state()->getStateName() == state) {
            result.push_back(std::unique_ptr<MedicalRecord>(
                dynamic_cast<MedicalRecord*>(record->clone())
            ));
        }
    }
    return result;
}

std::unique_ptr<MedicalRecord> BillService::findRecordById(const std::string& id) {
    auto store = _records->data();
    auto record = from(store).where(&MedicalRecord::id, id).findOne();
    if (record == nullptr) {
        return nullptr;
    }
    auto result = dynamic_cast<MedicalRecord*>(record->clone());
    return std::unique_ptr<MedicalRecord>(result);
}

std::unique_ptr<Patient> BillService::findPatientById(const std::string& id) {
    auto store = _patients->data();
    auto patient = from(store).where(&Patient::id, id).findOne();
    if (patient == nullptr) {
        return nullptr;
    }
    auto result = dynamic_cast<Patient*>(patient->clone());
    return std::unique_ptr<Patient>(result);
}

std::vector<std::unique_ptr<MedicineUsage>>
BillService::getAllMedicineUsageInRecord(const std::string& recordId) {
    auto store = _records->data();
    std::vector<std::unique_ptr<MedicineUsage>> result;
    auto query = from(store).where(&MedicalRecord::id, recordId).findOne();
    for (auto medicine : query->prescribedMedicines()) {
        result.push_back(std::unique_ptr<MedicineUsage>(
            dynamic_cast<MedicineUsage*>(medicine->clone())
        ));
    }
    return result;
}

std::vector<std::unique_ptr<ClinicalTest>>
BillService::getAllClinicalTestInRecord(const std::string& recordId) {
    auto store = _records->data();
    std::vector<std::unique_ptr<ClinicalTest>> result;
    auto query = from(store).where(&MedicalRecord::id, recordId).findOne();
    for (auto test : query->clinicalTests()) {
        result.push_back(std::unique_ptr<ClinicalTest>(
            dynamic_cast<ClinicalTest*>(test->clone())
        ));
    }
    return result;

}

std::unique_ptr<Receipt> BillService::generateReceipt(std::unique_ptr<MedicalRecord> record) {
    double totalPrice = record->calculateFee();
    std::string id = "HD-" + Date::toString(Date::getDate()) + "-" + Time::getCurrentTime().toString();
    std::unique_ptr<Patient> patient = findPatientById(record->patientId());
    std::unique_ptr<IPaymentMethod> method(PaymentMethodStrategy::getPaymentMethod(patient.get()));
    std::unique_ptr<Receipt> receipt = std::make_unique<Receipt>(id, patient->name(), record->id(), totalPrice);
    receipt->setPaymentMethod(std::move(method));
    return std::move(receipt);
}
