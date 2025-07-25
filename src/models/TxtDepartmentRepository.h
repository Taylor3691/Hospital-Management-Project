#ifndef TXT_DEPARTMENT_REPOSITORY_H
#define TXT_DEPARTMENT_REPOSITORY_H

#include "../interfaces/IDepartmentRepository.h"

class TxtDepartmentRepository : public IDepartmentRepository {
private:
    std::vector<std::unique_ptr<Department>> _departments;
    std::string _filePath;
    char _delim;

public:
    TxtDepartmentRepository();
    TxtDepartmentRepository(const std::string& filePath, char delim = '|');

public:
    std::string filePath() const;
    char delim() const;
    void setFilePath(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Department> department) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids) override;
    void update(const Department& department) override;
    std::vector<const Department*> data() const override;
};

#endif // !TXT_DEPARTMENT_REPOSITORY_H
