#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include <memory>
#include <iterator>
#include "DepartmentInfo.h"
#include "Employee.h"

class Department {
private:
    std::unique_ptr<DepartmentInfo> _info;
    std::vector<std::unique_ptr<Employee>> _staffs;

public:
    Department(std::unique_ptr<DepartmentInfo> info, std::vector<std::unique_ptr<Employee>>& staffs);

public:
    const DepartmentInfo* info() const;
    std::vector<std::unique_ptr<Employee>>& staffs();

public:
    const Doctor* getHeadDoctor() const;
    void assignHead(Doctor* doctor);
};

#endif
