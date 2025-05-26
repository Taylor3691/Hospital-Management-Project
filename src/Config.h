#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class Config {
private:
    std::map<std::string, std::string> _prototype;
    std::string _fileName;

public:
    Config(const std::string& name);

public:
    std::string getPath(const std::string type);
    void loadFromFile();

};


#endif // !CONFIG_H_
