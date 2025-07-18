#include "TxtTestServiceRepository.h"

TxtTestServiceRepository::TxtTestServiceRepository()
    : _filePath("tests.txt"), _delim('|')
{
    load();
}

TxtTestServiceRepository::TxtTestServiceRepository(
    const std::string& filePath,
    char delim
)
    : _filePath(filePath), _delim(delim)
{
    load();
}

const std::string& TxtTestServiceRepository::filePath() const {
    return _filePath;
}

void TxtTestServiceRepository::setFilePath(const std::string& filePath) {
    _filePath = filePath;
}

char TxtTestServiceRepository::delim() const {
    return _delim;
}

void TxtTestServiceRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtTestServiceRepository::save() const {
    ::save(_tests, _delim, _filePath);
}

void TxtTestServiceRepository::load() {
    _tests.clear();
    ::load(_tests, _delim, _filePath);
}

void TxtTestServiceRepository::add(std::unique_ptr<TestService> patient) {
    _tests.push_back(std::move(patient));
    save();
}

void TxtTestServiceRepository::removeById(const std::string& id) {
    from(_tests).where(&TestService::id, id).deleteOne();
    save();
}

void TxtTestServiceRepository::removeByIds(const std::vector<std::string>& ids) {
    auto query = from(_tests, FilterMode::OR);
    for (const auto& id : ids) {
        query.where(&TestService::id, id);
    }
    query.deleteMany();
    save();
}

void TxtTestServiceRepository::update(const TestService& patient) {
    auto ptr = from(_tests)
        .where(&TestService::id, patient.id()).findOne();
    if (ptr) {
        *ptr = patient;
    }
    else {
        throw std::runtime_error("TestService not found");
    }
    save();
}

std::vector<const TestService*> TxtTestServiceRepository::data() const {
    std::vector<const TestService*> result;
    for (const auto& patient : _tests) {
        result.push_back(patient.get());
    }
    return result;
}
