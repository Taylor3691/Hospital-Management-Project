#ifndef QUERY_UTILS_H
#define QUERY_UTILS_H

#include "QueryTypes.h"

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
