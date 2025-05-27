#include "PendingTestState.h"

std::string PendingTestState::getStateName() const {
    return "PendingTestState";
}

bool PendingTestState::canPrescribeMedicine() const {
    return true;
}

bool PendingTestState::canOrderClinicalTest() const {
    return true;
}

bool PendingTestState::canComplete() const {
    return false;
}

ExaminationState* PendingTestState::clone() const {
    return new PendingTestState();
}
