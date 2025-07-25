#include "TxtRoomExaminationRepository.h"

TxtRoomExaminationRepository::TxtRoomExaminationRepository()
    : _filePath("rooms.txt"), _delim('|')
{
    load();
}

TxtRoomExaminationRepository::TxtRoomExaminationRepository(
    const std::string& filePath,
    char delim
)
    : _filePath(filePath), _delim(delim)
{
    load();
}

const std::string& TxtRoomExaminationRepository::filePath() const {
    return _filePath;
}

void TxtRoomExaminationRepository::setFilePath(const std::string& filePath) {
    _filePath = filePath;
}

char TxtRoomExaminationRepository::delim() const {
    return _delim;
}

void TxtRoomExaminationRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtRoomExaminationRepository::save() const {
    ::save(_rooms, _delim, _filePath);
}

void TxtRoomExaminationRepository::load() {
    _rooms.clear();
    ::load(_rooms, _delim, _filePath);
}

void TxtRoomExaminationRepository::add(std::unique_ptr<RoomExamination> patient) {
    _rooms.push_back(std::move(patient));
    save();
}

void TxtRoomExaminationRepository::removeById(const std::string& id) {
    from(_rooms).where(&RoomExamination::id, id).deleteOne();
    save();
}

void TxtRoomExaminationRepository::removeByIds(const std::vector<std::string>& ids) {
    auto query = from(_rooms, FilterMode::OR);
    for (const auto& id : ids) {
        query.where(&RoomExamination::id, id);
    }
    query.deleteMany();
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
