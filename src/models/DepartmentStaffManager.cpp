#include "DepartmentStaffManager.h"

void DepartmentStaffManager::add(
    std::vector<std::unique_ptr<Employee>>& employees,
    std::unique_ptr<Employee> employee
) {
    if (employees.size() >= _maxStaff) {
        throw std::runtime_error("Maximum staff limit reached.");
    }
    Manager::add(employees, std::move(employee));
}
