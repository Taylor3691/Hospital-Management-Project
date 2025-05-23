#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "../interfaces/IManager.h"
#include "../interfaces/IEmployeeRepository.h"
#include "../utils/QueryBuilder.h"

class EmployeeManager : public IManager<Employee> {
private:
    IEmployeeRepository* _repo;

public:
    EmployeeManager(IEmployeeRepository* repo);

public:
    void add(std::unique_ptr<Employee> employee) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids);
    void update(const Employee& employee) override;
    std::vector<const Employee*> find(const std::vector<RFilter<Employee>>& filters) const override;
    std::vector<const Employee*> getAll() const override;
};

#endif // !EMPLOYEE_MANAGER_H
