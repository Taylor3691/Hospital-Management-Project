#ifndef TXT_MEDICINE_REPOSITORY_H
#define TXT_MEDICINE_REPOSITORY_H

#include "../interfaces/IMedicineRepository.h"

class TxtMedicineRepository : public IMedicineRepository {
private:
    std::string _filePath;
    char _delim;
    std::vector<std::unique_ptr<Medicine>> _medicines;

public:
    TxtMedicineRepository();
    TxtMedicineRepository(const std::string& filename, char delim = '|');

public:
    const std::string& filePath() const;
    char delim() const;
    void setFilePath(const std::string& filename);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Medicine> medicine) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids) override;
    void update(const Medicine& employee) override;
    std::vector<const Medicine*> data() const override;
};

#endif // !TXT_MEDICINE_REPOSITORY_H
