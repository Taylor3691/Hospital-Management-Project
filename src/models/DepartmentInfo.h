#ifndef DEPARTMENTINFO_H
#define DEPARTMENTINFO_H

#include <string>
#include "Doctor.h"

class DepartmentInfo {
private:
    std::string _id;
    std::string _name;
    std::string _location;
    std::string _requiredSpecialty;
    int _maxStaff;
    Doctor* _headDoctor;

public:
    DepartmentInfo(const std::string& id, const std::string& name, const std::string& location,
        const std::string& requiredSpecialty, int maxStaff, Doctor* doctor);

public:
    std::string id() const;
    std::string name() const;
    std::string location() const;
    std::string requiredSpecialty() const;
    int maxStaff() const;
    const Doctor* headDoctor() const;

public:
    void setHead(Doctor* doctor);
};

#endif
