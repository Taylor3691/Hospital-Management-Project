// DepartmentManager.cpp
#include "DepartmentManager.h"

DepartmentManager::DepartmentManager(IDepartmentRepository* departmentRepo)
    : _departmentRepo(departmentRepo), _departmentQuery(new DepartmentQuery(departmentRepo)) {}

void DepartmentManager::addDepartment(Department* department) {
    _departmentRepo->add(department);
}

void DepartmentManager::removeDepartment(const std::string& id) {
    _departmentRepo->remove(id);
}

std::vector<Department*> DepartmentManager::findAll() {
    return _departmentRepo->findAll();
}

std::vector<Department*> DepartmentManager::findByName(const std::string& name) {
    return _departmentQuery->findByName(name);
}

DepartmentManager::~DepartmentManager() {
    delete _departmentQuery;
}