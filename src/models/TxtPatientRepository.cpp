#include "TxtPatientRepository.h"

TxtPatientRepository::TxtPatientRepository()
    : _filePath("patients.txt"), _delim('|')
{
    load();
}

TxtPatientRepository::TxtPatientRepository(
    const std::string& filePath,
    char delim
)
    : _filePath(filePath), _delim(delim)
{
    load();
}

std::string TxtPatientRepository::filePath() const {
    return _filePath;
}

void TxtPatientRepository::setFilePath(const std::string& filePath) {
    _filePath = filePath;
}

char TxtPatientRepository::delim() const {
    return _delim;
}

void TxtPatientRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtPatientRepository::load() {
    _patients.clear();
    ::load(_patients, _delim, _filePath);
}

void TxtPatientRepository::save() const {
    ::save(_patients, _delim, _filePath);
}

void TxtPatientRepository::add(std::unique_ptr<Patient> patient) {
    _patients.push_back(std::move(patient));
    save();
}

void TxtPatientRepository::removeById(const std::string& id) {
    from(_patients).where(&Patient::id, id).deleteOne();
    save();
}

void TxtPatientRepository::removeByIds(const std::vector<std::string>& ids) {
    auto query = from(_patients, FilterMode::OR);
    for (const auto& id : ids) {
        query.where(&Patient::id, id);
    }
    query.deleteMany();
    save();
}

void TxtPatientRepository::update(const Patient& patient) {
    auto ptr = from(_patients)
        .where(&Patient::id, patient.id()).findOne();
    if (ptr) {
        *ptr = patient;
    }
    save();
}

std::vector<const Patient*> TxtPatientRepository::data() const {
    std::vector<const Patient*> result;
    result.reserve(_patients.size());
    for (const auto& patient : _patients) {
        result.push_back(patient.get());
    }
    return result;  
}
