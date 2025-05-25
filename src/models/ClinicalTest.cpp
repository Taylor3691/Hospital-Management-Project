#include "ClinicalTest.h"

ClinicalTest::ClinicalTest()
    : _cost(), _result(), _completed() {}

ClinicalTest::ClinicalTest(
    const std::string& id,
    const std::string& name,
    const std::string& testId,
    double cost,
    const std::string& result,
    bool completed
)
    : BillableComponent(id, name)
    , _testId(testId)
    , _cost(cost)
    , _result(result)
    , _completed(completed) {}

std::string ClinicalTest::testId() const {
    return _testId;
}

double ClinicalTest::cost() const {
    return _cost;
}

std::string ClinicalTest::result() const {
    return _result;
}

bool ClinicalTest::completed() const {
    return _completed;
}

void ClinicalTest::setTestId(const std::string& id) {
    _testId = id;
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

void ClinicalTest::acceptWrite(IVisitor* visitor, std::ostream& os) {
    (dynamic_cast<IWritingVisitor*>(visitor))->write(this, os);
}

Object* ClinicalTest::clone() const {
    return new ClinicalTest(*this);
}
