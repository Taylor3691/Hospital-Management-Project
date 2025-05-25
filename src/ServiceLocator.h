#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include "controllers/EmployeeManager.h"
#include "controllers/DepartmentManager.h"
#include "controllers/PatientManager.h"

struct Room {
    std::string id;
    std::string name;
    int waitings;
};

class ServiceLocator {
private:
    inline static EmployeeManager* _employeeManager = nullptr;
    inline static DepartmentManager* _departmentManager = nullptr;
    inline static PatientManager* _patientManager = nullptr;
    inline static std::vector<Room> _rooms = {
        { std::string("PHG-001"), std::string("Khám mắt"), 1 },
        { std::string("PHG-002"), std::string("Khám tổng quát"), 2 },
        { std::string("PHG-003"), std::string("Khám da liễu"), 3 },
        { std::string("PHG-001"), std::string("Khám mắt"), 1 },
        { std::string("PHG-002"), std::string("Khám tổng quát"), 2 },
        { std::string("PHG-003"), std::string("Khám da liễu"), 3 },
    };

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
    static const std::vector<Room>& rooms() { return _rooms; }
};

#endif // !SERVICE_LOCATOR_H
