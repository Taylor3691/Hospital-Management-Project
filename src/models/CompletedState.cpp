#include "CompletedState.h"

std::string CompletedState::getStateName() const {
    return "CompletedState";
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
