#ifndef IEMPLOYEEREPOSITORY
#define IEMPLOYEEREPOSITORY

#include "IRepository.h"
#include "../models/Employee.h"

class IEmployeeRepository : public IRepository<Employee> {
public:
    virtual ~IEmployeeRepository() = default;
};

#endif // !IEMPLOYEEREPOSITORY
