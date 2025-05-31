#ifndef EXAMINATION_SERVICE_H
#define EXAMINATION_SERVICE_H

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
    ExaminationService(IMedicalRecordRepository* records, IMedicineRepository* medicines,
        IRoomExaminationRepository* rooms, ITestServiceRepository* tests,
        IEmployeeRepository* employees, IPatientRepository* patients);

public:
    std::vector<std::unique_ptr<MedicalRecord>> getAllRecords();
    std::vector<std::unique_ptr<Doctor>> getAllDoctors();
    std::vector<std::unique_ptr<Medicine>> getAllMedicines();
    std::vector<std::unique_ptr<TestService>> getAllTestServices();
    std::vector<std::unique_ptr<RoomExamination>> getAllRooms();
    std::vector<const MedicalRecord*> getAllRecordsInRoom(
        const std::string& roomId);
    std::vector<const MedicalRecord*> getAllRecordsInRoomByState(
        const std::string& roomId,
        ExaminationState::State state = ExaminationState::Waiting);
    std::unique_ptr<MedicineUsage> createMedicineUsage(
        const std::string& medicineId, const std::string& name,
        int quantity, double price, const std::string& description);
    std::unique_ptr<ClinicalTest> createCinicalTest(
        const std::string& testId, const std::string& name, double cost);
    std::unique_ptr<Doctor> findDoctorById(const std::string& id);
    std::unique_ptr<Patient> findPatientById(const std::string& id);
    std::unique_ptr<MedicalRecord> findRecordById(const std::string& id);
    std::unique_ptr<Medicine> findMedicineById(const std::string& id);
    std::unique_ptr<TestService> findTestServiceById(const std::string id);
    std::string findDoctorIdByName(const std::string& name);
    void startExamination(const std::string& recordId, const std::string& doctorId);
    void cancelExamination(const std::string& recordId);
    std::unique_ptr<ExaminationState> recordState(const std::string& recordId);
    std::vector<std::string> clinicalTestIds(const std::string& recordId);
    void orderClinicalTests(const std::string& recordId,
        const std::vector<std::string>& specifiedTests);
    void updateClinicalTest(const std::string& recordId,
        std::unique_ptr<ClinicalTest> test);
    void prescribeMedicine(const std::string& recordId,
        std::unique_ptr<MedicineUsage> usage);
    void compeleteExamination(const std::string& recordId, const std::string& result);
};

#endif // !EXAMINATION_SERVICE_H
