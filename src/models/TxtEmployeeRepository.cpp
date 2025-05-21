#include "TxtEmployeeRepository.h"

TxtEmployeeRepository::TxtEmployeeRepository()
    : _fileName("employees.txt"), _delim('|')
{
    ::load(_employees, _delim, _fileName);
}

TxtEmployeeRepository::TxtEmployeeRepository(
    const std::string& fileName,
    char delim
)
    : _fileName(fileName), _delim(delim)
{
    ::load(_employees, _delim, _fileName);
}

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
    //save();
}

void TxtEmployeeRepository::removeById(const std::string& id) {
    from(_employees).where(&Employee::id, id).deleteOne();
    //save();
}

void TxtEmployeeRepository::removeByIds(const std::vector<std::string>& ids) {
    auto query = from(_employees, FilterMode::OR);
    for (const auto& id : ids) {
        query.where(&Employee::id, id);
    }
    query.deleteMany();
    //save();
}

void TxtEmployeeRepository::update(const Employee& employee) {
    auto ptr = from(_employees)
        .where(&Employee::id, employee.id()).findOne();
    if (ptr) {
        if (auto doctorPtr = dynamic_cast<Doctor*>(ptr)) {
            *doctorPtr = dynamic_cast<const Doctor&>(employee);
        }
        else if (auto nursePtr = dynamic_cast<Nurse*>(ptr)) {
            *nursePtr = dynamic_cast<const Nurse&>(employee);
        }
        else if (auto receptionistPtr = dynamic_cast<Receptionist*>(ptr)) {
            *receptionistPtr = dynamic_cast<const Receptionist&>(employee);
        }
        else {
            *ptr = employee;
        }
    }
    //save();
}

std::vector<const Employee*> TxtEmployeeRepository::data() const {
    std::vector<const Employee*> result;
    result.reserve(_employees.size());
    for (const auto& employee : _employees) {
        result.push_back(employee.get());
    }
    return result;
}
