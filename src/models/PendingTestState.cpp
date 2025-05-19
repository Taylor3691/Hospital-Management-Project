#include "PendingTestState.h"

std::string PendingTestState::getStateName() const {
    return "Cho test";
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
