#include "Config.h"

Config::Config(const std::string& filePath) {
    _filePath = filePath;
}

std::string Config::get(const std::string& property) {
    auto it = _prototype.find(property);
    if (it != _prototype.end()) {
        return it->second;
    }
    return "null";
}

void Config::loadFromFile() {
    std::ifstream input(_filePath);
    std::string buffer;

    while (std::getline(input, buffer)) {
        std::stringstream stream(buffer);
        std::string key;
        std::getline(stream, key, '=');
        std::string value;
        std::getline(stream, value, '=');
        _prototype[key] = value;
    }
}
