#ifndef IEMPLOYEE_REPOSITORY
#define IEMPLOYEE_REPOSITORY

#include "IRepository.h"
#include "../models/Employee.h"

class IEmployeeRepository : public IRepository<Employee> {
public:
    virtual ~IEmployeeRepository() = default;
};

#endif // !IEMPLOYEE_REPOSITORY
