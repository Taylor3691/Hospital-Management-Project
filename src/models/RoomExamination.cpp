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

void RoomExamination::addToWaitingQueue(const std::string& id) {
    _waitingQueue.push(id);
}

void RoomExamination::removeFromWaitingQueue() {
    _waitingQueue.pop();
}

int RoomExamination::getQueueCount() const {
    return _waitingQueue.size();
}
