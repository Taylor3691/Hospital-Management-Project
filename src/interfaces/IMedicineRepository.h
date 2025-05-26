#ifndef IMEDICINE_REPOSITORY_H
#define IMEDICINE_REPOSITORY_H

#include "IRepository.h"
#include "../models/Medicine.h"

class IMedicineRepository : public IRepository<Medicine> {
public:
    virtual ~IMedicineRepository() = default;
};

#endif // !IMEDICINE_REPOSITORY_H
