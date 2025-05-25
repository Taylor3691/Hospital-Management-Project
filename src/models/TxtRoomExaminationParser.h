#ifndef TXTROOMEXAMINATIONPARSER_H_
#define TXTROOMEXAMINATIONPARSER_H_

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

#endif // !TXTROOMEXAMINATIONPARSER_H_
