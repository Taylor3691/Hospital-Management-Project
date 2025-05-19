#ifndef IDEPARTMENT_REPOSITORY
#define IDEPARTMENT_REPOSITORY

#include "IRepository.h"
#include "../models/Department.h"

class IDepartmentRepository : public IRepository<Department> {
public:
    virtual ~IDepartmentRepository() = default;
};

#endif // !IDEPARTMENT_REPOSITORY
