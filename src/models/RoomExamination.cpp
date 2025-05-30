#include "RoomExamination.h"

RoomExamination::RoomExamination()
    : _examinationFee() {}

RoomExamination::RoomExamination(
    const std::string& id,
    const std::string& name,
    const std::string& departmentId,
    double examinationFee
)
    : Object(id, name)
    , _departmentId(departmentId)
    , _examinationFee(examinationFee) {}

std::string RoomExamination::departmentId() const {
    return _departmentId;
}

std::vector<std::string> RoomExamination::waitingList() const {
    return _waitingList;
}

double RoomExamination::examinationFee() const {
    return _examinationFee;
}

void RoomExamination::setDepartmentId(const std::string& id) {
    _departmentId = id;
}

void RoomExamination::setWaitingList(std::vector<std::string> list) {
    _waitingList = list;
}

void RoomExamination::setRoomFee(double fee) {
    _examinationFee = fee;
}

void RoomExamination::addToWaitingList(const std::string& id) {
    _waitingList.push_back(id);
}

void RoomExamination::removeFromWaitingList(const std::string& id) {
    auto it = std::find(_waitingList.begin(), _waitingList.end(), id);
    if (it != _waitingList.end()) {
        _waitingList.erase(it);
    }
}

int RoomExamination::waitingListCount() const {
    return static_cast<int>(_waitingList.size());
}

void RoomExamination::acceptWrite(IVisitor* visitor, std::ostream& os) {
    (dynamic_cast<IWritingVisitor*>(visitor))->write(this, os);
}

Object* RoomExamination::clone() const {
    return new RoomExamination(*this);
}
