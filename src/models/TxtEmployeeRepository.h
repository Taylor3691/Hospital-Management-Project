#ifndef TXTEMPLOYEEREPOSITORY_H
#define TXTEMPLOYEEREPOSITORY_H

#include <fstream>
#include "../interfaces/IEmployeeRepository.h"
#include "../utils/QueryBuilder.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Receptionist.h"

class TxtEmployeeRepository : public IEmployeeRepository {
private:
    std::string _doctorFile;
    std::string _nurseFile;
    std::string _receptionistFile;
    std::vector<std::unique_ptr<Employee>> _employees;

public:
    TxtEmployeeRepository();
    TxtEmployeeRepository(const std::string& doctorFile,
        const std::string& nurseFile, const std::string& receptionistFile);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Employee> employee) override;
    void removeById(const std::string& id) override;
    void update(const Employee& employee) override;
    std::vector<const Employee*> employees() const override;
};

#endif // !TXTEMPLOYEEREPOSITORY_H
