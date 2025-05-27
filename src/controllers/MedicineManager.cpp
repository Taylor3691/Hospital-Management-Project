#include "MedicineManager.h"

MedicineManager::MedicineManager(IMedicineRepository* repo) {
    _repo = repo;
}

void MedicineManager::add(std::unique_ptr<Medicine> medicine) {
    _repo->add(std::move(medicine));
}

void MedicineManager::removeById(const std::string& id) {
    _repo->removeById(id);
}

void MedicineManager::removeByIds(const std::vector<std::string>& ids) {
    _repo->removeByIds(ids);
}

void MedicineManager::update(const Medicine& medicine) {
    _repo->update(medicine);
}

std::vector<const Medicine*> MedicineManager::find(
    const std::vector<RFilter<Medicine>>& filters
) const {
    auto medicines = _repo->data();
    auto query = from(medicines);
    for (const auto& [criteria, getter] : filters) {
        query.where(getter, criteria.value, criteria.op);
    }
    return query.find();
}

std::vector<const Medicine*> MedicineManager::getAll() const {
    return _repo->data();
}
