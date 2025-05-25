#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "../interfaces/IManager.h"
#include "../interfaces/IPatientRepository.h"
#include "../utils/QueryBuilder.h"

class PatientManager : public IManager<Patient> {
private:
    IPatientRepository* _repo;

public:
    PatientManager(IPatientRepository* repo);

public:
    void add(std::unique_ptr<Patient> patient) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids);
    void update(const Patient& patient) override;
    std::vector<const Patient*> find(const std::vector<RFilter<Patient>>& filters) const override;
    std::vector<const Patient*> getAll() const override;
};

#endif // !PATIENT_MANAGER_H
