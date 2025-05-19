#ifndef EXAMINATION_STATE_H
#define EXAMINATION_STATE_H

#include <string>

class ExaminationState {
public:
    virtual ~ExaminationState() = default;

public:
    virtual std::string getStateName() const = 0;
    virtual bool canPrescribeMedicine() const = 0;
    virtual bool canOrderClinicalTest() const = 0;
    virtual bool canComplete() const = 0;
};

#endif // !EXAMINATION_STATE_H
