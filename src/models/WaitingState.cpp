#include "WaitingState.h"

std::string WaitingState::getStateName() const {
    return "WaitingState";
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
