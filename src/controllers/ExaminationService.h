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
    std::vector<MedicalRecord*> getAllRecord();
    std::vector<Doctor*> getAllDoctor();
    std::vector<Medicine*> getAllMedicine();
    std::vector<TestService*> getAllTestService();
    std::vector<RoomExamination*> getAllRoom();
    std::vector<MedicalRecord*> getAllRecordByState(const std::string& state);
    MedicineUsage* createMedicneUsage(const std::string& medicineId, const std::string& name,
        int quantity, double price, const std::string& description);
    ClinicalTest* createCinicalTest(const std::string& testId, const std::string& name,
        double cost);
    Patient* findPatientById(const std::string& id);
    RoomExamination* findRoomById(const std::string& id);
    MedicalRecord* findRecordById(const std::string& id);
    Medicine* findMedicineById(const std::string& id);
    TestService* findTestServiceById(const std::string id);
    void updateRecord(const MedicalRecord* record);
    void orderMedicineUsage(MedicalRecord* record, MedicineUsage* usage);
    void orderClinicalTest(MedicalRecord* record, ClinicalTest* usage);
};


#endif // !EXAMINATIONSERVICE_H
