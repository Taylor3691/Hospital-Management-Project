#ifndef TXTROOMEXAMINATION_H_
#define TXTROOMEXAMINATION_H_

#include "../interfaces/IRoomExaminationRepository.h"

class TxtRoomExaminationRepository : public IRoomExaminationRepository {
private:
    std::string _fileName;
    std::vector<std::unique_ptr<RoomExamination>> _rooms;
    char _delim;

public:
    TxtRoomExaminationRepository();
    TxtRoomExaminationRepository(const std::string& filePath, char delim = '|');

public:
    const std::string& fileName() const;
    char delim() const;
    void setFileName(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<RoomExamination> entity) override;
    void removeById(const std::string& id) override;
    void update(const RoomExamination& entity) override;
    std::vector<const RoomExamination*> data() const override;
};


#endif // !TXTROOMEXAMINATION_H_
