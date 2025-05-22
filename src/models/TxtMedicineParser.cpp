#include "TxtMedicineParser.h"

TxtMedicineParser::TxtMedicineParser(char delim) : _delim(delim) {}

Object* TxtMedicineParser::parse(const std::string& str) const {
    auto medicine = new Medicine();

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    medicine->setId(buffer);

    std::getline(stream, buffer, _delim);
    medicine->setName(buffer);

    std::getline(stream, buffer, _delim);
    medicine->setUnit(buffer);

    std::getline(stream, buffer, _delim);
    medicine->setPricePerUnit(stod(buffer));

    std::getline(stream, buffer, _delim);
    medicine->setQuantity(stoi(buffer));

    return medicine;
}
