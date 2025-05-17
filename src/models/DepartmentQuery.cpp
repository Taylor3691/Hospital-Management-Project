#include "DepartmentQuery.h"

DepartmentQuery::DepartmentQuery(IDepartmentRepository* repo)
    : _repo(repo) {}

const Department* DepartmentQuery::findById(const std::string& id) const {
    auto employees = _repo->data();
    return from(employees).where(&Department::id, id).findOne();
}

std::vector<const Department*> DepartmentQuery::findAll() const {
    auto employees = _repo->data();
    return from(employees).find();
}

std::vector<const Department*> DepartmentQuery::findByName(
    const std::string& name
) const {
    auto employees = _repo->data();
    return from(employees).where(&Department::name, name).find();
}

std::vector<const Department*> DepartmentQuery::findByFoundationDate(
    const Date& date
) const {
    auto employees = _repo->data();
    return from(employees).where(&Department::foundationDate, date).find();
}
