#include "WaitingState.h"

ExaminationState::State WaitingState::getStateName() const {
    return Waiting;
}

bool WaitingState::canPrescribeMedicine() const {
    return false;
}

bool WaitingState::canOrderClinicalTest() const {
    return false;
}

bool WaitingState::canComplete() const {
    return false;
}

ExaminationState* WaitingState::clone() const {
    return new WaitingState(*this);
}
