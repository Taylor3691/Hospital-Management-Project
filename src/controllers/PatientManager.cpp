#include "PatientManager.h"

PatientManager::PatientManager(IPatientRepository* repo)
    : _repo(repo) {
}

void PatientManager::add(std::unique_ptr<Patient> patient) {
    _repo->add(std::move(patient));
}

void PatientManager::removeById(const std::string& id) {
    _repo->removeById(id);
}

void PatientManager::removeByIds(const std::vector<std::string>& ids) {
    _repo->removeByIds(ids);
}

void PatientManager::update(const Patient& patient) {
    _repo->update(patient);
}

std::vector<const Patient*> PatientManager::find(
    const std::vector<RFilter<Patient>>& filters
) const {
    auto patients = _repo->data();
    auto query = from(patients);
    for (const auto& [criteria, getter] : filters) {
        query.where(getter, criteria.value, criteria.op);
    }
    return query.find();
}

std::vector<const Patient*> PatientManager::getAll() const {
    return _repo->data();
}
