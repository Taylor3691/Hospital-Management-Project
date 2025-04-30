#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include "Room.h"  

class Department {
private:
    std::string _departmentId;
    std::string _name;

public:
    std::string id() const;
    std::string name() const;
};

#endif
