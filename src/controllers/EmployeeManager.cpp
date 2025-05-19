#include "EmployeeManager.h"

EmployeeManager::EmployeeManager(IEmployeeRepository* repo)
    : _employeeRepo(repo)
    , _employeeQuery(new EmployeeQuery(repo)) {}

EmployeeManager::~EmployeeManager() {
    delete _employeeQuery;
}

void EmployeeManager::add(std::unique_ptr<Employee> employee) {
    _employeeRepo->add(std::move(employee));
}

void EmployeeManager::removeById(const std::string& id) {
    _employeeRepo->removeById(id);
}

std::vector<const Employee*> EmployeeManager::findAll() const {
    return _employeeQuery->findAll();
}

std::vector<const Employee*> EmployeeManager::findByName(
    const std::string& name
) const {
    return _employeeQuery->findByName(name);
}

std::vector<const Employee*> EmployeeManager::findByType(
    const std::string& type
) const {
    return _employeeQuery->findByType(type);
}

std::vector<const Employee*> EmployeeManager::findByEducation(
    const std::string& education
) const {
    return _employeeQuery->findByEducation(education);
}

std::vector<const Employee*> EmployeeManager::findBySalary(
    double salary, ComparisonOperator op
) const {
    return _employeeQuery->findBySalary(salary, op);
}
