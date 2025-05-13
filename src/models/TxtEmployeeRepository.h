#ifndef TXTEMPLOYEEREPOSITORY_H
#define TXTEMPLOYEEREPOSITORY_H

#include <fstream>
#include <typeinfo>
#include "../interfaces/IEmployeeRepository.h"
#include "../utils/QueryBuilder.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Receptionist.h"

#define DEFAULT_DELIM '|'

class TxtEmployeeRepository : public IEmployeeRepository {
private:
    std::string _doctorFile;
    std::string _nurseFile;
    std::string _receptionistFile;
    std::vector<std::unique_ptr<Employee>> _employees;
    char _delim;

public:
    TxtEmployeeRepository();
    TxtEmployeeRepository(const std::string& doctorFile, const std::string& nurseFile,
        const std::string& receptionistFile, char delim = DEFAULT_DELIM);

private:
    static void serialize(std::ofstream& file, const Employee* employee);
    static void serialize(std::ofstream& file, const Doctor* doctor);
    static void serialize(std::ofstream& file, const Nurse* nurse);
    static void serialize(std::ofstream& file, const Receptionist* receptionist);
    static void deserialize(std::ifstream& file, Employee* employee, std::string& buffer);
    static void deserialize(std::ifstream& file, Doctor* doctor, std::string& buffer);
    static void deserialize(std::ifstream& file, Nurse* nurse, std::string& buffer);
    static void deserialize(std::ifstream& file, Receptionist* receptionist, std::string& buffer);

private:
    template<typename T>
    void load(const std::string& fileName, const char* errorMsg);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Employee> employee) override;
    void removeById(const std::string& id) override;
    void update(const Employee& employee) override;
    std::vector<const Employee*> data() const override;
};

#endif // !TXTEMPLOYEEREPOSITORY_H

template<typename T>
inline void TxtEmployeeRepository::load(const std::string& fileName, const char* errorMsg) {
    std::string buffer;

    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error(errorMsg);
    }

    while (std::getline(file, buffer, _delim)) {
        auto employee = std::make_unique<T>();
        deserialize(file, employee.get(), buffer);
        _employees.push_back(std::move(employee));
    }
    file.close();
}
