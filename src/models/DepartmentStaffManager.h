#ifndef DEPARTMENTSTAFFMANAGER_H
#define DEPARTMENTSTAFFMANAGER_H

#include "Manager.h"
#include "Employee.h"
#include "Department.h"

class DepartmentStaffManager : public Manager<Employee> {
private:
    DepartmentStaffManager() = default;
    ~DepartmentStaffManager() = default;

public:
    DepartmentStaffManager(const DepartmentStaffManager&) = delete;

public:
    static DepartmentStaffManager* getInstance();

public:
    void add(Department* department, std::unique_ptr<Employee> staff);

public:
    DepartmentStaffManager& operator=(const DepartmentStaffManager&) = delete;
};

#endif
