#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include "../utils/QueryBuilder.h"
#include "../utils/utils_template.h"

template<class Entity>
class IRepository {
public:
    virtual ~IRepository() = default;

public:
    virtual void load() = 0;
    virtual void save() const = 0;
    virtual void add(std::unique_ptr<Entity> entity) = 0;
    virtual void removeById(const std::string& id) = 0;
    virtual void removeByIds(const std::vector<std::string>& ids) = 0;
    virtual void update(const Entity& entity) = 0;
    virtual std::vector<const Entity*> data() const = 0;
};

#endif // !IREPOSITORY_H
