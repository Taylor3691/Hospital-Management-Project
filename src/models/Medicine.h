#ifndef MEDICINE_H
#define MEDICINE_H

#include "Object.h"
#include "TxtWritingVisitor.h"

class Medicine : public Object {
private:
    std::string _unit;
    double _pricePerUnit;
    int _quantity;

public:
    Medicine();
    Medicine(const std::string& id, const std::string& name,
        const std::string& unit, double price, int quantity);

public:
    std::string unit() const;
    double pricePerUnit() const;
    int quantity() const;

public:
    void setUnit(const std::string& unit);
    void setPricePerUnit(double price);
    void setQuantity(int quantity);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;
};

#endif
