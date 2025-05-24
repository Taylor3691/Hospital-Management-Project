#ifndef DEPARTMENT_MANAGER_H
#define DEPARTMENT_MANAGER_H

#include "../interfaces/IManager.h"
#include "../interfaces/IDepartmentRepository.h"
#include "../utils/QueryBuilder.h"

class DepartmentManager : public IManager<Department> {
private:
    IDepartmentRepository* _repo;

public:
    DepartmentManager(IDepartmentRepository* repo);

public:
    void add(std::unique_ptr<Department> department) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids);
    void update(const Department& department) override;
    std::vector<const Department*> find(const std::vector<RFilter<Department>>& filters) const override;
    std::vector<const Department*> getAll() const override;
};

#endif // !DEPARTMENT_MANAGER_H
