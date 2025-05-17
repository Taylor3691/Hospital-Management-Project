// DepartmentQuery.cpp
#include "DepartmentQuery.h"
#include <algorithm>

DepartmentQuery::DepartmentQuery(IDepartmentRepository* repo) : _repo(repo) {}

std::vector<Department*> DepartmentQuery::findByName(const std::string& name) {
    auto condition = [&name](Department* dept) {
        return dept->name().find(name) != std::string::npos;
    };
    return buildQuery(_repo->findAll(), condition); // Sử dụng QueryBuild.h
}

std::vector<Department*> DepartmentQuery::findByFoundedDate(const std::tm& date) {
    auto condition = [&date](Department* dept) {
        std::tm deptDate = dept->getFoundedDay();
        return deptDate.tm_year == date.tm_year &&
               deptDate.tm_mon == date.tm_mon &&
               deptDate.tm_mday == date.tm_mday;
    };
    return buildQuery(_repo->findAll(), condition); // Sử dụng QueryBuild.h
}