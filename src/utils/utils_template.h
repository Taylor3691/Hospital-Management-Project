#ifndef UTILS_TEMPLATE_H
#define UTILS_TEMPLATE_H

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <regex>
#include <filesystem>
#include "../models/TxtParserFactory.h"
#include "../models/TxtWritingVisitor.h"

template<typename T>
void load(
    std::vector<std::unique_ptr<T>>& container,
    char delim,
    const std::string& filePath
) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file `" + filePath + "` for reading");
    }

    TxtParserFactory* factory = new TxtParserFactory(delim);
    IParser* parser = nullptr;
    std::string line;
    while (std::getline(file, line)) {
        std::regex pattern("^(\\w+)-");
        std::smatch matches;

        bool found = std::regex_search(line, matches, pattern);
        if (!found) {
            throw std::runtime_error("Invalid line in `" + filePath + "`");
        }

        parser = factory->getParser(matches[1].str());
        if (!parser) {
            throw std::runtime_error("Invalid line in `" + filePath + "`");
        }

        std::unique_ptr<T> object(dynamic_cast<T*>(parser->parse(line)));
        container.push_back(std::move(object));
    }
    delete factory;

    file.close();
}

template<typename T>
void save(
    const std::vector<std::unique_ptr<T>>& container,
    char delim,
    const std::string& filePath
) {
    const std::string tmpFileName = filePath + ".tmp";
    std::ofstream file(tmpFileName, std::ios::trunc | std::ios::out);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file `" + filePath + "` for writing");
    }

    IVisitor* visitor = new TxtWritingVisitor(delim);
    for (const auto& obj : container) {
        obj->acceptWrite(visitor, file);
        file << "\n";
    }

    delete visitor;
    file.flush();
    file.close();

    std::error_code ec;
    std::filesystem::rename(tmpFileName, filePath, ec);
    if (ec) {
        throw std::runtime_error("Cannot rename temp file to target");
    }
}

#endif // !UTILS_TEMPLATE_H
