#ifndef IDEPARTMENT_REPOSITORY_H
#define IDEPARTMENT_REPOSITORY_H

#include "IRepository.h"
#include "../models/Department.h"

class IDepartmentRepository : public IRepository<Department> {
public:
    virtual ~IDepartmentRepository() = default;
};

#endif // !IDEPARTMENT_REPOSITORY_H
