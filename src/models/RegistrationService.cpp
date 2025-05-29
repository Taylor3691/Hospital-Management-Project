#include "RegistrationService.h"

RegistrationService::RegistrationService(
    IPatientRepository* patientRepo,
    IMedicalRecordRepository* medicalRecordRepo,
    IRoomExaminationRepository* roomRepo
)
    : _patientRepo(patientRepo)
    , _medicalRecordRepo(medicalRecordRepo)
    , _roomRepo(roomRepo) {}

void RegistrationService::updateRoom(
    const std::string& recordId,
    const std::string& roomId
) {
    auto data = _roomRepo->data();
    auto copy = std::unique_ptr<RoomExamination>(
        static_cast<RoomExamination*>(
            from(data)
            .where(&RoomExamination::id, roomId)
            .findOne()->clone()));
    copy->addToWaitingQueue(recordId);
    _roomRepo->update(*copy);
}

std::unique_ptr<HealthInsurance> RegistrationService::createInsurace(
    const std::string& id,
    const Date& startDate,
    const Date& endDate,
    double percent
) {
    auto insurance = std::make_unique<HealthInsurance>(
        id, startDate, endDate, percent);
    return std::move(insurance);
}

Patient* RegistrationService::createPatient(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::vector<std::string>& symptoms,
    std::unique_ptr<HealthInsurance> insurance
) {
    auto patient = std::make_unique<Patient>(id, name, gender,
        address, phone, dob, symptoms, std::move(insurance));
    auto ptr = patient.get();
    _patientRepo->add(std::move(patient));
    return ptr;
}

MedicalRecord* RegistrationService::createMedicalRecord(Patient* patient, const std::string& roomId) {
    auto data = _medicalRecordRepo->data();
    std::vector<const Object*> objectData(data.begin(), data.end());
    auto newId = createId(objectData, getFormat<MedicalRecord>());

    auto record = std::make_unique<MedicalRecord>(newId, patient->id());
    record->assignToRoom(roomId);
    updateRoom(record->id(), roomId);

    auto ptr = record.get();
    _medicalRecordRepo->add(std::move(record));

    return ptr;
}
