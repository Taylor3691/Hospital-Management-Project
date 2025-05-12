#include "Object.h"

Object::Object(const std::string& id, const std::string& name)
    : _id(id), _name(name) {}

std::string Object::id() const {
    return _id;
}

std::string Object::name() const {
    return _name;
}

void Object::setId(const std::string& id) {
    _id = id;
}

void Object::setName(const std::string& name) {
    _name = name;
}
