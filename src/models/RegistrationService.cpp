#include "RegistrationService.h"

RegistrationService::RegistrationService(
    IPatientRepository* patientRepo,
    IMedicalRecordRepository* medicalRecordRepo,
    IRoomExaminationRepository* roomRepo
)
    : _patientRepo(patientRepo)
    , _medicalRecordRepo(medicalRecordRepo)
    , _roomRepo(roomRepo) {}

MedicalRecord* RegistrationService::createMedicalRecord(Patient* patient) {
    auto data = _medicalRecordRepo->data();
    auto newId = createId(data, getFormat<MedicalRecord>());
    auto record = std::make_unique<MedicalRecord>(newId, patient->id());
    record->changeState(std::make_unique<RegisteredState>());
    auto ptr = record.get();
    _medicalRecordRepo->add(std::move(record));
    return ptr;
}

Patient* RegistrationService::createPatient(
    const std::string& id,
    const std::string& name,
    const std::string& gender,
    const std::string& address,
    const std::string& phone,
    const Date& dob,
    const std::vector<std::string>& symptoms
) {
    auto patient = std::make_unique<Patient>(
        id, name, gender, address, phone, dob, symptoms);
    auto ptr = patient.get();
    _patientRepo->add(std::move(patient));
    return ptr;
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

void RegistrationService::assignInsurance(
    Patient* patient,
    std::unique_ptr<HealthInsurance> insurance
) {
    patient->setInsuranceCard(std::move(insurance));
}

void RegistrationService::assignRoom(
    const std::string& roomId,
    MedicalRecord* record
) {
    record->assignToRoom(roomId);
}
