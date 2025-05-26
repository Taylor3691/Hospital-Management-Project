#ifndef MEDICINEMANAGER_H
#define MEDICINEMANAGER_H

#include "../interfaces/IManager.h"
#include "../interfaces/IMedicineRepository.h"
#include "../utils/QueryBuilder.h"

class MedicineManager : public IManager<Medicine> {
private:
    IMedicineRepository* _repo;

public:
    MedicineManager(IMedicineRepository* repo);

public:
    void add(std::unique_ptr<Medicine> medicine) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids);
    void update(const Medicine& medicine) override;
    std::vector<const Medicine*> find(const std::vector<RFilter<Medicine>>& filters) const override;
    std::vector<const Medicine*> getAll() const override;
};


#endif // !MEDICINEMANAGER_H
