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

std::vector<std::unique_ptr<MedicalRecord>> ExaminationService::getAllRecord() {
    std::vector<std::unique_ptr<MedicalRecord>> result;

    for (auto record : _records->data()) {
        result.push_back(std::unique_ptr<MedicalRecord>(
            dynamic_cast<MedicalRecord*>(record->clone())
        ));
     }

    return result;
}

std::vector<std::unique_ptr<Doctor>> ExaminationService::getAllDoctor() {
    std::vector<std::unique_ptr<Doctor>> result;
    auto employees = _employees->data();

    std::string role = typeid(Doctor).name();
    FilterCriteria criteria;
    criteria.value = role;
    Getter<Employee> getter = [](auto& e) {
        return std::string(typeid(e).name());
    };

    auto doctors = from(employees).where(getter, criteria.value, criteria.op).find();
    for (auto doctor : doctors) {
        auto unit = dynamic_cast<Doctor*>(doctor->clone());
        result.push_back(std::unique_ptr<Doctor>(
            dynamic_cast<Doctor*>(doctor->clone())
        ));
    }

    return result;
}

std::vector<std::unique_ptr<Medicine>> ExaminationService::getAllMedicine() {
    std::vector<std::unique_ptr<Medicine>> result;
    for (auto medicine : _medicines->data()) { 
        result.push_back(std::unique_ptr<Medicine>(
            dynamic_cast<Medicine*>(medicine->clone())
        ));
    }
    return result;
}

std::vector<std::unique_ptr<TestService>> ExaminationService::getAllTestService() {
    std::vector<std::unique_ptr<TestService>> result;
    for (auto test : _tests->data()) {
        result.push_back(std::unique_ptr<TestService>(
            dynamic_cast<TestService*>(test->clone())
        ));
    }
    return result;
}

std::vector<std::unique_ptr<RoomExamination>> ExaminationService::getAllRoom() {
    std::vector<std::unique_ptr<RoomExamination>> result;

    for (auto room : _rooms->data()) {
        result.push_back(std::unique_ptr<RoomExamination>(
            dynamic_cast<RoomExamination*>(room->clone())
        ));
    }
    return result;
}

std::vector<std::unique_ptr<MedicalRecord>> ExaminationService::getAllRecordByState(const std::string& state) {
    auto store = _records->data();
    std::vector<std::unique_ptr<MedicalRecord>> result;
    for (auto record : store) {
        if (record->state()->getStateName() == state) {
            result.push_back(std::unique_ptr<MedicalRecord>(
                dynamic_cast<MedicalRecord*>(record->clone())
            ));
        }
    }
    return result;
}

std::unique_ptr<MedicineUsage> ExaminationService::createMedicineUsage(const std::string& medicineId, const std::string& name,
    int quantity, double price, const std::string& description)
{
    auto date = Date::getDate().toString(Date::getDate());
    auto time = Time::getCurrentTime().toString();
    MedicineUsage* usage = new MedicineUsage("MEUSE-" + date + "-" + time, name, medicineId, quantity, price, description);
    return std::unique_ptr<MedicineUsage>(usage);
}

std::unique_ptr<ClinicalTest> ExaminationService::createCinicalTest(const std::string& testId, const std::string& name, double cost)
{
    auto date = Date::getDate().toString(Date::getDate());
    auto time = Time::getCurrentTime().toString();
    ClinicalTest* test = new ClinicalTest("CLSUSE-" + date + "-" + time, name, testId, cost, "", false);
    return std::unique_ptr<ClinicalTest>(test);
}

std::unique_ptr<Patient> ExaminationService::findPatientById(const std::string& id) {
    auto store = _patients->data();
    auto record = from(store).where(&Patient::id, id).findOne();
    if (record == nullptr) return nullptr;
    auto result = dynamic_cast<Patient*>(record->clone());
    return std::unique_ptr<Patient>(result);
}

std::unique_ptr<RoomExamination> ExaminationService::findRoomById(const std::string& id) {
    auto store = _rooms->data();
    auto record = from(store).where(&RoomExamination::id, id).findOne();
    if (record == nullptr) return nullptr;
    auto result = dynamic_cast<RoomExamination*>(record->clone());
    return std::unique_ptr<RoomExamination>(result);
}

std::unique_ptr<MedicalRecord> ExaminationService::findRecordById(const std::string& id) {
    auto store = _records->data();
    auto record = from(store).where(&MedicalRecord::id, id).findOne();
    if (record == nullptr) {
        return nullptr;
    }
    auto result = dynamic_cast<MedicalRecord*>(record->clone());
    return std::unique_ptr<MedicalRecord>(result);
}

std::unique_ptr<Medicine> ExaminationService::findMedicineById(const std::string& id) {
    auto store = _medicines->data();
    auto medicine = from(store).where(&Medicine::id, id).findOne();
    if (medicine == nullptr) {
        return nullptr;
    }
    auto result = dynamic_cast<Medicine*>(medicine->clone());
    return std::unique_ptr<Medicine>(result);
}

std::unique_ptr<TestService> ExaminationService::findTestServiceById(const std::string id) {
    auto store = _tests->data();
    auto test = from(store).where(&TestService::id, id).findOne();
    if (test == nullptr) {
        return nullptr;
    }
    auto result = dynamic_cast<TestService*>(test->clone());
    return std::unique_ptr<TestService>(result);
}

void  ExaminationService::updateRecord(std::unique_ptr<MedicalRecord> record) {
    _records->update(*record.get());
}


