#include "ClinicalTest.h"

ClinicalTest::ClinicalTest()
    : _cost(), _result(), _completed() {}

ClinicalTest::ClinicalTest(
    const std::string& id,
    const std::string& name,
    double cost,
    const std::string& result,
    bool completed
)
    : BillableComponent(id, name)
    , _cost(cost)
    , _result(result)
    , _completed(completed) {}

double ClinicalTest::cost() const {
    return _cost;
}

std::string ClinicalTest::result() const {
    return _result;
}

bool ClinicalTest::completed() const {
    return _completed;
}

void ClinicalTest::setCost(double cost) {
    _cost = cost;
}

void ClinicalTest::setResult(const std::string& result) {
    _result = result;
}

void ClinicalTest::setCompleted(bool completed) {
    _completed = completed;
}

double ClinicalTest::calculateFee() const {
    return _cost;
}

void ClinicalTest::acceptWrite(IVisitor* visior, std::ostream& os) {

}

Object* ClinicalTest::clone() const {
    return new ClinicalTest(*this);
}
