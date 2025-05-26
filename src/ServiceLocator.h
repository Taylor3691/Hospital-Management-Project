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
        { std::string("PHG-001"), std::string("Khám Da Liễu"), 3 },
        { std::string("PHG-002"), std::string("Khám Nội Tổng Quát"), 1 },
        { std::string("PHG-003"), std::string("Khám Ngoại Tổng Quát"), 2 },
        { std::string("PHG-004"), std::string("Khám Nhi"), 3 },
        { std::string("PHG-005"), std::string("Khám Sản"), 1 },
        { std::string("PHG-006"), std::string("Khám Mắt"), 2 },
        { std::string("PHG-007"), std::string("Khám Tai Mũi Họng"), 3 },
        { std::string("PHG-008"), std::string("Khám Răng Hàm Mặt"), 0 },
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
