#include "TxtDepartmentRepository.h"

TxtDepartmentRepository::TxtDepartmentRepository()
    : _filePath("departments.txt"), _delim('|')
{
    load();
}

TxtDepartmentRepository::TxtDepartmentRepository(
    const std::string& filePath,
    char delim
)
    : _filePath(filePath), _delim(delim)
{
    load();
}

std::string TxtDepartmentRepository::filePath() const {
    return _filePath;
}

char TxtDepartmentRepository::delim() const {
    return _delim;
}

void TxtDepartmentRepository::setFilePath(const std::string& filePath) {
    _filePath = filePath;
}

void TxtDepartmentRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtDepartmentRepository::load() {
    _departments.clear();
    ::load(_departments, _delim, _filePath);
}

void TxtDepartmentRepository::save() const {
    ::save(_departments, _delim, _filePath);
}

void TxtDepartmentRepository::add(std::unique_ptr<Department> department) {
    _departments.push_back(std::move(department));
    save();
}

void TxtDepartmentRepository::removeById(const std::string& id) {
    from(_departments).where(&Department::id, id).deleteOne();
    save();
}

void TxtDepartmentRepository::removeByIds(const std::vector<std::string>& ids) {
    auto query = from(_departments, FilterMode::OR);
    for (const auto& id : ids) {
        query.where(&Department::id, id);
    }
    query.deleteMany();
    save();
}

void TxtDepartmentRepository::update(const Department& department) {
    auto ptr = from(_departments)
        .where(&Department::id, department.id()).findOne();
    if (ptr) {
        *ptr = department;
    }
    save();
}

std::vector<const Department*> TxtDepartmentRepository::data() const {
    std::vector<const Department*> result;
    result.reserve(_departments.size());
    for (const auto& department : _departments) {
        result.push_back(department.get());
    }
    return result;
}
