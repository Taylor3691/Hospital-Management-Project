#ifndef UTILS_TEMPLATE_H
#define UTILS_TEMPLATE_H

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <regex>
#include "../models/TxtParserFactory.h"
#include "../models/TxtWritingVisitor.h"

template<typename T>
void load(std::vector<std::unique_ptr<T>>& container,
    char delim, const std::string& fileName);

template<typename T>
void save(const std::vector<std::unique_ptr<T>>& container,
    char delim, const std::string& fileName);

#endif // !UTILS_TEMPLATE_H

template<typename T>
inline void load(
    std::vector<std::unique_ptr<T>>& container,
    char delim,
    const std::string& fileName
) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file `" + fileName + "` for reading");
    }

    TxtParserFactory* factory = new TxtParserFactory(delim);
    IParser* parser = nullptr;
    std::string line;
    while (std::getline(file, line)) {
        std::regex pattern("^(\\w+)-");
        std::smatch matches;

        bool found = std::regex_search(line, matches, pattern);
        if (!found) {
            throw std::runtime_error("Invalid line in `" + fileName + "`");
        }

        parser = factory->getParser(matches[1].str());
        if (!parser) {
            throw std::runtime_error("Invalid line in `" + fileName + "`");
        }

        std::unique_ptr<T> object(dynamic_cast<T*>(parser->parse(line)));
        container.push_back(std::move(object));
    }
    delete factory;

    file.close();
}

template<typename T>
inline void save(
    const std::vector<std::unique_ptr<T>>& container,
    char delim,
    const std::string& fileName
) {
    std::ofstream file(fileName, std::ios::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file `" + fileName + "` for writing");
    }

    IVisitor* visitor = new TxtWritingVisitor(delim);
    for (const auto& obj : container) {
        obj->acceptWrite(visitor, file);
        file << "\n";
    }

    file.close();
}
