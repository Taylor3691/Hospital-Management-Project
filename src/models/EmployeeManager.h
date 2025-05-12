#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "../interfaces/IManager.h"
#include "../interfaces/IEmployeeRepository.h"
#include "EmployeeQuery.h"

class EmployeeManager : public IManager<Employee> {
private:
    IEmployeeRepository* _employeeRepo;
    EmployeeQuery* _employeeQuery;

public:
    EmployeeManager(IEmployeeRepository* repo);
    ~EmployeeManager();

public:
    void add(std::unique_ptr<Employee> employee) override;
    void removeById(const std::string& id) override;
    std::vector<const Employee*> findAll() const;
    std::vector<const Employee*> findByName(const std::string& name) const;
    std::vector<const Employee*> findByType(const std::string& type) const;
    std::vector<const Employee*> findByEducation(const std::string& education) const;
    std::vector<const Employee*> findBySalary(double salary,
        ComparisonOperator op = ComparisonOperator::EQ) const;
};

#endif // !EMPLOYEEMANAGER_H
