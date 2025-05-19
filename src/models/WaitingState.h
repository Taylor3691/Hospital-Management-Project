#ifndef WAITING_STATE_H
#define WAITING_STATE_H

#include "ExaminationState.h"

class WaitingState : public ExaminationState{
public:
    std::string getStateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
};

#endif // !WAITING_STATE_H
