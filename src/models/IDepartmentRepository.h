// IDepartmentRepository.h
#ifndef IDEPARTMENT_REPOSITORY_H
#define IDEPARTMENT_REPOSITORY_H
#include "IRepository.h" // Giả định IRepository được định nghĩa
#include "Department.h"
#include <vector>
#include <string>

class IDepartmentRepository : public IRepository<Department> {
public:
    virtual void add(Department* department) = 0;
    virtual void remove(const std::string& id) = 0;
    virtual Department* find(const std::string& id) = 0;
    virtual std::vector<Department*> findAll() = 0;
    virtual void save() = 0;
    virtual void load() = 0;
    virtual ~IDepartmentRepository() = default;
};

#endif