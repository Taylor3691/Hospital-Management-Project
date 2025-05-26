#ifndef TEST_SERVICE_H
#define TEST_SERVICE_H

#include "Object.h"
#include "TxtWritingVisitor.h"

class TestService : public Object {
protected:
    double _cost;

public:
    TestService() = default;
    TestService(const std::string& id, const std::string& name, double cost);
    TestService(const TestService& other);
    virtual ~TestService() = default;

public:
    double cost() const;
    void setCost(double cost);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;
};

#endif // !TEST_SERVICE_H
