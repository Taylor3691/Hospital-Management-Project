#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class Config {
private:
    std::map<std::string, std::string> _prototype;
    std::string _filePath;

public:
    Config(const std::string& filePath);

public:
    std::string get(const std::string& property);
    void loadFromFile();
};

#endif // !CONFIG_H
