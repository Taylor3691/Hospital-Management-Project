#ifndef QUERY_BUILDER_H
#define QUERY_BUILDER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "QueryUtils.h"

namespace {
    template<typename T>
    using Collection = std::variant<
        std::reference_wrapper<std::vector<std::unique_ptr<T>>>,
        std::reference_wrapper<std::vector<T*>>
    >;
}

template<typename T>
class QueryBuilder {
private:
    Collection<T> _collection;
    std::vector<RFilter<std::remove_const_t<T>>> _filters;
    FilterMode _mode;

public:
    explicit QueryBuilder(const Collection<T>& collection,
        FilterMode mode = FilterMode::AND);

public:
    std::vector<T*> find();
    T* findOne();
    void deleteMany();
    void deleteOne();
    template<typename U> void updateMany(Setter<T> setter, const U& value);
    template<typename U> void updateOne(Setter<T> setter, const U& value);
    template<typename U> QueryBuilder& where(Getter<T> getter, const U& value,
        ComparisonOperator op = ComparisonOperator::EQ);
};

template<typename T>
inline QueryBuilder<T> from(
    std::vector<std::unique_ptr<T>>& collection,
    FilterMode mode = FilterMode::AND
) {
    auto wrapper = Collection<T>(std::ref(collection));
    return QueryBuilder<T>(wrapper, mode);
}

template<typename T>
inline QueryBuilder<T> from(
    std::vector<T*>& collection,
    FilterMode mode = FilterMode::AND
) {
    auto wrapper = Collection<T>(std::ref(collection));
    return QueryBuilder<T>(wrapper, mode);
}

template<typename T>
inline QueryBuilder<T>::QueryBuilder(const Collection<T>& collection, FilterMode mode)
    : _collection(collection), _mode(mode) {}

template<typename T>
inline std::vector<T*> QueryBuilder<T>::find() {
    std::vector<T*> results;

    std::visit([this, &results](const auto& collection) {
        auto& vec = collection.get();
        for (const auto& item : vec) {
            if (matches(*item, _filters, _mode)) {
                if constexpr (std::is_same_v<std::remove_reference_t<decltype(item)>, std::unique_ptr<T>>) {
                    results.push_back(item.get());
                }
                else if constexpr (std::is_same_v<std::remove_reference_t<decltype(item)>, T*>) {
                    results.push_back(item);
                }
            }
        }
    }, _collection);

    return results;
}

template<typename T>
inline T* QueryBuilder<T>::findOne() {
    T* result = nullptr;

    std::visit([this, &result](const auto& collection) {
        auto& vec = collection.get();
        auto it = std::find_if(
            vec.begin(), vec.end(),
            [this](const auto& item) {
                return matches(*item, _filters, _mode);
            }
        );

        if (it != vec.end()) {
            if constexpr (std::is_same_v<std::remove_reference_t<decltype(*it)>, std::unique_ptr<T>>) {
                result = it->get();
            }
            else if constexpr (std::is_same_v<std::remove_reference_t<decltype(*it)>, T*>) {
                result = *it;
            }
        }
    }, _collection);

    return result;
}

template<typename T>
inline void QueryBuilder<T>::deleteMany() {
    std::visit([this](auto& collection) {
        auto& vec = collection.get();
        if constexpr (!std::is_const_v<std::remove_pointer_t<typename std::decay_t<decltype(vec)>::value_type>>) {
            std::erase_if(vec, [this](const auto& item) {
                return matches(*item, _filters, _mode);
            });
        }
    }, _collection);
}

template<typename T>
inline void QueryBuilder<T>::deleteOne() {
    std::visit([this](auto& collection) {
        auto& vec = collection.get();
        if constexpr (!std::is_const_v<std::remove_pointer_t<typename std::decay_t<decltype(vec)>::value_type>>) {
            auto it = std::find_if(
                vec.begin(), vec.end(),
                [this](const auto& item) { return matches(*item, _filters, _mode); }
            );

            if (it != vec.end()) {
                vec.erase(it);
            }
        }
    }, _collection);
}

template<typename T>
template<typename U>
inline void QueryBuilder<T>::updateMany(Setter<T> setter, const U& value) {
    std::visit([this, &setter, &value](auto& collection) {
        auto& vec = collection.get();
        if constexpr (!std::is_const_v<std::remove_pointer_t<typename std::decay_t<decltype(vec)>::value_type>>) {
            for (auto& item : vec) {
                if (matches(*item, _filters, _mode)) {
                    setter(*item, value);
                }
            }
        }
    }, _collection);
}

template<typename T>
template<typename U>
inline void QueryBuilder<T>::updateOne(Setter<T> setter, const U& value) {
    std::visit([this, &setter, &value](auto& collection) {
        auto& vec = collection.get();
        if constexpr (!std::is_const_v<std::remove_pointer_t<typename std::decay_t<decltype(vec)>::value_type>>) {
            auto it = std::find_if(
                vec.begin(), vec.end(),
                [this](const auto& item) { return matches(*item, _filters, _mode); }
            );

            if (it != vec.end()) {
                setter(**it, value);
            }
        }
    }, _collection);
}

template<typename T>
template<typename U>
inline QueryBuilder<T>& QueryBuilder<T>::where(
    Getter<T> getter,
    const U& value,
    ComparisonOperator op
) {
    FilterCriteria criteria;
    criteria.value = value;
    criteria.op = op;

    _filters.push_back({ criteria, getter });

    return *this;
}

#endif // !QUERY_BUILDER_H
