#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include "controllers/EmployeeManager.h"

class ServiceLocator {
private:
    inline static EmployeeManager* _employeeManager = nullptr;

public:
    static void provide(EmployeeManager* manager) {
        _employeeManager = manager;
    }

    static EmployeeManager* employeeManager() { return _employeeManager; }
};

#endif // !SERVICE_LOCATOR_H
