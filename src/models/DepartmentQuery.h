// DepartmentQuery.h
#ifndef DEPARTMENT_QUERY_H
#define DEPARTMENT_QUERY_H
#include "IQuery.h" // Giả định IQuery được định nghĩa
#include "IDepartmentRepository.h"
#include <vector>
#include <string>
#include "QueryBuild.h" // Giả định QueryBuild.h cung cấp hàm buildQuery

class DepartmentQuery : public IQuery<Department> {
public:
    DepartmentQuery(IDepartmentRepository* repo);
    std::vector<Department*> findByName(const std::string& name);
    std::vector<Department*> findByFoundedDate(const std::tm& date);
    ~DepartmentQuery() = default;

private:
    IDepartmentRepository* _repo;
};

#endif