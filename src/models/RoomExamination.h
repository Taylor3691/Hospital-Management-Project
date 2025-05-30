#ifndef ROOM_EXAMINATION_H
#define ROOM_EXAMINATION_H

#include <algorithm>
#include <vector>
#include "Object.h"
#include "TxtWritingVisitor.h"

class RoomExamination : public Object {
private:
    std::string _departmentId;
    std::vector<std::string> _waitingList;
    double _examinationFee;

public:
    RoomExamination();
    RoomExamination(const std::string& id, const std::string& name,
        const std::string& departmentId, double examinationFee);

public:
    std::string departmentId() const;
    std::vector<std::string> waitingList() const;
    double examinationFee() const;
    void setDepartmentId(const std::string& id);
    void setWaitingList(std::vector<std::string> list);
    void setRoomFee(double fee);

public:
    void addToWaitingList(const std::string& id);
    void removeFromWaitingList(const std::string& id);
    int waitingListCount() const;
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;
};

#endif // !ROOM_EXAMINATION_H
