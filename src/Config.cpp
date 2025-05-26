#include "Config.h"

Config::Config(const std::string& name) {
    _fileName = name;
}

std::string Config::getPath(const std::string type) {
    auto it = _prototype.find(type);
    if (it != _prototype.end()) {
        return it->second;
    }
    return "null";
}

void Config::loadFromFile() {
    std::ifstream input(_fileName);
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
