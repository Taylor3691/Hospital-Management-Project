#include "TxtRoomExaminationParser.h"

TxtRoomExaminationParser::TxtRoomExaminationParser(char delim) {
    _delim = delim;
}

Object* TxtRoomExaminationParser::parse(const std::string& str) const {
    auto room = new RoomExamination();

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    room->setId(buffer);

    std::getline(stream, buffer, _delim);
    room->setName(buffer);

    std::getline(stream, buffer, _delim);
    room->setDepartmentId(buffer);

    std::getline(stream, buffer, _delim);
    room->setWaitingCount(stoi(buffer));

    std::getline(stream, buffer, _delim);
    room->setRoomFee(std::stod(buffer));

    return room;
}
