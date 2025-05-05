#include "DepartmentInfo.h"

DepartmentInfo::DepartmentInfo(
    const std::string& id,
    const std::string& name,
    const std::string& location,
    const std::string& requiredSpecialty,
    int maxStaff,
    Doctor* doctor
) {
    _id = id;
    _name = name;
    _location = location;
    _requiredSpecialty = requiredSpecialty;
    _maxStaff = maxStaff;
    _headDoctor = doctor;
}

std::string DepartmentInfo::id() const {
    return _id;
}

std::string DepartmentInfo::name() const {
    return _name;
}

std::string DepartmentInfo::location() const {
    return _location;
}

std::string DepartmentInfo::requiredSpecialty() const {
    return _requiredSpecialty;
}

int DepartmentInfo::maxStaff() const {
    return _maxStaff;
}

const Doctor* DepartmentInfo::headDoctor() const {
    return _headDoctor;
}

void DepartmentInfo::setHead(Doctor* doctor) {
    _headDoctor = doctor;
}
