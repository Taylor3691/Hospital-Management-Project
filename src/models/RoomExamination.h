#ifndef ROOM_EXAMINATION_H
#define ROOM_EXAMINATION_H

#include <queue>
#include "Object.h"
#include "TxtWritingVisitor.h"

class RoomExamination : public Object {
private:
    std::string _departmentId;
    std::queue<std::string> _waitingQueue;
    double _examinationFee;

public:
    RoomExamination();
    RoomExamination(const std::string& id, const std::string& name,
        const std::string& departmentId, double examinationFee);

public:
    std::string departmentId() const;
    std::vector<std::string> waitingQueue() const;
    double examinationFee() const;
    void setDepartmentId(const std::string& id);
    void setWaitingQueue(std::vector<std::string> queue);
    void setRoomFee(double fee);

public:
    void addToWaitingQueue(const std::string& id);
    void removeFromWaitingQueue();
    int getQueueCount() const;
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;
};

#endif // !ROOM_EXAMINATION_H
