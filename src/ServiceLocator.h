#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include "Config.h"
#include "controllers/EmployeeManager.h"
#include "controllers/DepartmentManager.h"
#include "controllers/PatientManager.h"
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

private:
    ServiceLocator();

public:
    static ServiceLocator* getInstance();

public:
    IPatientRepository* patients() const;
    IDepartmentRepository* departments() const;
    IRoomExaminationRepository* rooms() const;
    IMedicineRepository* medicines() const;
    IEmployeeRepository* employees() const;
    IMedicalRecordRepository* records() const;
    ITestServiceRepository* tests() const;
    IParserFactory* factory() const;
    EmployeeManager* employeeManager() const;
    DepartmentManager* departmentManager() const;
    PatientManager* patientManager() const;
};

#endif // !SERVICE_LOCATOR_H
