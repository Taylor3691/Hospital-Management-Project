#include "ExaminingState.h"

std::string ExaminingState::getStateName() const {
    return "ExaminingState";
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
    return new ExaminingState();
}
