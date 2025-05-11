#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "QueryUtils.h"

template<typename T>
class QueryBuilder {
private:
    std::vector<std::unique_ptr<T>>& _collection;
    std::vector<RFilter<T>> _filters;

public:
    explicit QueryBuilder(std::vector<std::unique_ptr<T>>& collection);

public:
    std::vector<T*> find() const;
    T* findOne() const;
    void deleteMany();
    void deleteOne();
    template<typename U> void updateMany(Setter<T> setter, const U& value);
    template<typename U> void updateOne(Setter<T> setter, const U& value);
    template<typename U> QueryBuilder& where(Getter<T> getter,
        const U& value, ComparisonOperator op = ComparisonOperator::EQ);
};

template<typename T>
QueryBuilder<T> from(std::vector<std::unique_ptr<T>>& collection);

#endif // !QUERYBUILDER_H

template<typename T>
inline QueryBuilder<T> from(std::vector<std::unique_ptr<T>>& collection) {
    return QueryBuilder<T>(collection);
}

template<typename T>
inline QueryBuilder<T>::QueryBuilder(std::vector<std::unique_ptr<T>>& collection)
    : _collection(collection) {}

template<typename T>
inline std::vector<T*> QueryBuilder<T>::find() const {
    std::vector<T*> results;
    for (const std::unique_ptr<T>& item : _collection) {
        if (matches(*item, _filters)) {
            results.push_back(item.get());
        }
    }

    return results;
}

template<typename T>
inline T* QueryBuilder<T>::findOne() const {
    auto it = std::find_if(
        _collection.begin(), _collection.end(),
        [this](const std::unique_ptr<T>& item) { return matches(*item, _filters); }
    );

    if (it == _collection.end()) {
        return nullptr;
    }
    return it->get();
}

template<typename T>
inline void QueryBuilder<T>::deleteMany() {
    std::erase_if(_collection, [this](const std::unique_ptr<T>& item) {
        return matches(*item, _filters);
    });
}

template<typename T>
inline void QueryBuilder<T>::deleteOne() {
    auto it = std::find_if(
        _collection.begin(), _collection.end(),
        [this](const std::unique_ptr<T>& item) { return matches(*item, _filters); }
    );

    if (it != _collection.end()) {
        _collection.erase(it);
    }
}

template<typename T>
template<typename U>
inline void QueryBuilder<T>::updateMany(Setter<T> setter, const U& value) {
    for (const std::unique_ptr<T>& item : _collection) {
        if (matches(*item, _filters)) {
            setter(*item, value);
        }
    }
}

template<typename T>
template<typename U>
inline void QueryBuilder<T>::updateOne(Setter<T> setter, const U& value) {
    auto it = std::find_if(
        _collection.begin(), _collection.end(),
        [this](const std::unique_ptr<T>& item) { return matches(*item, _filters); }
    );

    if (it != _collection.end()) {
        setter(**it, value);
    }
}

template<typename T>
template<typename U>
inline QueryBuilder<T>& QueryBuilder<T>::where(Getter<T> getter, const U& value, ComparisonOperator op) {
    _filters.push_back({ getter, FilterCondition<U>{value, op} });
    return *this;
}
