#include "DepartmentStaffManager.h"

DepartmentStaffManager* DepartmentStaffManager::getInstance() {
    static std::unique_ptr<DepartmentStaffManager, void(*)(DepartmentStaffManager*)> instance(
        new DepartmentStaffManager(),
        [](DepartmentStaffManager* ptr) { delete ptr; }
    );
    return instance.get();
}

void DepartmentStaffManager::add(Department* department, std::unique_ptr<Employee> staff) {  
   if (department->staffs().size() >= department->info()->maxStaff()) {  
        throw std::runtime_error("Maximum staff limit reached.");
    }
   this->Manager<Employee>::add(department->staffs(), std::move(staff));  
}
