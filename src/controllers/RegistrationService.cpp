#include "RegistrationService.h"

RegistrationService::RegistrationService(
    IPatientRepository* patients,
    IMedicalRecordRepository* records,
    IRoomExaminationRepository* rooms
)
    : _patients(patients)
    , _records(records)
    , _rooms(rooms) {}

void RegistrationService::updateRoom(
    const std::string& recordId,
    const std::string& roomId
) {
    auto room = findRoomById(roomId);
    auto copy = std::unique_ptr<RoomExamination>(
        static_cast<RoomExamination*>(room->clone()));
    copy->addToWaitingList(recordId);
    _rooms->update(*copy);
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
    _patients->add(std::move(patient));
    return ptr;
}

MedicalRecord* RegistrationService::createMedicalRecord(Patient* patient, const std::string& roomId) {
    auto data = _records->data();
    std::vector<const Object*> objectData(data.begin(), data.end());
    auto newId = createId(objectData, getFormat<MedicalRecord>());

    auto record = std::make_unique<MedicalRecord>(newId, patient->id());
    record->assignToRoom(roomId);
    updateRoom(record->id(), roomId);

    auto ptr = record.get();
    _records->add(std::move(record));

    return ptr;
}

std::unique_ptr<RoomExamination> RegistrationService::findRoomById(const std::string& id) {
    auto data = _rooms->data();
    auto record = from(data).where(&RoomExamination::id, id).findOne();
    if (!record) {
        return nullptr;
    }
    auto copy = static_cast<RoomExamination*>(record->clone());
    return std::unique_ptr<RoomExamination>(copy);
}
