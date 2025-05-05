#include "Department.h"

Department::Department(
    std::unique_ptr<DepartmentInfo> info,
    std::vector<std::unique_ptr<Employee>>& staffs
) {
    _info = std::move(info);
    _staffs.insert(
        _staffs.end(),
        std::make_move_iterator(staffs.begin()),
        std::make_move_iterator(staffs.end())
    );
    staffs.clear();
}

const DepartmentInfo* Department::info() const {
    return _info.get();
}

std::vector<std::unique_ptr<Employee>>& Department::staffs() {
    return _staffs;
}

const Doctor* Department::getHeadDoctor() const {
    return _info->headDoctor();
}

void Department::assignHead(Doctor* doctor) {
    _info->setHead(doctor);
}
