#ifndef TXTDEPARTMENTREPOSITORY_H
#define TXTDEPARTMENTREPOSITORY_H

#include "IDepartmentRepository.h"

class TxtDepartmentRepository: public IDepartmentRepository {
private:
    std::string _path;

public:
    TxtDepartmentRepository();
    TxtDepartmentRepository(std::string path);
    ~TxtDepartmentRepository();

public:
    bool save(Department* dept);
    std::vector<Department*> loadAll();
};

#endif // !TXTDEPARTMENTREPOSITORY_H
