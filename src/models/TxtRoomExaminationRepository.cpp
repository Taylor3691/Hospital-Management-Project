#include "TxtRoomExaminationRepository.h"

TxtRoomExaminationRepository::TxtRoomExaminationRepository() : _fileName("tests.txt"), _delim('|') {}

TxtRoomExaminationRepository::TxtRoomExaminationRepository(const std::string& filePath, char delim) : _fileName(filePath), _delim(delim) {
}

const std::string& TxtRoomExaminationRepository::fileName() const {
    return _fileName;
}

void TxtRoomExaminationRepository::setFileName(const std::string& filePath) {
    _fileName = filePath;
}

char TxtRoomExaminationRepository::delim() const {
    return _delim;
}

void TxtRoomExaminationRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtRoomExaminationRepository::save() const {
    ::save(_rooms, _delim, _fileName);
}

void TxtRoomExaminationRepository::load() {
    _rooms.clear();
    ::load(_rooms, _delim, _fileName);
}

void TxtRoomExaminationRepository::add(std::unique_ptr<RoomExamination> patient) {
    _rooms.push_back(std::move(patient));
    save();
}

void TxtRoomExaminationRepository::removeById(const std::string& id) {
    from(_rooms).where(&RoomExamination::id, id).deleteOne();
    save();
}

void TxtRoomExaminationRepository::update(const RoomExamination& patient) {
    auto ptr = from(_rooms)
        .where(&RoomExamination::id, patient.id()).findOne();
    if (ptr) {
        *ptr = patient;
    }
    else {
        throw std::runtime_error("RoomExamination not found");
    }
    save();
}

std::vector<const RoomExamination*> TxtRoomExaminationRepository::data() const {
    std::vector<const RoomExamination*> result;
    for (const auto& patient : _rooms) {
        result.push_back(patient.get());
    }
    return result;
}
