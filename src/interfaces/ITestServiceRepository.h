#ifndef ITESTSERVICEREPOSITORY_H_
#define ITESTSERVICEREPOSITORY_H_
#include "IRepository.h"
#include "../models/TestService.h"

class ITestServiceRepository : public IRepository<TestService> {
public:
    ~ITestServiceRepository() = default;
};

#endif // !ITESTSERVICEREPOSITORY_H_
