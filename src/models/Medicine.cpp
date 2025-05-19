#include "Medicine.h"

Medicine::Medicine()
    : _pricePerUnit(), _quantity() {}

Medicine::Medicine(
    const std::string& id,
    const std::string& name,
    const std::string& unit,
    double price,
    int quantity
)
    : Object(id, name)
    , _unit(unit)
    , _pricePerUnit(price)
    , _quantity(quantity) {}

std::string Medicine::unit() const {
    return _unit;
}

double Medicine::pricePerUnit() const {
    return _pricePerUnit;
}

int Medicine::quantity() const {
    return _quantity;
}

void Medicine::setUnit(const std::string& unit) {
    _unit = unit;
}

void Medicine::setPricePerUnit(double price) {
    _pricePerUnit = price;
}

void Medicine::setQuantity(int quantity) {
    _quantity = quantity;
}
