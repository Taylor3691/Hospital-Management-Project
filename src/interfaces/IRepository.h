#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <vector>
#include "../models/Entity.h"

class IRepository {
public:
    virtual std::vector<Entity*> loadAll() const = 0;
    virtual void saveAll(const std::vector<Entity*>& entities) const = 0;
};

#endif // !IREPOSITORY_H
