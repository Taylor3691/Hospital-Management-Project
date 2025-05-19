#include "CompletedState.h"

std::string CompletedState::getStateName() const {
    return "Hoan Thanh";
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
