#ifndef IPATIENT_REPOSITORY_H
#define IPATIENT_REPOSITORY_H

#include "IRepository.h"
#include "../models/Patient.h"

class IPatientRepository : public IRepository<Patient> {
public:
    virtual ~IPatientRepository() = default;
};

#endif // !IPATIENT_REPOSITORY_H
