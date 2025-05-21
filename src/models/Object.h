#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>
#include "../interfaces/IVisitor.h"

class Object {
protected:
    std::string _id;
    std::string _name;

public:
    Object() = default;
    Object(const std::string& id, const std::string& name);
    Object(const Object&);
    virtual ~Object() = default;

public:
    std::string id() const;
    std::string name() const;

public:
    void setId(const std::string& id);
    void setName(const std::string& name);

public:
    virtual void acceptWrite(IVisitor* visitor, std::ostream& os) = 0;
    virtual Object* clone() const;

};

#endif // !OBJECT_H
