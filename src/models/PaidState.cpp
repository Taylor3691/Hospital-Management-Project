#include "PaidState.h"

ExaminationState::State PaidState::stateName() const {
    return Paid;
}

bool PaidState::canPrescribeMedicine() const {
    return false;
}

bool PaidState::canOrderClinicalTest() const {
    return false;
}

bool PaidState::canComplete() const {
    return false;
}

ExaminationState* PaidState::clone() const {
    return new PaidState(*this);
}
