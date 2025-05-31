#ifndef COMPLETED_STATE_H
#define COMPLETED_STATE_H

#include "ExaminationState.h"

class CompletedState : public ExaminationState {
public:
    State stateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
    ExaminationState* clone() const override;
};

#endif // !COMPLETED_STATE_H
