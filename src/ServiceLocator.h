#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include "Config.h"

#include "controllers/MedicineManager.h"
#include "controllers/EmployeeManager.h"
#include "controllers/DepartmentManager.h"
#include "controllers/PatientManager.h"
#include "controllers/RegistrationService.h"
#include "controllers/ExaminationService.h"
#include "controllers/TestProcessingService.h"
#include "controllers/BillService.h"

#include "models/TxtPatientRepository.h"
#include "models/TxtDepartmentRepository.h"
#include "models/TxtMedicalRecordRepository.h"
#include "models/TxtTestServiceRepository.h"
#include "models/TxtEmployeeRepository.h"
#include "models/TxtMedicineRepository.h"
#include "models/TxtRoomExaminationRepository.h"
#include "models/TxtParserFactory.h"

class ServiceLocator {
private:
    std::unique_ptr<IPatientRepository> _patients;
    std::unique_ptr<IDepartmentRepository> _departments;
    std::unique_ptr<IRoomExaminationRepository> _rooms;
    std::unique_ptr<IMedicineRepository> _medicines;
    std::unique_ptr<IEmployeeRepository> _employees;
    std::unique_ptr<IMedicalRecordRepository> _records;
    std::unique_ptr<ITestServiceRepository> _tests;
    std::unique_ptr<IParserFactory> _factory;
    std::unique_ptr<EmployeeManager> _employeeManager;
    std::unique_ptr<DepartmentManager> _departmentManager;
    std::unique_ptr<PatientManager> _patientManager;
    std::unique_ptr<MedicineManager> _medicineManager;
    std::unique_ptr<RegistrationService> _registrationService;
    std::unique_ptr<ExaminationService> _examinationService;
    std::unique_ptr<TestProcessingService> _testProcessingService;
    std::unique_ptr<BillService> _billService;

private:
    ServiceLocator();

public:
    static ServiceLocator* instance();

public:
    IPatientRepository* patientRepository() const;
    IEmployeeRepository* employeeRepository() const;
    ITestServiceRepository* testServiceRepository() const;
    IMedicalRecordRepository* medicalRecordRepository() const;
    IMedicineRepository* medicineRepository() const;
    IRoomExaminationRepository* roomExaminationRepository() const;
    IDepartmentRepository* departmentRepository() const;
    IParserFactory* parseFactory() const;

public:
    EmployeeManager* employeeManager() const;
    DepartmentManager* departmentManager() const;
    PatientManager* patientManager() const;
    MedicineManager* medicineManager() const;

public:
    RegistrationService* registrationService() const;
    ExaminationService* examinationService() const;
    TestProcessingService* testProcessingService() const;
    BillService* billService() const;
};

#endif // !SERVICE_LOCATOR_H
