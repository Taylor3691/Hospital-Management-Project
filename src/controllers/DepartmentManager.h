#ifndef DEPARTMENT_MANAGER_H
#define DEPARTMENT_MANAGER_H

#include "../interfaces/IManager.h"
#include "../interfaces/IDepartmentRepository.h"
#include "../models/DepartmentQuery.h"

class DepartmentManager : public IManager<Department> {
private:
    IDepartmentRepository* _departmentRepo;
    DepartmentQuery* _departmentQuery;

public:
    DepartmentManager(IDepartmentRepository* repo);
    ~DepartmentManager();

public:
    void add(std::unique_ptr<Department> department) override;
    void removeById(const std::string& id) override;
    std::vector<const Department*> findAll() const;
    std::vector<const Department*> findByName(const std::string& name) const;
};

#endif // !DEPARTMENT_MANAGER_H
