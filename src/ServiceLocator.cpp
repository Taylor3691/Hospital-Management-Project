#include "ServiceLocator.h"

ServiceLocator::ServiceLocator() {
    Config* config = new Config("config.txt");
    config->loadFromFile();

    _factory = new TxtParserFactory('|');

    _patients = new TxtPatientRepository(config->getPath("patient_repo"));
    _rooms = new TxtRoomExaminationRepository(config->getPath("room_repo"));
    _medicines = new TxtMedicineRepository(config->getPath("medicine_repo"));
    _records = new TxtMedicalRecordRepository(config->getPath("record_repo"));
    _tests = new TxtTestServiceRepository(config->getPath("test_repo"));
    _employees = new TxtEmployeeRepository(config->getPath("employee_repo"));
    _departments = new TxtDepartmentRepository(config->getPath("department_repo"));

    _patientManager = new PatientManager(_patients);
    _employeeManager = new EmployeeManager(_employees);
    _departmentManager = new DepartmentManager(_departments);
}

ServiceLocator* ServiceLocator::getInstance() {
    if (_singleton == nullptr) {
        return new ServiceLocator();
    }
    return _singleton;
}

EmployeeManager* ServiceLocator::employeeManager() {
    return _employeeManager;
}

DepartmentManager* ServiceLocator::departmentManager() {
    return _departmentManager;
}

PatientManager* ServiceLocator::patientManager() {
    return _patientManager;
}

MedicineManager* ServiceLocator::medicineManager() {
    return _medicineManager;
}
