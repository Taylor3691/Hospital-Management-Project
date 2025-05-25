#ifndef IEMPLOYEE_REPOSITORY_H
#define IEMPLOYEE_REPOSITORY_H

#include "IRepository.h"
#include "../models/Employee.h"

class IEmployeeRepository : public IRepository<Employee> {
public:
    virtual ~IEmployeeRepository() = default;
};

#endif // !IEMPLOYEE_REPOSITORY_H
