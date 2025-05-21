#ifndef TXT_DEPARTMENT_REPOSITORY_H
#define TXT_DEPARTMENT_REPOSITORY_H

#include "../interfaces/IDepartmentRepository.h"
#include "../utils/QueryBuilder.h"
#include "../utils/utils_template.h"

class TxtDepartmentRepository : public IDepartmentRepository {
private:
    std::vector<std::unique_ptr<Department>> _departments;
    std::string _fileName;
    char _delim;

public:
    TxtDepartmentRepository();
    TxtDepartmentRepository(const std::string& fileName, char delim = '|');
public:
    std::string fileName() const;
    char delim() const;
    void setFileName(const std::string& fileName);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Department> department) override;
    void removeById(const std::string& id) override;
    void update(const Department& department) override;
    std::vector<const Department*> data() const override;
};

#endif // !TXT_DEPARTMENT_REPOSITORY_H
