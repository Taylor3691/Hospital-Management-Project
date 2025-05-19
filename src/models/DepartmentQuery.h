#ifndef DEPARTMENT_QUERY_H
#define DEPARTMENT_QUERY_H

#include <typeinfo>
#include "../interfaces/IQuery.h"
#include "../interfaces/IDepartmentRepository.h"
#include "../utils/QueryBuilder.h"

class DepartmentQuery : public IQuery<Department> {
private:
    IDepartmentRepository* _repo;

public:
    DepartmentQuery(IDepartmentRepository* repo);

public:
    const Department* findById(const std::string& id) const override;
    std::vector<const Department*> findAll() const override;
    std::vector<const Department*> findByName(const std::string& name) const;
    std::vector<const Department*> findByFoundationDate(const Date& date) const;
};

#endif // !DEPARTMENT_QUERY_H
