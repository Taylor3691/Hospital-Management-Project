#ifndef TXT_ROOM_EXAMINATION_H
#define TXT_ROOM_EXAMINATION_H

#include "../interfaces/IRoomExaminationRepository.h"

class TxtRoomExaminationRepository : public IRoomExaminationRepository {
private:
    std::string _filePath;
    std::vector<std::unique_ptr<RoomExamination>> _rooms;
    char _delim;

public:
    TxtRoomExaminationRepository();
    TxtRoomExaminationRepository(const std::string& filePath, char delim = '|');

public:
    const std::string& filePath() const;
    char delim() const;
    void setFilePath(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<RoomExamination> entity) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids) override;
    void update(const RoomExamination& entity) override;
    std::vector<const RoomExamination*> data() const override;
};

#endif // !TXT_ROOM_EXAMINATION_H
