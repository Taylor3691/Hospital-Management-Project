#ifndef WAITING_STATE_H
#define WAITING_STATE_H

#include "ExaminationState.h"

class WaitingState : public ExaminationState{
public:
    State getStateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
    ExaminationState* clone() const override;
};

#endif // !WAITING_STATE_H
