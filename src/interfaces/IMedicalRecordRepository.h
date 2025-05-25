#ifndef IMEDICALRECORDREPOSITORY_H_
#define IMEDICALRECORDREPOSITORY_H_

#include "IRepository.h"
#include "../models/MedicalRecord.h"

class IMedicalRecordRepository : public IRepository<MedicalRecord> {
public:
    virtual ~IMedicalRecordRepository() = default;
};


#endif // !IMEDICALREPOSITORY_H_
