#include "ExaminingState.h"

ExaminationState::State ExaminingState::stateName() const {
    return Examining;
}

bool ExaminingState::canPrescribeMedicine() const {
    return true;
}

bool ExaminingState::canOrderClinicalTest() const {
    return true;
}

bool ExaminingState::canComplete() const {
    return true;
}

ExaminationState* ExaminingState::clone() const {
    return new ExaminingState(*this);
}
