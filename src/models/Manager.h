#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "../utils/QueryBuilder.h"

template<typename T>
class Manager {
protected:
    Manager() = default;
    ~Manager() = default;

public:
    Manager(const Manager&) = delete;

public:
    static Manager* getInstance();

public:
    virtual void add(std::vector<std::unique_ptr<T>>& entities, std::unique_ptr<T> entity);
    void removeById(std::vector<std::unique_ptr<T>>& entities, const std::string& id);
    void removeByName(std::vector<std::unique_ptr<T>>& entities, const std::string& name);
    T* findById(std::vector<std::unique_ptr<T>>& entities, const std::string& id);
    std::vector<T*> findByName(std::vector<std::unique_ptr<T>>& entities, const std::string& name);

public:
    Manager& operator=(const Manager&) = delete;
};

#endif

template<typename T>
Manager<T>* Manager<T>::getInstance() {
    static std::unique_ptr<Manager, void(*)(Manager*)> instance(
        new Manager(),
        [](Manager* ptr) { delete ptr; }
    );
    return instance.get();
}

template<typename T>
void Manager<T>::add(std::vector<std::unique_ptr<T>>& entities, std::unique_ptr<T> entity) {
    entities.push_back(std::move(entity));
}

template<typename T>
void Manager<T>::removeById(std::vector<std::unique_ptr<T>>& entities, const std::string& id) {
    from(entities).where(makeGetter(&T::id), id).deleteOne();
}

template<typename T>
void Manager<T>::removeByName(std::vector<std::unique_ptr<T>>& entities, const std::string& name) {
    from(entities).where(makeGetter(&T::name), name).deleteMany();
}

template<typename T>
T* Manager<T>::findById(std::vector<std::unique_ptr<T>>& entities, const std::string& id) {
    return from(entities).where(makeGetter(&T::id), id).findOne();;
}

template<typename T>
std::vector<T*> Manager<T>::findByName(std::vector<std::unique_ptr<T>>& entities, const std::string& name) {
    return from(entities).where(makeGetter(&T::name), name).find();;
}
