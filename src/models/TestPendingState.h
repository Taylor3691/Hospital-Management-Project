#ifndef PENDING_TEST_STATE_H
#define PENDING_TEST_STATE_H

#include "ExaminationState.h"

class TestPendingState : public ExaminationState {
public:
    State getStateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
    ExaminationState* clone() const override;
};

#endif // !PENDING_TEST_STATE_H
