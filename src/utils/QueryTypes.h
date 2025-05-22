#ifndef QUERY_TYPES_H
#define QUERY_TYPES_H

#include <variant>
#include <string>
#include <functional>
#include <any>
#include "Date.h"
#include "Time.h"

using ValueVariant = std::variant<
    int,
    bool,
    double,
    std::string,
    Date,
    Time
>;

enum class ComparisonOperator {
    EQ,
    NE,
    GT,
    LT,
    GTE,
    LTE
};

enum class FilterMode {
    AND,
    OR
};

struct FilterCriteria {
    ValueVariant value;
    ComparisonOperator op = ComparisonOperator::EQ;
};

template<class ClassType>
using Getter = std::function<std::any(const ClassType&)>;

template<class ClassType>
struct RFilter {
    FilterCriteria criteria;
    Getter<ClassType> getter;
};

template<class ClassType>
using Setter = std::function<void(const ClassType&, const std::any&)>;

template<class ClassType>
struct WFilter : RFilter<ClassType> {
    Setter<ClassType> setter;
};

#endif // !QUERY_TYPES_H
