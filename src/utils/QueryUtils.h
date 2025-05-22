#ifndef QUERY_UTILS_H
#define QUERY_UTILS_H

#include "QueryTypes.h"

template<class ClassType, class ValueType>
inline Getter<ClassType> makeGetter(ValueType(ClassType::* getter)() const) {
    return [getter](const ClassType& obj) -> std::any {
        return (obj.*getter)();
        };
}

template<class ClassType, class ValueType>
inline Getter<ClassType> makeGetter(const ValueType* (ClassType::* getter)() const) {
    return [getter](const ClassType& obj) -> std::any {
        return *(obj.*getter)();
        };
}

template<class ClassType, class ValueType>
inline Setter<ClassType> makeSetter(void(ClassType::* setter)(const ValueType&)) {
    return [setter](const ClassType& obj, const ValueType& value) -> std::any {
        return (obj.*setter)(value);
        };
}

template<class Parent, class Child>
inline Getter<Parent> compose(Getter<Parent> parent, Getter<Child> child) {
    return [parent, child](const Parent& obj) -> std::any {
        try {
            auto parentValue = std::any_cast<Child>(parent(obj));
            return child(parentValue);
        }
        catch (const std::bad_any_cast& e) {
            throw std::runtime_error("Parentype mismatch in compose");
        }
        };
}

template<class Parent, class Child>
inline Setter<Parent> compose(Getter<Parent> parent, Setter<Child> child) {
    return [parent, child](const Parent& obj, const Child& value) -> std::any {
        try {
            auto parentValue = std::any_cast<Child>(parent(obj));
            return child(parentValue, value);
        }
        catch (const std::bad_any_cast& e) {
            throw std::runtime_error("Type mismatch in compose");
        }
        };
}

template<class ValueType>
inline bool compare(const ValueType& value, const FilterCriteria& criteria) {
    if (auto ptr = std::get_if<ValueType>(&criteria.value)) {
        switch (criteria.op) {
        case ComparisonOperator::EQ: return value == *ptr;
        case ComparisonOperator::NE: return value != *ptr;
        case ComparisonOperator::GT: return value > *ptr;
        case ComparisonOperator::LT: return value < *ptr;
        case ComparisonOperator::GTE: return value >= *ptr;
        case ComparisonOperator::LTE: return value <= *ptr;
        default: return false;
        }
    }
    return false;
}

template<class ClassType>
inline bool matches(
    const ClassType& item,
    const std::vector<RFilter<std::remove_const_t<ClassType>>>& filters,
    FilterMode mode = FilterMode::AND
) {
    if (filters.empty()) return true;

    bool result = true;
    for (const RFilter<ClassType>& filter : filters) {
        std::visit([&](const auto& condValue) {
            try {
                using ValueType = std::decay_t<decltype(condValue)>;
                auto value = std::any_cast<ValueType>(filter.getter(item));
                result = compare(value, filter.criteria);
            }
            catch (const std::bad_any_cast&) {
                throw std::runtime_error("Type mismatch in filter");
            }
            }, filter.criteria.value);

        if (mode == FilterMode::OR) {
            if (result) {
                return true;
            }
            else if (!result && &filter == &filters.back()) {
                return false;
            }
        }
        else if (!result) {
            return false;
        }
    }
    return true;
}

#endif // !QUERY_UTILS_H
