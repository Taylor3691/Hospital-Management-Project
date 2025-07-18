#ifndef TXT_PATIENT_REPOSITORY_H
#define TXT_PATIENT_REPOSITORY_H

#include "../interfaces/IPatientRepository.h"
#include "../utils/QueryBuilder.h"
#include "../utils/utils_template.h"

class TxtPatientRepository : public IPatientRepository {
private:
    std::vector<std::unique_ptr<Patient>> _patients;
    std::string _filePath;
    char _delim;

public:
    TxtPatientRepository();
    TxtPatientRepository(const std::string& filePath, char delim = '|');

public:
    std::string filePath() const;
    char delim() const;
    void setFilePath(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<Patient> patient) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids) override;
    void update(const Patient& patient) override;
    std::vector<const Patient*> data() const override;
};

#endif // !TXT_PATIENT_REPOSITORY_H
