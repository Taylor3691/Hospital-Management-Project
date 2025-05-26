#ifndef IMEDICAL_RECORD_REPOSITORY_H
#define IMEDICAL_RECORD_REPOSITORY_H

#include "IRepository.h"
#include "../models/MedicalRecord.h"

class IMedicalRecordRepository : public IRepository<MedicalRecord> {
public:
    virtual ~IMedicalRecordRepository() = default;
};

#endif // !IMEDICAL_RECORD_REPOSITORY_H
