#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "QueryTypes.h"

// ---- Helper Functions ----

template<typename T, typename U>
Getter<T> makeGetter(U(T::* getter)() const);

template<typename T, typename U>
Getter<T> makeGetter(const U* (T::* getter)() const);

template<typename T, typename U>
Getter<T> compose(Getter<T> parent, Getter<U> child);

template<typename T>
bool compare(const T& value, const Condition<T>& condition);

template<typename T>
bool matches(const T& item, const std::vector<Filter<T>>& filters);

// ---- QueryBuilder Class ----

template<typename T>
class QueryBuilder {
private:
    std::vector<std::unique_ptr<T>>& _collection;
    std::vector<Filter<T>> _filters;

public:
    explicit QueryBuilder(std::vector<std::unique_ptr<T>>& collection);

public:
    std::vector<T*> find() const;
    T* findOne() const;
    void deleteMany();
    void deleteOne();
    template<typename U>
    QueryBuilder& where(Getter<T> getter, const U& value, ComparisonOp op = ComparisonOp::EQ);
};

// ---- Factory Function ----

template<typename T>
QueryBuilder<T> from(std::vector<std::unique_ptr<T>>& collection);

#endif

// ---- Implementation Details ----

template<typename T, typename U>
Getter<T> makeGetter(U(T::* getter)() const) {
    return [getter](const T& obj) -> std::any { return (obj.*getter)(); };
}

template<typename T, typename U>
Getter<T> makeGetter(const U* (T::* getter)() const) {
    return [getter](const T& obj) -> std::any { return *(obj.*getter)(); };
}

template<typename T, typename U>
Getter<T> compose(Getter<T> parent, Getter<U> child) {
    return [parent, child](const T& obj) -> std::any {
        try {
            auto parentValue = std::any_cast<U>(parent(obj));
            return child(parentValue);
        }
        catch (const std::bad_any_cast& e) {
            throw std::runtime_error("Type mismatch in compose");
        }
    };
}

template<typename T>
bool compare(const T& value, const Condition<T>& condition) {
    switch (condition.op) {
    case ComparisonOp::EQ:
        return value == condition.value;
    case ComparisonOp::NE:
        return value != condition.value;
    case ComparisonOp::GT:
        return value > condition.value;
    case ComparisonOp::LT:
        return value < condition.value;
    case ComparisonOp::GTE:
        return value >= condition.value;
    case ComparisonOp::LTE:
        return value <= condition.value;
    default:
        return false;
    }
}

template<typename T>
bool matches(const T& item, const std::vector<Filter<T>>& filters) {
    if (filters.empty()) return true;

    bool result = true;
    for (const Filter<T>& filter : filters) {
        std::visit([&](const auto& cond) {
            try {
                using CondType = std::decay_t<decltype(cond.value)>;
                auto value = std::any_cast<CondType>(filter.getter(item));
                result = compare(value, cond);
            }
            catch (const std::bad_any_cast& e) {
                throw std::runtime_error("Type mismatch in filter");
            }
        }, filter.value);

        if (!result) {
            return false;
        }
    }

    return true;
}

template<typename T>
QueryBuilder<T> from(std::vector<std::unique_ptr<T>>& collection) {
    return QueryBuilder<T>(collection);
}

template<typename T>
QueryBuilder<T>::QueryBuilder(std::vector<std::unique_ptr<T>>& collection)
    : _collection(collection) {}

template<typename T>
std::vector<T*> QueryBuilder<T>::find() const {
    std::vector<T*> results;
    for (const std::unique_ptr<T>& item : _collection) {
        if (matches(*item, _filters)) {
            results.push_back(item.get());
        }
    }

    return results;
}

template<typename T>
T* QueryBuilder<T>::findOne() const {
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
void QueryBuilder<T>::deleteMany() {
    std::erase_if(_collection, [this](const std::unique_ptr<T>& item) {
        return matches(*item, _filters);
    });
}

template<typename T>
void QueryBuilder<T>::deleteOne() {
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
QueryBuilder<T>& QueryBuilder<T>::where(Getter<T> getter, const U& value, ComparisonOp op) {
    _filters.push_back({ getter, Condition<U>{value, op} });
    return *this;
}
