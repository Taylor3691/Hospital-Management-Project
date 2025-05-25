#include "TxtDoctorParser.h"
#include "TxtPatientRepository.h"
#include <filesystem>

int main() {
    std::string room = "PHG-001|Khám Da Liễu|DEPT-001|HS-001,HS-002,HS-003|35000.00";
    IParser* parse = new TxtRoomExaminationParser('|');
    std::stringstream os;
    RoomExamination* sample = dynamic_cast<RoomExamination*>(parse->parse(room));
    IWritingVisitor* visitor = new TxtWritingVisitor('|');
    sample->acceptWrite(visitor, os);

}
