#ifndef IMANAGER_H
#define IMANAGER_H

#include <string>
#include <memory>
#include <vector>

template<class Entity>
class IManager {
public:
    virtual ~IManager() = default;

public:
    virtual void add(std::unique_ptr<Entity> entity) = 0;
    virtual void removeById(const std::string& id) = 0;
    virtual void update(const Entity& entity) = 0;
    virtual std::vector<const Entity*> getAll() const = 0;
};

#endif // !IMANAGER_H
