#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
protected:
    std::string _id;
    std::string _name;

public:
    Object(const std::string& id, const std::string& name);
    virtual ~Object() = default;

public:
    virtual std::string id() const;
    virtual std::string name() const;
};

#endif // !OBJECT_H
