#ifndef IPERSON_H
#define IPERSON_H

#include <string>
#include "../utils/Date.h"

class IPerson {
public:
    virtual std::string id() const = 0;
    virtual std::string name() const = 0;
    virtual Date dateOfBirth() const = 0;
    virtual int age() const = 0;
    virtual std::string gender() const = 0;
    virtual std::string phone() const = 0;
    virtual std::string address() const = 0;
};

#endif
