#ifndef BILLSERVICE_H_
#define BILLSERVICE_H_

#include "../ServiceLocator.h"
#include "../models/Receipt.h"
#include "../models/PaymentMethodStrategy.h"

class BillService {
private:
    IMedicalRecordRepository* _records;
    IPatientRepository* _patients;
    IRoomExaminationRepository* _rooms;

public:
    BillService(IMedicalRecordRepository* records, IPatientRepository* patients,
        IRoomExaminationRepository* rooms);

public:
    std::vector<std::unique_ptr<MedicalRecord>> getAllRecord();
    std::vector<std::unique_ptr<MedicalRecord>> getAllRecordByState(const std::string& state);
    std::unique_ptr<MedicalRecord> findRecordById(const std::string& id);
    std::unique_ptr<Patient> findPatientById(const std::string& id);
    std::vector<std::unique_ptr<MedicineUsage>> getAllMedicineUsageInRecord(const std::string& recordId);
    std::vector<std::unique_ptr<ClinicalTest>> getAllClinicalTestInRecord(const std::string& recordId);
    std::unique_ptr<Receipt> generateReceipt(std::unique_ptr<MedicalRecord> record);
};

#endif // !BILLSERVICE_H_
