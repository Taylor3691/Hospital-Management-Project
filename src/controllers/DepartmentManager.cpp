#include "DepartmentManager.h"

DepartmentManager::DepartmentManager(IDepartmentRepository* repo)
    : _repo(repo) {
}

void DepartmentManager::add(std::unique_ptr<Department> department) {
    _repo->add(std::move(department));
}

void DepartmentManager::removeById(const std::string& id) {
    _repo->removeById(id);
}

void DepartmentManager::removeByIds(const std::vector<std::string>& ids) {
    _repo->removeByIds(ids);
}

void DepartmentManager::update(const Department& department) {
    _repo->update(department);
}

std::vector<const Department*> DepartmentManager::find(
    const std::vector<RFilter<Department>>& filters
) const {
    auto departments = _repo->data();
    auto query = from(departments);
    for (const auto& [criteria, getter] : filters) {
        query.where(getter, criteria.value, criteria.op);
    }
    return query.find();
}

std::vector<const Department*> DepartmentManager::getAll() const {
    return _repo->data();
}


