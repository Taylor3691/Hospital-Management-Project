#include "RegisteredState.h"

RegisteredState::RegisteredState() {}

std::string RegisteredState::getStateName() const {
    return "Da Dang Ky";
}

bool RegisteredState::canPrescribeMedicine() const {
    return false;
}

bool RegisteredState::canOrderClinicalTest() const {
    return false;
}

bool RegisteredState::canComplete() const {
    return false;
}

ExaminationState* RegisteredState::clone() const {
    return new RegisteredState();
}
