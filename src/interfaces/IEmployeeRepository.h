#ifndef IEMPLOYEEREPOSITORY
#define IEMPLOYEEREPOSITORY

#include <vector>
#include "IRepository.h"
#include "../models/Employee.h"

class IEmployeeRepository : public IRepository<Employee> {
public:
    virtual ~IEmployeeRepository() = default;

public:
    virtual std::vector<const Employee*> employees() const = 0;
};

#endif // !IEMPLOYEEREPOSITORY
