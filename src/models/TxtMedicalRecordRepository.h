#ifndef TXT_MEDICAL_RECORD_REPOSITORY_H
#define TXT_MEDICAL_RECORD_REPOSITORY_H

#include "../interfaces/IMedicalRecordRepository.h"

class TxtMedicalRecordRepository : public IMedicalRecordRepository {
private:
    std::string _filePath;
    char _delim;
    std::vector<std::unique_ptr<MedicalRecord>> _records;

public:
    TxtMedicalRecordRepository();
    TxtMedicalRecordRepository(const std::string& filePath, char delim = '|');

public:
    const std::string& filePath() const;
    char delim() const;
    void setFilePath(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<MedicalRecord> record) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids) override;
    void update(const MedicalRecord& record) override;
    std::vector<const MedicalRecord*> data() const override;
};

#endif // !TXT_MEDICAL_RECORD_REPOSITORY_H
