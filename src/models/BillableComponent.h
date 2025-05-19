#ifndef BILLABLE_COMPONENT_H
#define BILLABLE_COMPONENT_H

#include "Object.h"

class BillableComponent : public Object {
public:
    BillableComponent() = default;
    BillableComponent(const std::string& id, const std::string& name);
    virtual ~BillableComponent() = default;

public:
    virtual double calculateFee() const = 0;
};

#endif // !BILLABLE_COMPONENT_H
