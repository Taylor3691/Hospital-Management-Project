#ifndef REGISTRATION_SERVICE_H
#define REGISTRATION_SERVICE_H

#include "../interfaces/IPatientRepository.h"
#include "../interfaces/IMedicalRecordRepository.h"
#include "../interfaces/IRoomExaminationRepository.h"
#include "../models/HealthInsurance.h"
#include "../models/RoomExamination.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"

class RegistrationService {
private:
    IPatientRepository* _patients;
    IMedicalRecordRepository* _records;
    IRoomExaminationRepository* _rooms;

public:
    RegistrationService() = default;
    RegistrationService(IPatientRepository* patients,
        IMedicalRecordRepository* records,
        IRoomExaminationRepository* rooms);

public:
    std::unique_ptr<HealthInsurance> createInsurace(
        const std::string& id, const Date& startDate,
        const Date& endDate, double percent);
    Patient* createPatient(const std::string& id,
        const std::string& name, const std::string& gender,
        const std::string& address, const std::string& phone,
        const Date& dob, const std::vector<std::string>& symptoms,
        std::unique_ptr<HealthInsurance> insurance = nullptr);
    MedicalRecord* createMedicalRecord(
        Patient* patient, const std::string& roomId);
    std::unique_ptr<RoomExamination> findRoomById(const std::string& id);
};

#endif // !REGISTRATION_SERVICE_H
