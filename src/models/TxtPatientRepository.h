#ifndef TXTPATIENTREPOSITORY_H_
#define TXTPATIENTREPOSITORY_H_
#include "../interfaces/IPatientRepository.h"
#include "../utils/QueryBuilder.h"
#include "../utils/utils_template.h"

class TxtPatientRepository : public IPatientRepository {
private:
    std::string _filePath;
    std::vector<std::unique_ptr<Patient>> _patients;
    char _delim;

public:
    TxtPatientRepository();
    TxtPatientRepository(const std::string& filePath, char delim = '|');

public:
    const std::string& fileName() const;
    char delim() const;
    void setFileName(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Patient> entity) override;
    void removeById(const std::string& id) override;
    void update(const Patient& entity) override;
    std::vector<const Patient*> data() const override;

};

#endif // !TXTPATIENTREPOSITORY_H_
