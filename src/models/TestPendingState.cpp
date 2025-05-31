#include "TestPendingState.h"

ExaminationState::State TestPendingState::stateName() const {
    return TestPending;
}

bool TestPendingState::canPrescribeMedicine() const {
    return true;
}

bool TestPendingState::canOrderClinicalTest() const {
    return true;
}

bool TestPendingState::canComplete() const {
    return false;
}

ExaminationState* TestPendingState::clone() const {
    return new TestPendingState(*this);
}
