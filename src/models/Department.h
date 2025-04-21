#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include "Room.h"  

class Department {
private:
    std::string departmentId;
    std::string name;
    std::string location;
public:
    Department(std::string id, std::string n, std::string loc)
        : departmentId(id), name(n), location(loc) {}

    void displayInfo() {
        std::cout << "Department ID: " << departmentId << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Location: " << location << std::endl;
    }
};

#endif
