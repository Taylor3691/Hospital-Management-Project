#ifndef REGISTRATION_SERVICE_H
#define REGISTRATION_SERVICE_H

#include "../interfaces/IPatientRepository.h"
#include "../interfaces/IMedicalRecordRepository.h"
#include "../interfaces/IRoomExaminationRepository.h"
#include "HealthInsurance.h"
#include "RoomExamination.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"
#include "RegisteredState.h"
#include "../utils/QueryBuilder.h"

class RegistrationService {
private:
    IPatientRepository* _patientRepo;
    IMedicalRecordRepository* _medicalRecordRepo;
    IRoomExaminationRepository* _roomRepo;

public:
    RegistrationService() = default;
    RegistrationService(IPatientRepository* patientRepo,
        IMedicalRecordRepository* medicalRecordRepo,
        IRoomExaminationRepository* roomRepo);

public:
    MedicalRecord* createMedicalRecord(Patient* patient);
    Patient* createPatient(const std::string& id,
        const std::string& name, const std::string& gender,
        const std::string& address, const std::string& phone,
        const Date& dob, const std::vector<std::string>& symptoms);
    std::unique_ptr<HealthInsurance> createInsurace(const std::string& id,
        const Date& startDate, const Date& endDate, double percent);
    void assignInsurance(Patient* patient,
        std::unique_ptr<HealthInsurance> insurance);
    void assignRoom(const std::string& roomId, MedicalRecord* record);
};

#endif // !REGISTRATION_SERVICE_H
