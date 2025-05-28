#ifndef EXAMINATIONSERVICE_H
#define EXAMINATIONSERVICE_H

#include "../utils/QueryBuilder.h"
#include "../models/TxtMedicalRecordRepository.h"
#include "../models/TxtEmployeeRepository.h"
#include "../models/TxtRoomExaminationRepository.h"
#include "../models/TxtTestServiceRepository.h"
#include "../models/TxtMedicineRepository.h"
#include "../models/TxtPatientRepository.h"
#include "../utils/utils.h"
#include "../utils/Date.h"
#include "../utils/Time.h"


class ExaminationService {
private:
    IMedicineRepository* _medicines;
    IMedicalRecordRepository* _records;
    IRoomExaminationRepository* _rooms;
    ITestServiceRepository* _tests;
    IEmployeeRepository* _employees;
    IPatientRepository* _patients;

public:
    ExaminationService(IMedicalRecordRepository* records, IMedicineRepository* medicines, IRoomExaminationRepository* rooms
    , TxtTestServiceRepository* tests, IEmployeeRepository* employees, IPatientRepository* patients);

public:
    std::vector<std::unique_ptr<MedicalRecord>> getAllRecord();
    std::vector<std::unique_ptr<Doctor>> getAllDoctor();
    std::vector<std::unique_ptr<Medicine>> getAllMedicine();
    std::vector<std::unique_ptr<TestService>> getAllTestService();
    std::vector<std::unique_ptr<RoomExamination>> getAllRoom();
    std::vector<std::unique_ptr<MedicalRecord>> getAllRecordByState(const std::string& state);
    std::unique_ptr<MedicineUsage> createMedicneUsage(const std::string& medicineId, const std::string& name,
        int quantity, double price, const std::string& description);
    std::unique_ptr<ClinicalTest> createCinicalTest(const std::string& testId, const std::string& name,
        double cost);
    std::unique_ptr<Patient> findPatientById(const std::string& id);
    std::unique_ptr<RoomExamination> findRoomById(const std::string& id);
    std::unique_ptr<MedicalRecord> findRecordById(const std::string& id);
    std::unique_ptr<Medicine> findMedicineById(const std::string& id);
    std::unique_ptr<TestService> findTestServiceById(const std::string id);
    void updateRecord(std::unique_ptr<MedicalRecord> record);
    void orderMedicineUsage(std::unique_ptr<MedicalRecord> record, std::unique_ptr<MedicineUsage> usage);
    void orderClinicalTest(std::unique_ptr<MedicalRecord> record, std::unique_ptr<ClinicalTest> test);
};


#endif // !EXAMINATIONSERVICE_H
