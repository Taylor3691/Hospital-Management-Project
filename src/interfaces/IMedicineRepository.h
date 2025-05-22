#ifndef IMEDICINEREPOSITORY_H
#define IMEDICINEREPOSITORY_H

#include "IRepository.h"
#include "../models/Medicine.h"

class IMedicineRepository : public IRepository<Medicine> {
public:
    virtual ~IMedicineRepository() = default;
};

#endif // !IMEDICINEREPOSITORY_H
