#ifndef IQUERY_H
#define IQUERY_H

#include <string>
#include <vector>

template<class Entity>
class IQuery {
public:
    virtual ~IQuery() = default;

public:
    virtual Entity* findById(const std::string& id) const = 0;
    virtual std::vector<const Entity*> findAll() const = 0;
};

#endif // !IQUERY_H
