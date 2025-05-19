#ifndef REGISTERED_STATE_H
#define REGISTERED_STATE_H

#include "ExaminationState.h"

class RegisteredState : public ExaminationState {
public:
    std::string getStateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
};

#endif // !REGISTERED_STATE_H
