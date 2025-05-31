#ifndef EXAMINATION_STATE_H
#define EXAMINATION_STATE_H

#include <string>

class ExaminationState {
public:
    enum State {
        Waiting,
        Examining,
        TestPending,
        Completed,
        Paid,
    };

public:
    virtual ~ExaminationState() = default;

public:
    virtual State stateName() const = 0;
    virtual bool canPrescribeMedicine() const = 0;
    virtual bool canOrderClinicalTest() const = 0;
    virtual bool canComplete() const = 0;
    virtual ExaminationState* clone() const = 0;
};

#endif // !EXAMINATION_STATE_H
