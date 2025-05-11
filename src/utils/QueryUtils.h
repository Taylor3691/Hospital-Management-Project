#ifndef QUERYUTILS_H
#define QUERYUTILS_H

#include "QueryTypes.h"

template<typename T, typename U>
Getter<T> makeGetter(U(T::* getter)() const);

template<typename T, typename U>
Getter<T> makeGetter(const U* (T::* getter)() const);

template<typename T, typename U>
Setter<T> makeSetter(void(T::* setter)(const U&));

template<typename T, typename U>
Getter<T> compose(Getter<T> parent, Getter<U> child);

template<typename T, typename U>
Setter<T> compose(Getter<T> parent, Setter<U> child);

template<typename T>
bool compare(const T& value, const FilterCondition<T>& condition);

template<typename T>
bool matches(const T& item, const std::vector<RFilter<T>>& filters);

#endif // !QUERYUTILS_H

template<typename T, typename U>
inline Getter<T> makeGetter(U(T::* getter)() const) {
    return [getter](const T& obj) -> std::any {
        return (obj.*getter)();
    };
}

template<typename T, typename U>
inline Getter<T> makeGetter(const U* (T::* getter)() const) {
    return [getter](const T& obj) -> std::any {
        return *(obj.*getter)();
    };
}

template<typename T, typename U>
inline Setter<T> makeSetter(void(T::* setter)(const U&)) {
    return [setter](const T& obj, const U& value) -> std::any {
        return (obj.*setter)(value);
    };
}

template<typename T, typename U>
inline Getter<T> compose(Getter<T> parent, Getter<U> child) {
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

template<typename T, typename U>
inline Setter<T> compose(Getter<T> parent, Setter<U> child) {
    return [parent, child](const T& obj, const U& value) -> std::any {
        try {
            auto parentValue = std::any_cast<U>(parent(obj));
            return child(parentValue, value);
        }
        catch (const std::bad_any_cast& e) {
            throw std::runtime_error("Type mismatch in compose");
        }
    };
}

template<typename T>
inline bool compare(const T& value, const FilterCondition<T>& condition) {
    switch (condition.op) {
    case ComparisonOperator::EQ:
        return value == condition.value;
    case ComparisonOperator::NE:
        return value != condition.value;
    case ComparisonOperator::GT:
        return value > condition.value;
    case ComparisonOperator::LT:
        return value < condition.value;
    case ComparisonOperator::GTE:
        return value >= condition.value;
    case ComparisonOperator::LTE:
        return value <= condition.value;
    default:
        return false;
    }
}

template<typename T>
inline bool matches(const T& item, const std::vector<RFilter<T>>& filters) {
    if (filters.empty()) return true;

    bool result = true;
    for (const RFilter<T>& filter : filters) {
        std::visit([&](const auto& cond) {
            try {
                using CondType = std::decay_t<decltype(cond.value)>;
                auto value = std::any_cast<CondType>(filter.getter(item));
                result = compare(value, cond);
            }
            catch (const std::bad_any_cast& e) {
                throw std::runtime_error("Type mismatch in filter");
            }
        }, filter.criteria);

        if (!result) {
            return false;
        }
    }

    return true;
}
