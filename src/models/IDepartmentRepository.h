#ifndef IDEPARTMENTREPOSITORY_H
#define IDEPARTMENTREPOSITORY_H
#include "Department.h"
#include <vector>
#include <iostream>
class IDepartmentRepository {
public:
    ~IDepartmentRepository() = default;
    virtual bool save(Department*) = 0;
    virtual std::vector<Department*> loadAll() = 0;
};



#endif // !IDepartmentRepository
