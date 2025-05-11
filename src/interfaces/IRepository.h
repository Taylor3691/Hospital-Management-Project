#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <vector>
template<class Entity>
class IRepository {
public:
    virtual ~IRepository() = default;
public:
    virtual std::vector<Entity*> loadAll() const = 0;
    virtual void saveAll(const std::vector<Entity*>& entities) const = 0;
    virtual void add(Entity* entity) const = 0;
    virtual void removeById(const std::string& id) const = 0;
    virtual std::vector<Enity*> findAll() const = 0;
};

#endif // !IREPOSITORY_H
