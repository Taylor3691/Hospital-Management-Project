#ifndef QUERYTYPES_H
#define QUERYTYPES_H

#include <variant>
#include <string>
#include <functional>
#include <any>
#include "Date.h"
#include "Time.h"

enum class ComparisonOperator {
    EQ,
    NE,
    GT,
    LT,
    GTE,
    LTE
};

template<typename T>
struct FilterCondition {
    T value;
    ComparisonOperator op = ComparisonOperator::EQ;
};

using FilterCriteria = std::variant<
    FilterCondition<int>,
    FilterCondition<bool>,
    FilterCondition<double>,
    FilterCondition<std::string>,
    FilterCondition<Date>,
    FilterCondition<Time>
>;

template<typename T>
using Getter = std::function<std::any(const T&)>;

template<typename T>
struct RFilter {
    FilterCriteria criteria;
    Getter<T> getter;
};

template<typename T>
using Setter = std::function<void(const T&, const std::any&)>;

template<typename T>
struct WFilter : RFilter<T> {
    Setter<T> setter;
};

#endif // !QUERYTYPES_H
