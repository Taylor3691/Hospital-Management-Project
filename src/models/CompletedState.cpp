#include "CompletedState.h"

ExaminationState::State CompletedState::getStateName() const {
    return Completed;
}

bool CompletedState::canPrescribeMedicine() const {
    return false;
}

bool CompletedState::canOrderClinicalTest() const {
    return false;
}

bool CompletedState::canComplete() const {
    return false;
}

ExaminationState* CompletedState::clone() const {
    return new CompletedState(*this);
}
