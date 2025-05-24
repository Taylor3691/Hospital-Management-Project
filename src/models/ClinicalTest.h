#ifndef CLINICAL_TEST_H
#define CLINICAL_TEST_H

#include "BillableComponent.h"

class ClinicalTest : public BillableComponent {
private:
    double _cost;
    std::string _result;
    bool _completed;

public:
    ClinicalTest();
    ClinicalTest(const std::string& id, const std::string& name,
        double cost, const std::string& result = "", bool completed = false);

public:
    double cost() const;
    std::string result() const;
    bool completed() const;

public:
    void setCost(double cost);
    void setResult(const std::string& result);
    void setCompleted(bool completed);

public:
    double calculateFee() const override;
    void acceptWrite(IVisitor* visitor, std::ostream& os);
    Object* clone() const;
};

#endif // !CLINICAL_TEST_H
