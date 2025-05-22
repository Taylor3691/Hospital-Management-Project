#ifndef IPATIENTREPOSITORY_H_
#define IPATIENTREPOSITORY_H_

#include "IRepository.h"
#include "../models/Patient.h"

class IPatientRepository : public IRepository<Patient> {
public:
    virtual ~IPatientRepository() = default;
};

#endif // !IPATIENTREPOSITORY_H_
