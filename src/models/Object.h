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
    std::string id() const;
    std::string name() const;

public:
    void setId(const std::string& id);
    void setName(const std::string& name);
};

#endif // !OBJECT_H
