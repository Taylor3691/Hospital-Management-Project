// TxtDepartmentRepository.h
#ifndef TXT_DEPARTMENT_REPOSITORY_H
#define TXT_DEPARTMENT_REPOSITORY_H
#include "IDepartmentRepository.h"
#include <vector>
#include <string>

class TxtDepartmentRepository : public IDepartmentRepository {
public:
    TxtDepartmentRepository();
    TxtDepartmentRepository(const std::string& fileName);

    void add(Department* department) override;
    void remove(const std::string& id) override;
    Department* find(const std::string& id) override;
    std::vector<Department*> findAll() override;
    void save() override;
    void load() override;

    ~TxtDepartmentRepository();

private:
    std::string _fileName;
    std::vector<Department*> _departments;

    // Hàm phụ trợ
    std::tm parseDate(const std::string& dateStr);
    std::string formatDate(const std::tm& date);
};

#endif