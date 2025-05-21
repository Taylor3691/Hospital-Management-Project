#ifndef TXT_EMPLOYEE_REPOSITORY_H
#define TXT_EMPLOYEE_REPOSITORY_H

#include "../interfaces/IEmployeeRepository.h"
#include "../utils/QueryBuilder.h"
#include "../utils/utils_template.h"

class TxtEmployeeRepository : public IEmployeeRepository {
private:
    std::vector<std::unique_ptr<Employee>> _employees;
    std::string _fileName;
    char _delim;

public:
    TxtEmployeeRepository();
    TxtEmployeeRepository(const std::string& fileName, char delim = '|');

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Employee> employee) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids);
    void update(const Employee& employee) override;
    std::vector<const Employee*> data() const override;
};

#endif // !TXT_EMPLOYEE_REPOSITORY_H
