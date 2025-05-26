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

struct Room {
    std::string id;
    std::string name;
    int waitings;
};

class ServiceLocator {
private:
    IPatientRepository* _patients;
    IDepartmentRepository* _departments;
    IRoomExaminationRepository* _rooms;
    IMedicineRepository* _medicines;
    IEmployeeRepository* _employees;
    IMedicalRecordRepository* _records;
    ITestServiceRepository* _tests;
    IParserFactory* _factory;

private:
    EmployeeManager* _employeeManager;
    DepartmentManager* _departmentManager;
    PatientManager* _patientManager;

private:
    inline static ServiceLocator* _singleton = nullptr;

private:
    ServiceLocator();

public:
    static ServiceLocator* getInstance();

public:

public:
    EmployeeManager* employeeManager();
    DepartmentManager* departmentManager();
    PatientManager* patientManager();
};

#endif // !SERVICE_LOCATOR_H
