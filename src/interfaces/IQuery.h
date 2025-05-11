#ifndef IQUERY_H
#define IQUERY_H

#include <string>
#include "../models/Entity.h"

class IQuery {
public:
    virtual Entity* findById(const std::string& id) const = 0;
};

#endif // !IQUERY_H
