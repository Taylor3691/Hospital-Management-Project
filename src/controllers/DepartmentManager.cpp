#include "DepartmentManager.h"

DepartmentManager::DepartmentManager(IDepartmentRepository* repo)
    : _departmentRepo(repo)
    , _departmentQuery(new DepartmentQuery(repo)) {}

DepartmentManager::~DepartmentManager() {
    delete _departmentQuery;
}

void DepartmentManager::add(std::unique_ptr<Department> department) {
    _departmentRepo->add(std::move(department));
}

void DepartmentManager::removeById(const std::string& id) {
    _departmentRepo->removeById(id);
}

std::vector<const Department*> DepartmentManager::findAll() const {
    return _departmentQuery->findAll();
}

std::vector<const Department*> DepartmentManager::findByName(
    const std::string& name
) const {
    return _departmentQuery->findByName(name);
}
