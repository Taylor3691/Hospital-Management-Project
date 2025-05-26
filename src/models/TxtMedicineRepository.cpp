#include "TxtMedicineRepository.h"

TxtMedicineRepository::TxtMedicineRepository()
    : _fileName("medicines.txt")
    , _delim('|'){}

TxtMedicineRepository::TxtMedicineRepository(const std::string& filename, char delim)
    : _fileName(filename)
    , _delim(delim) {}

const std::string& TxtMedicineRepository::fileName() const {
    return _fileName;
}

char TxtMedicineRepository::delim() const {
    return _delim;
}

void TxtMedicineRepository::setFilename(const std::string& filename) {
    _fileName = filename;
}

void TxtMedicineRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtMedicineRepository::load() {
    _medicines.clear();
    ::load(_medicines, _delim, _fileName);
}

void TxtMedicineRepository::save() const {
    ::save(_medicines, _delim, _fileName);
}

void TxtMedicineRepository::add(std::unique_ptr<Medicine> medicine) {
    _medicines.push_back(std::move(medicine));
    save();
}

void TxtMedicineRepository::removeById(const std::string& id) {
    from(_medicines).where(&Medicine::id, id).deleteOne();
    save();
}

void TxtMedicineRepository::removeByIds(const std::vector<std::string>& ids) {
    auto query = from(_medicines, FilterMode::OR);
    for (const auto& id : ids) {
        query.where(&Medicine::id, id);
    }
    query.deleteMany();
    save();
}

void TxtMedicineRepository::update(const Medicine& medicine) {
    auto ptr = from(_medicines)
        .where(&Medicine::id, medicine.id()).findOne();
    if (ptr) {
        *ptr = medicine;
    }
    save();
}

std::vector<const Medicine*> TxtMedicineRepository::data() const {
    std::vector<const Medicine*> result;
    for (const auto& medicine : _medicines) {
        result.push_back(medicine.get());
    }
    return result;
}


