#ifndef TESTSERVICE_H_
#define TESTSERVICE_H_

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
    virtual void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    virtual Object* clone() const override;
};



#endif // !TESTSERVICE_H_
