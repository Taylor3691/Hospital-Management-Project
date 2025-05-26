#ifndef IROOM_EXAMINATION_REPOSITORY_H
#define IROOM_EXAMINATION_REPOSITORY_H

#include "IRepository.h"
#include "../models/RoomExamination.h"

class IRoomExaminationRepository : public IRepository<RoomExamination> {
public:
    virtual ~IRoomExaminationRepository() = default;
};

#endif // !IROOM_EXAMINATION_REPOSITORY_H
