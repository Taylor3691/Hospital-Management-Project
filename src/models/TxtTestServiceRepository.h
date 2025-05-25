#ifndef TXTTESTSERVICEREPOSITORY_H_
#define TXTTESTSERVICEREPOSITORY_H_

#include "../interfaces/ITestServiceRepository.h"

class TxtTestServiceRepository : public ITestServiceRepository {
private:
    std::string _fileName;
    std::vector<std::unique_ptr<TestService>> _tests;
    char _delim;

public:
    TxtTestServiceRepository();
    TxtTestServiceRepository(const std::string& filePath, char delim = '|');

public:
    const std::string& fileName() const;
    char delim() const;
    void setFileName(const std::string& filePath);
    void setDelim(char delim);

public:
    void load() override;
    void save() const override;
    void add(std::unique_ptr<TestService> entity) override;
    void removeById(const std::string& id) override;
    void update(const TestService& entity) override;
    std::vector<const TestService*> data() const override;
};


#endif // !TXTTESTSERVICEREPOSITORY_H_
