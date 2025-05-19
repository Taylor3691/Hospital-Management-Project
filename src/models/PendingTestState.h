#ifndef PENDING_TEST_STATE_H
#define PENDING_TEST_STATE_H

#include "ExaminationState.h"

class PendingTestState : public ExaminationState {
public:
    std::string getStateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
};

#endif // !PENDING_TEST_STATE_H
