#include "EmployeeQuery.h"

const Employee* EmployeeQuery::findById(const std::string& id) const {
    auto employees = _repo->employees();
    return from(employees).where(&Employee::id, id).findOne();
}

std::vector<const Employee*> EmployeeQuery::findAll() const {
    auto employees = _repo->employees();
    return from(employees).find();
}

std::vector<const Employee*> EmployeeQuery::findByName(
    const std::string& name
) const {
    auto employees = _repo->employees();
    return from(employees).where(&Employee::name, name).find();
}

std::vector<const Employee*> EmployeeQuery::findByEducation(
    const std::string& education
) const {
    auto employees = _repo->employees();
    return from(employees).where(&Employee::education, education).find();
}

std::vector<const Employee*> EmployeeQuery::findByType(
    const std::string& type
) const {
    auto employees = _repo->employees();
    return from(employees)
        .where([](const auto& e) { return std::string(typeid(e).name()); }, type)
        .find();
}

std::vector<const Employee*> EmployeeQuery::findBySalary(
    double salary, ComparisonOperator op
    ComparisonOperator op
) const {
    auto employees = _repo->employees();
    return from(employees).where(&Employee::baseSalary, salary, op).find();
}
