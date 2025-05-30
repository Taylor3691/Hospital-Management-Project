#include "ExaminationService.h"

ExaminationService::ExaminationService(
    IMedicalRecordRepository* records,
    IMedicineRepository* medicines,
    IRoomExaminationRepository* rooms,
    ITestServiceRepository* tests,
    IEmployeeRepository* employees,
    IPatientRepository* patients
)
    : _records(records)
    , _medicines(medicines)
    , _rooms(rooms)
    , _tests(tests)
    , _employees(employees)
    , _patients(patients) {}

std::vector<std::unique_ptr<MedicalRecord>> ExaminationService::getAllRecords() {
    std::vector<std::unique_ptr<MedicalRecord>> results;

    for (auto record : _records->data()) {
        results.push_back(std::unique_ptr<MedicalRecord>(
            static_cast<MedicalRecord*>(record->clone())
        ));
    }

    return results;
}

std::vector<std::unique_ptr<Doctor>> ExaminationService::getAllDoctors() {
    std::vector<std::unique_ptr<Doctor>> results;
    auto employees = _employees->data();

    std::string role = typeid(Doctor).name();
    FilterCriteria criteria;
    criteria.value = role;
    Getter<Employee> getter = [](auto& e) {
        return std::string(typeid(e).name());
    };

    auto doctors = from(employees).where(getter, criteria.value, criteria.op).find();
    for (auto doctor : doctors) {
        auto unit = static_cast<Doctor*>(doctor->clone());
        results.push_back(std::unique_ptr<Doctor>(
            static_cast<Doctor*>(doctor->clone())
        ));
    }

    return results;
}

std::vector<std::unique_ptr<Medicine>> ExaminationService::getAllMedicines() {
    std::vector<std::unique_ptr<Medicine>> results;
    for (auto medicine : _medicines->data()) { 
        results.push_back(std::unique_ptr<Medicine>(
            static_cast<Medicine*>(medicine->clone())
        ));
    }
    return results;
}

std::vector<std::unique_ptr<TestService>> ExaminationService::getAllTestServices() {
    std::vector<std::unique_ptr<TestService>> results;
    for (auto test : _tests->data()) {
        results.push_back(std::unique_ptr<TestService>(
            static_cast<TestService*>(test->clone())
        ));
    }
    return results;
}

std::vector<std::unique_ptr<RoomExamination>> ExaminationService::getAllRooms() {
    std::vector<std::unique_ptr<RoomExamination>> results;

    for (auto room : _rooms->data()) {
        results.push_back(std::unique_ptr<RoomExamination>(
            static_cast<RoomExamination*>(room->clone())
        ));
    }
    return results;
}

std::vector<const MedicalRecord*> ExaminationService::getAllRecordsInRoom(
    const std::string& roomId
) {
    auto data = _records->data();
    return from(data).where(&MedicalRecord::roomId, roomId).find();
}

std::vector<const MedicalRecord*> ExaminationService::getAllRecordsInRoomByState(
    const std::string& roomId,
    ExaminationState::State state
) {
    Getter<MedicalRecord> stateGetter = [](const MedicalRecord& record) {
        return (int)record.state()->getStateName();
    };
    auto data = _records->data();
    return from(data)
        .where(&MedicalRecord::roomId, roomId)
        .where(stateGetter, (int)state)
        .find();
}

std::unique_ptr<MedicineUsage> ExaminationService::createMedicineUsage(
    const std::string& medicineId,
    const std::string& name,
    int quantity,
    double price,
    const std::string& description
) {
    auto date = Date::getDate().toString(Date::getDate());
    auto time = Time::getCurrentTime().toString();
    return std::make_unique<MedicineUsage>(
        "MEUSE-" + date + "-" + time,
        name,
        medicineId,
        quantity,
        price,
        description
    );
}

std::unique_ptr<ClinicalTest> ExaminationService::createCinicalTest(
    const std::string& testId,
    const std::string& name,
    double cost
) {
    auto date = Date::getDate().toString(Date::getDate());
    auto time = Time::getCurrentTime().toString();
    return std::make_unique<ClinicalTest>(
        "CLSUSE-" + date + "-" + time,
        name,
        testId,
        cost
    );
}

std::unique_ptr<Doctor> ExaminationService::findDoctorById(const std::string& id) {
    auto doctors = getAllDoctors();
    auto record = from(doctors).where(&Doctor::id, id).findOne();
    if (!record) {
        return nullptr;
    }
    auto copy = static_cast<Doctor*>(record->clone());
    return std::unique_ptr<Doctor>(copy);
}

std::unique_ptr<Patient> ExaminationService::findPatientById(const std::string& id) {
    auto data = _patients->data();
    auto record = from(data).where(&Patient::id, id).findOne();
    if (!record) {
        return nullptr;
    }
    auto copy = static_cast<Patient*>(record->clone());
    return std::unique_ptr<Patient>(copy);
}

std::unique_ptr<MedicalRecord> ExaminationService::findRecordById(const std::string& id) {
    auto data = _records->data();
    auto record = from(data).where(&MedicalRecord::id, id).findOne();
    if (!record) {
        return nullptr;
    }
    auto copy = static_cast<MedicalRecord*>(record->clone());
    return std::unique_ptr<MedicalRecord>(copy);
}

std::unique_ptr<Medicine> ExaminationService::findMedicineById(const std::string& id) {
    auto data = _medicines->data();
    auto medicine = from(data).where(&Medicine::id, id).findOne();
    if (!medicine) {
        return nullptr;
    }
    auto copy = static_cast<Medicine*>(medicine->clone());
    return std::unique_ptr<Medicine>(copy);
}

std::unique_ptr<TestService> ExaminationService::findTestServiceById(const std::string id) {
    auto data = _tests->data();
    auto test = from(data).where(&TestService::id, id).findOne();
    if (!test) {
        return nullptr;
    }
    auto copy = static_cast<TestService*>(test->clone());
    return std::unique_ptr<TestService>(copy);
}

void ExaminationService::updateRecord(std::unique_ptr<MedicalRecord> record) {
    _records->update(*record.get());
}
