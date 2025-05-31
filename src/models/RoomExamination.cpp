#include "RoomExamination.h"

RoomExamination::RoomExamination()
    : _waitingCount(), _examinationFee() {}

RoomExamination::RoomExamination(
    const std::string& id,
    const std::string& name,
    const std::string& departmentId,
    double examinationFee
)
    : Object(id, name)
    , _departmentId(departmentId)
    , _waitingCount()
    , _examinationFee(examinationFee) {}

std::string RoomExamination::departmentId() const {
    return _departmentId;
}

int RoomExamination::waitingCount() const {
    return _waitingCount;
}

double RoomExamination::examinationFee() const {
    return _examinationFee;
}

void RoomExamination::setDepartmentId(const std::string& id) {
    _departmentId = id;
}

void RoomExamination::setWaitingCount(int count) {
    _waitingCount = count;
}

void RoomExamination::setRoomFee(double fee) {
    _examinationFee = fee;
}

void RoomExamination::addToWaitingList() {
    ++_waitingCount;
}

void RoomExamination::removeFromWaitingList() {
    --_waitingCount;
}

void RoomExamination::acceptWrite(IVisitor* visitor, std::ostream& os) {
    (dynamic_cast<IWritingVisitor*>(visitor))->write(this, os);
}

Object* RoomExamination::clone() const {
    return new RoomExamination(*this);
}
