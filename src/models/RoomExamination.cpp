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

std::vector<std::string> RoomExamination::waitingQueue() const {
    std::vector<std::string> waitingQueue;
    std::queue<std::string> copy = _waitingQueue;
    while (!copy.empty()) {
        waitingQueue.push_back(copy.front());
        copy.pop();
    }
    return waitingQueue;
}

double RoomExamination::examinationFee() const {
    return _examinationFee;
}

void RoomExamination::setDepartmentId(const std::string& id) {
    _departmentId = id;
}

void RoomExamination::setWaitingQueue(std::vector<std::string> queue) {
    while (!_waitingQueue.empty()) {
        _waitingQueue.pop();
    }

    for (auto room : queue) {
        _waitingQueue.push(room);
    }
}

void RoomExamination::setRoomFee(double fee) {
    _examinationFee = fee;
}

void RoomExamination::addToWaitingQueue(const std::string& id) {
    _waitingQueue.push(id);
}

void RoomExamination::removeFromWaitingQueue() {
    _waitingQueue.pop();
}

int RoomExamination::getQueueCount() const {
    return static_cast<int>(_waitingQueue.size());
}

void RoomExamination::acceptWrite(IVisitor* visitor, std::ostream& os) {
    (dynamic_cast<IWritingVisitor*>(visitor))->write(this, os);
}

Object* RoomExamination::clone() const {
    return nullptr;
}
