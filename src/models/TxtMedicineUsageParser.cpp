#include "TxtMedicineUsageParser.h"

TxtMedicineUsageParser::TxtMedicineUsageParser(char delim)
    : _delim(delim) {}

Object* TxtMedicineUsageParser::parse(const std::string& line) const {
    MedicineUsage* usage = new MedicineUsage();

    std::string str = line;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') str[i] = _delim;
    }

    std::istringstream stream(str);
    std::string buffer;

    std::getline(stream, buffer, _delim);
    usage->setId(buffer);

    std::getline(stream, buffer, _delim);
    usage->setName(buffer);

    std::getline(stream, buffer, _delim);
    usage->setMedicineId(buffer);

    std::getline(stream, buffer, _delim);
    usage->setPrice(std::stod(buffer));

    std::getline(stream, buffer, _delim);
    usage->setUsedQuantity(std::stoi(buffer));

    std::getline(stream, buffer, _delim);
    usage->setDescription(buffer);

    return usage;
}
