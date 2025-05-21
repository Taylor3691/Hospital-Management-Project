#include "TxtDepartmentRepository.h"

TxtDepartmentRepository::TxtDepartmentRepository()
    : _fileName("departments.txt"), _delim('|') {
}

TxtDepartmentRepository::TxtDepartmentRepository(
    const std::string& fileName,
    char delim
)
    : _fileName(fileName), _delim(delim) {
}

std::string TxtDepartmentRepository::fileName() const {
    return _fileName;
}

char TxtDepartmentRepository::delim() const {
    return _delim;
}

void TxtDepartmentRepository::setFileName(const std::string& fileName) {
    _fileName = fileName;
}

void TxtDepartmentRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtDepartmentRepository::load() {
    _departments.clear();
    ::load(_departments, _delim, _fileName);
}

void TxtDepartmentRepository::save() const {
    ::save(_departments, _delim, _fileName);
}

void TxtDepartmentRepository::add(std::unique_ptr<Department> department) {
    _departments.push_back(std::move(department));
    save();
}

void TxtDepartmentRepository::removeById(const std::string& id) {
    from(_departments).where(&Department::id, id).deleteOne();
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

