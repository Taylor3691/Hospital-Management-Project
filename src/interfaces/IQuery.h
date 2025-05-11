#ifndef IQUERY_H
#define IQUERY_H

#include <string>
template<class Entity>
class IQuery {
public:
    virtual Entity* findById(const std::string& id) const = 0;
    virtual std::vector<Entity*> findAll() const = 0;
};

#endif // !IQUERY_H
