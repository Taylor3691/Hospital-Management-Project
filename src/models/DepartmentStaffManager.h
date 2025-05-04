#ifndef DEPARTMENTSTAFFMANAGER_H
#define DEPARTMENTSTAFFMANAGER_H

#include "Manager.h"
#include "Employee.h"

class DepartmentStaffManager : public Manager<Employee> {
private:
    int _maxStaff;

public:
    void add(std::vector<std::unique_ptr<Employee>>& employees,
        std::unique_ptr<Employee> employee) override;
};

#endif
