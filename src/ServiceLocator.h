#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include "controllers/EmployeeManager.h"
#include "controllers/DepartmentManager.h"
#include "controllers/PatientManager.h"

class ServiceLocator {
private:
    inline static EmployeeManager* _employeeManager = nullptr;
    inline static DepartmentManager* _departmentManager = nullptr;
    inline static PatientManager* _patientManager = nullptr;

public:
    static void provide(
        EmployeeManager* employeeManager,
        DepartmentManager* departmentManager,
        PatientManager* patientManager
    ) {
        _employeeManager = employeeManager;
        _departmentManager = departmentManager;
        _patientManager = patientManager;
    }

    static EmployeeManager* employeeManager() { return _employeeManager; }
    static DepartmentManager* departmentManager() { return _departmentManager; }
    static PatientManager* patientManager() { return _patientManager; }
};

#endif // !SERVICE_LOCATOR_H
