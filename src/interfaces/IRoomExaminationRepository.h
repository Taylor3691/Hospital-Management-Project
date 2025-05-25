#ifndef IROOMEXAMINATIONREPOSITORY_H_
#define IROOMEXAMINATIONREPOSITORY_H_

#include "IRepository.h"
#include "../models/RoomExamination.h"

class IRoomExaminationRepository : public IRepository<RoomExamination> {
public:
    virtual ~IRoomExaminationRepository() = default;
};


#endif // !IMEDICALREPOSITORY_H_
