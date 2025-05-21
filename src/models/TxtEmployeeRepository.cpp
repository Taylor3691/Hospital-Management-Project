#include "TxtEmployeeRepository.h"

TxtEmployeeRepository::TxtEmployeeRepository()
    : _fileName("employees.txt"), _delim('|') {}

TxtEmployeeRepository::TxtEmployeeRepository(
    const std::string& fileName,
    char delim
)
    : _fileName(fileName), _delim(delim) {}

const std::string& TxtEmployeeRepository::fileName() const {
    return _fileName;
}

char TxtEmployeeRepository::delim() const {
    return _delim;
}

void TxtEmployeeRepository::setFileName(const std::string& fileName) {
    _fileName = fileName;
}

void TxtEmployeeRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtEmployeeRepository::load() {
    _employees.clear();
    ::load(_employees, _delim, _fileName);
}

void TxtEmployeeRepository::save() const {
    ::save(_employees, _delim, _fileName);
}

void TxtEmployeeRepository::add(std::unique_ptr<Employee> employee) {
    _employees.push_back(std::move(employee));
    save();
}

void TxtEmployeeRepository::removeById(const std::string& id) {
    from(_employees).where(&Employee::id, id).deleteOne();
    save();
}

void TxtEmployeeRepository::update(const Employee& employee) {
    auto ptr = from(_employees)
        .where(&Employee::id, employee.id()).findOne();
    if (ptr) {
        *ptr = employee;
    }
    save();
}

std::vector<const Employee*> TxtEmployeeRepository::data() const {
    std::vector<const Employee*> result;
    result.reserve(_employees.size());
    for (const auto& employee : _employees) {
        result.push_back(employee.get());
    }
    return result;
}
