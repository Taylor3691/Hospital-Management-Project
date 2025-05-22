#ifndef TXTMEDICINEREPOSITORY_H_
#define TXTMEDICINEREPOSITORY_H_

#include "../interfaces/IMedicineRepository.h"

class TxtMedicineRepository : public IMedicineRepository {
private:
    std::string _filename;
    char _delim;
    std::vector<std::unique_ptr<Medicine>> _medicines;

public:
    TxtMedicineRepository();
    TxtMedicineRepository(const std::string& filename, char delim = '|');

public:
    const std::string& fileName() const;
    char delim() const;
    void setFilename(const std::string& filename);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Medicine> medicine) override;
    void removeById(const std::string& id) override;
    void update(const Medicine& employee) override;
    std::vector<const Medicine*> data() const override;

};

#endif // !TXTMEDICINEREPOSITORY_H_
