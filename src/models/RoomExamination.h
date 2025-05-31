#ifndef ROOM_EXAMINATION_H
#define ROOM_EXAMINATION_H

#include <algorithm>
#include <vector>
#include "Object.h"
#include "TxtWritingVisitor.h"

class RoomExamination : public Object {
private:
    std::string _departmentId;
    int _waitingCount;
    double _examinationFee;

public:
    RoomExamination();
    RoomExamination(const std::string& id, const std::string& name,
        const std::string& departmentId, double examinationFee);

public:
    std::string departmentId() const;
    int waitingCount() const;
    double examinationFee() const;
    void setDepartmentId(const std::string& id);
    void setWaitingCount(int count);
    void setRoomFee(double fee);

public:
    void addToWaitingList();
    void removeFromWaitingList();
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;
};

#endif // !ROOM_EXAMINATION_H
