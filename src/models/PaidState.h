#ifndef PAID_STATE_H
#define PAID_STATE_H

#include "ExaminationState.h"

class PaidState : public ExaminationState {
public:
    State stateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
    ExaminationState* clone() const override;
};

#endif // !PAID_STATE_H
