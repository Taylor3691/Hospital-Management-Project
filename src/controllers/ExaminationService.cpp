#include "ExaminationService.h"

ExaminationService::ExaminationService(
    IMedicalRecordRepository* records,
    IMedicineRepository* medicines,
    IRoomExaminationRepository* rooms,
    TxtTestServiceRepository* tests,
    IEmployeeRepository* employees,
    IPatientRepository* patients
)
    : _records(records)
    , _medicines(medicines)
    , _rooms(rooms)
    , _tests(tests)
    , _employees(employees)
    , _patients(patients) {}

std::vector<MedicalRecord*> ExaminationService::getAllRecord() {
    std::vector<MedicalRecord*> result;

    for (auto record : _records->data()) {
        MedicalRecord* clone = dynamic_cast<MedicalRecord*>(record->clone());
        result.push_back(clone);
     }

    return result;
}

std::vector<Doctor*> ExaminationService::getAllDoctor() {
    std::vector<Doctor*> result;
    auto employees = _employees->data();

    std::string role = typeid(Doctor).name();
    FilterCriteria criteria;
    criteria.value = role;
    Getter<Employee> getter = [](auto& e) {
        return std::string(typeid(e).name());
    };

    auto doctors = from(employees).where(getter, criteria.value, criteria.op).find();
    for (auto doctor : doctors) {
        result.push_back(dynamic_cast<Doctor*>(doctor->clone()));
    }

    return result;
}

std::vector<Medicine*> ExaminationService::getAllMedicine() {
    std::vector<Medicine*> result;
    for (auto medicine : _medicines->data()) {
        Medicine* clone = dynamic_cast<Medicine*>(medicine->clone());
        result.push_back(clone);
    }
    return result;
}

std::vector<TestService*> ExaminationService::getAllTestService() {
    std::vector<TestService*> result;
    for (auto test : _tests->data()) {
        TestService* clone = dynamic_cast<TestService*>(test->clone());
        result.push_back(clone);
    }
    return result;
}

std::vector<RoomExamination*> ExaminationService::getAllRoom() {
    std::vector<RoomExamination*> result;
    for (auto room : _rooms->data()) {
        RoomExamination* clone = dynamic_cast<RoomExamination*>(room->clone());
    }
    return result;
}

std::vector<MedicalRecord*> ExaminationService::getAllRecordByState(const std::string& state) {
    auto store = _records->data();
    std::vector<MedicalRecord*> result;
    for (auto record : store) {
        if (record->state()->getStateName() == state) {
            result.push_back(dynamic_cast<MedicalRecord*>(record->clone()));
        }
    }
    return result;
}

MedicineUsage* ExaminationService::createMedicneUsage(const std::string& medicineId, const std::string& name,
    int quantity, double price, const std::string& description)
{
    auto date = Date::getDate().toString(Date::getDate());
    auto time = Time::getCurrentTime().toString();
    MedicineUsage* usage = new MedicineUsage("MEUSE-" + date + "-" + time, name, medicineId, quantity, price, description);
    return usage;
}

ClinicalTest* ExaminationService::createCinicalTest(const std::string& testId, const std::string& name, double cost)
{
    auto date = Date::getDate().toString(Date::getDate());
    auto time = Time::getCurrentTime().toString();
    ClinicalTest* test = new ClinicalTest("CLSUSE-" + date + "-" + time, name, testId, cost, "", false);
    return test;
}

Patient* ExaminationService::findPatientById(const std::string& id) {
    auto store = _patients->data();
    auto record = from(store).where(&Patient::id, id).findOne();
    return dynamic_cast<Patient*>(record->clone());
}

RoomExamination* ExaminationService::findRoomById(const std::string& id) {
    auto store = _rooms->data();
    auto record = from(store).where(&RoomExamination::id, id).findOne();
    return dynamic_cast<RoomExamination*>(record->clone());
}

MedicalRecord* ExaminationService::findRecordById(const std::string& id) {
    auto store = _records->data();
    auto record = from(store).where(&MedicalRecord::id, id).findOne();
    return dynamic_cast<MedicalRecord*>(record->clone());
}

Medicine* ExaminationService::findMedicineById(const std::string& id) {
    auto store = _medicines->data();
    auto medicine = from(store).where(&Medicine::id, id).findOne();
    return dynamic_cast<Medicine*>(medicine->clone());
}

TestService* ExaminationService::findTestServiceById(const std::string id) {
    auto store = _tests->data();
    auto test = from(store).where(&TestService::id, id).findOne();
    return dynamic_cast<TestService*>(test->clone());
}

void ExaminationService::updateRecord(const MedicalRecord* record) {
    _records->update(*record);
}

void ExaminationService::orderMedicineUsage(MedicalRecord* record, MedicineUsage* usage) {
    if (!record->state()->canPrescribeMedicine()) {
        delete usage;
        throw std::runtime_error(record->state()->getStateName() + " state cannot prescribe medicine");
    }
    auto store = _medicines->data();
    auto medicine = from(store).where(&Medicine::id, usage->medicineId()).findOne();
    if (medicine->quantity() >= usage->usedQuantity()) {
        record->prescribeMedicine(usage);
        updateRecord(record);
    }
    else {
        delete usage;
        throw std::runtime_error("Not enough quantity to prescribe");
    }
}

void ExaminationService::orderClinicalTest(MedicalRecord* record, ClinicalTest* usage) {
    if (!record->state()->canOrderClinicalTest()) {
        delete usage;
        throw std::runtime_error(record->state()->getStateName() + " state cannot order clinical test");
    }

    record->orderClinicalTest(usage);
    updateRecord(record);
}
