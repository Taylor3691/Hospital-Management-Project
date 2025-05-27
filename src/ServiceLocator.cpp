#include "ServiceLocator.h"

ServiceLocator::ServiceLocator() {
    auto config = std::make_unique<Config>("config.txt");
    config->loadFromFile();

    _factory = std::make_unique<TxtParserFactory>(config->get("delim")[0]);

    _patients = std::make_unique<TxtPatientRepository>(config->get("patient_repo_path"));
    _rooms = std::make_unique<TxtRoomExaminationRepository>(config->get("room_repo_path"));
    _medicines = std::make_unique<TxtMedicineRepository>(config->get("medicine_repo_path"));
    _records = std::make_unique<TxtMedicalRecordRepository>(config->get("record_repo_path"));
    _tests = std::make_unique<TxtTestServiceRepository>(config->get("test_repo_path"));
    _employees = std::make_unique<TxtEmployeeRepository>(config->get("employee_repo_path"));
    _departments = std::make_unique<TxtDepartmentRepository>(config->get("department_repo_path"));

    _patientManager = std::make_unique<PatientManager>(_patients.get());
    _employeeManager = std::make_unique<EmployeeManager>(_employees.get());
    _departmentManager = std::make_unique<DepartmentManager>(_departments.get());
}

ServiceLocator* ServiceLocator::getInstance() {
    static std::unique_ptr<ServiceLocator> instance(new ServiceLocator());
    return instance.get();
}

IPatientRepository* ServiceLocator::patients() const {
    return _patients.get();
}

IMedicineRepository* ServiceLocator::medicines() const {
    return _medicines.get();
}

IEmployeeRepository* ServiceLocator::employees() const {
    return _employees.get();
}

IRoomExaminationRepository* ServiceLocator::rooms() const {
    return _rooms.get();
}

IMedicalRecordRepository* ServiceLocator::records() const {
    return _records.get();
}

ITestServiceRepository* ServiceLocator::tests() const {
    return _tests.get();
}

IParserFactory* ServiceLocator::factory() const {
    return _factory.get();
}

EmployeeManager* ServiceLocator::employeeManager() const {
    return _employeeManager.get();
}

DepartmentManager* ServiceLocator::departmentManager() const {
    return _departmentManager.get();
}

PatientManager* ServiceLocator::patientManager() const {
    return _patientManager.get();
}
