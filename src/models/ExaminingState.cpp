#include "ExaminingState.h"

std::string ExaminingState::getStateName() const {
    return "Dang Kham";
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
