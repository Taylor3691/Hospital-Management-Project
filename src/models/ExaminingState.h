#ifndef EXAMINING_STATE_H
#define EXAMINING_STATE_H

#include "ExaminationState.h"

class ExaminingState : public ExaminationState {
public:
    std::string getStateName() const override;
    bool canPrescribeMedicine() const override;
    bool canOrderClinicalTest() const override;
    bool canComplete() const override;
};

#endif // !EXAMINING_STATE_H
