#ifndef IMANAGER_H
#define IMANAGER_H

#include <vector>
#include <memory>
#include <string>
template<class Entity>
class IManager {
public:
    virtual void removeById(const std::string& id) const = 0;
    virtual void add(std::unique_ptr<Entity> entity) const = 0;
    virtual std::vector<Entity*> findAll() const = 0;
};

#endif // !IMANAGER_H
