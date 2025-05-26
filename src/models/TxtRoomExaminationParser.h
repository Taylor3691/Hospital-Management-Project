#ifndef TXT_ROOM_EXAMINATION_PARSER_H
#define TXT_ROOM_EXAMINATION_PARSER_H

#include <sstream>
#include "RoomExaminationParser.h"
#include "RoomExamination.h"

class TxtRoomExaminationParser : public RoomExaminationParser {
private:
    char _delim;

public:
    TxtRoomExaminationParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_ROOM_EXAMINATION_PARSER_H
