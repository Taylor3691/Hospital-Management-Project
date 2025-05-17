// DepartmentManager.h
#ifndef DEPARTMENT_MANAGER_H
#define DEPARTMENT_MANAGER_H
#include "IManager.h" // Giả định IManager được định nghĩa
#include "IDepartmentRepository.h"
#include "DepartmentQuery.h"
#include <vector>
#include <string>

class DepartmentManager : public IManager<Department> {
public:
    DepartmentManager(IDepartmentRepository* departmentRepo);
    void addDepartment(Department* department);
    void removeDepartment(const std::string& id);
    std::vector<Department*> findAll();
    std::vector<Department*> findByName(const std::string& name);
    ~DepartmentManager();

private:
    IDepartmentRepository* _departmentRepo;
    DepartmentQuery* _departmentQuery;
};

#endif