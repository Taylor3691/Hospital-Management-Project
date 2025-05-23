#include "EmployeeManager.h"

EmployeeManager::EmployeeManager(IEmployeeRepository* repo)
    : _repo(repo) {}

void EmployeeManager::add(std::unique_ptr<Employee> employee) {
    _repo->add(std::move(employee));
}

void EmployeeManager::removeById(const std::string& id) {
    _repo->removeById(id);
}

void EmployeeManager::removeByIds(const std::vector<std::string>& ids) {
    _repo->removeByIds(ids);
}

void EmployeeManager::update(const Employee& employee) {
    _repo->update(employee);
}

std::vector<const Employee*> EmployeeManager::find(
    const std::vector<RFilter<Employee>>& filters
) const {
    auto employees = _repo->data();
    auto query = from(employees);
    for (const auto& [criteria, getter] : filters) {
        query.where(getter, criteria.value, criteria.op);
    }
    return query.find();
}

std::vector<const Employee*> EmployeeManager::getAll() const {
    return _repo->data();
}
