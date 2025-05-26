#ifndef TXT_TEST_SERVICE_REPOSITORY_H
#define TXT_TEST_SERVICE_REPOSITORY_H

#include "../interfaces/ITestServiceRepository.h"

class TxtTestServiceRepository : public ITestServiceRepository {
private:
    std::string _filePath;
    std::vector<std::unique_ptr<TestService>> _tests;
    char _delim;

public:
    TxtTestServiceRepository();
    TxtTestServiceRepository(const std::string& filePath, char delim = '|');

public:
    const std::string& filePath() const;
    char delim() const;
    void setFilePath(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<TestService> entity) override;
    void removeById(const std::string& id) override;
    void removeByIds(const std::vector<std::string>& ids) override;
    void update(const TestService& entity) override;
    std::vector<const TestService*> data() const override;
};

#endif // !TXT_TEST_SERVICE_REPOSITORY_H
