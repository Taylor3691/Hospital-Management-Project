#ifndef QUERYTYPES_H
#define QUERYTYPES_H

#include <variant>
#include <string>
#include <functional>
#include <any>
#include "Date.h"
#include "Time.h"

enum class ComparisonOp {
    EQ,
    NE,
    GT,
    LT,
    GTE,
    LTE
};

template<typename T>
struct Condition {
    T value;
    ComparisonOp op = ComparisonOp::EQ;
};

using ConditionValue = std::variant<
    Condition<int>,
    Condition<bool>,
    Condition<double>,
    Condition<std::string>,
    Condition<Date>,
    Condition<Time>
>;

template<typename T>
using Getter = std::function<std::any(const T&)>;

template<typename T>
struct Filter {
    Getter<T> getter;
    ConditionValue value;
};

#endif
