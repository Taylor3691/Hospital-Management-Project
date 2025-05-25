#include "TxtMedicalRecordRepository.h"

TxtMedicalRecordRepository::TxtMedicalRecordRepository() : _fileName("records.txt"), _delim('|') {}

TxtMedicalRecordRepository::TxtMedicalRecordRepository(const std::string& fileName, char delim)
{
    _fileName = fileName;
    _delim = delim;
}

const std::string& TxtMedicalRecordRepository::fileName() const {
    return _fileName;
}

void TxtMedicalRecordRepository::setFileName(const std::string& filePath) {
    _fileName = filePath;
}

char TxtMedicalRecordRepository::delim() const {
    return _delim;
}

void TxtMedicalRecordRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtMedicalRecordRepository::save() const {
    ::save(_records, _delim, _fileName);
}

void TxtMedicalRecordRepository::load() {
    _records.clear();
    ::load(_records, _delim, _fileName);
}

void TxtMedicalRecordRepository::add(std::unique_ptr<MedicalRecord> record) {
    _records.push_back(std::move(record));
    save();
}

void TxtMedicalRecordRepository::removeById(const std::string& id) {
    from(_records).where(&MedicalRecord::id, id).deleteOne();
    save();
}

void TxtMedicalRecordRepository::update(const MedicalRecord& record) {
    auto ptr = from(_records)
        .where(&MedicalRecord::id, record.id()).findOne();
    if (ptr) {
        *ptr = record;
    }
    else {
        throw std::runtime_error("MedicalRecord not found");
    }
    save();
}

std::vector<const MedicalRecord*> TxtMedicalRecordRepository::data() const {
    std::vector<const MedicalRecord*> result;
    for (const auto& record : _records) {
        result.push_back(record.get());
    }
    return result;
}
