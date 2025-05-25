#ifndef TXT_EMPLOYEE_REPOSITORY_H
#define TXT_EMPLOYEE_REPOSITORY_H

#include "../interfaces/IEmployeeRepository.h"

class TxtEmployeeRepository : public IEmployeeRepository {
private:
    std::vector<std::unique_ptr<Employee>> _employees;
    std::string _filePath;
    char _delim;

public:
    TxtEmployeeRepository();
    TxtEmployeeRepository(const std::string& filePath, char delim = '|');

public:
    std::string filePath() const;
    char delim() const;
    void setFilePath(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Employee> employee) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids) override;
    void update(const Employee& employee) override;
    std::vector<const Employee*> data() const override;
};

#endif // !TXT_EMPLOYEE_REPOSITORY_H
