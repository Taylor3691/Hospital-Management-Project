#ifndef ITEST_SERVICE_REPOSITORY_H
#define ITEST_SERVICE_REPOSITORY_H

#include "IRepository.h"
#include "../models/TestService.h"

class ITestServiceRepository : public IRepository<TestService> {
public:
    ~ITestServiceRepository() = default;
};

#endif // !ITEST_SERVICE_REPOSITORY_H
