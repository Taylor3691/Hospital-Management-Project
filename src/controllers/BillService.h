#ifndef BILL_SERVICE_H
#define BILL_SERVICE_H

#include "../interfaces/IMedicalRecordRepository.h"
#include "../interfaces/IPatientRepository.h"
#include "../interfaces/IRoomExaminationRepository.h"
#include "../models/Receipt.h"
#include "../models/PaymentMethodStrategy.h"

class BillService {
private:
    IMedicalRecordRepository* _records;
    IPatientRepository* _patients;
    IRoomExaminationRepository* _rooms;

public:
    BillService(IMedicalRecordRepository* records,
        IPatientRepository* patients, IRoomExaminationRepository* rooms);

public:
    std::vector<std::unique_ptr<MedicalRecord>> getAllRecords();
    std::vector<std::unique_ptr<MedicalRecord>> getAllRecordsByState(
        ExaminationState::State state = ExaminationState::Completed);
    std::unique_ptr<Patient> findPatientById(const std::string& id);
    std::vector<std::unique_ptr<MedicineUsage>> getAllMedicineUsagesInRecord(
        const std::string& recordId);
    std::vector<std::unique_ptr<ClinicalTest>> getAllClinicalTestsInRecord(
        const std::string& recordId);
    std::unique_ptr<Receipt> generateReceipt(std::unique_ptr<MedicalRecord> record);
};

#endif // !BILL_SERVICE_H
