#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <iostream>

class Department {
private:
    std::string _departmentId;
    std::string _name;

public:
    Department(const std::string& id, const std::string& name)
        : _departmentId(id), _name(name) {}
    //~Department() { std::cout << "Department " << _departmentId << " is destroying\n"; }

public:
    std::string id() const { return _departmentId; }
    std::string name() const { return _name; }
};

#endif
