#ifndef EMPLOYEEQUERY_H
#define EMPLOYEEQUERY_H

#include <typeinfo>
#include "../interfaces/IQuery.h"
#include "../interfaces/IEmployeeRepository.h"
#include "../utils/QueryBuilder.h"

class EmployeeQuery : public IQuery<Employee> {
private:
    IEmployeeRepository* _repo;

public:
    const Employee* findById(const std::string& id) const override;
    std::vector<const Employee*> findAll() const override;
    std::vector<const Employee*> findByName(const std::string& name) const;
    std::vector<const Employee*> findByEducation(const std::string& education) const;
    std::vector<const Employee*> findByType(const std::string& type) const;
    std::vector<const Employee*> findBySalary(const std::string& salary,
        ComparisonOperator op = ComparisonOperator::EQ) const;
};

#endif // !EMPLOYEEQUERY_H
