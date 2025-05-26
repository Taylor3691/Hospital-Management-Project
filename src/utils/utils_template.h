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

template<typename T>
int compare(const T& a, const T& b) {
    return a == b ? 0 : (a < b ? -1 : 1);
}

template<class T>
const char* getIdPrefix();

template<>
inline const char* getIdPrefix<Doctor>() {
    return "BS";
}

template<>
inline const char* getIdPrefix<Nurse>() {
    return "YT";
}

template<>
inline const char* getIdPrefix<Receptionist>() {
    return "TT";
}

template<>
inline const char* getIdPrefix<Department>() {
    return "DEPT";
}

template<>
inline const char* getIdPrefix<Patient>() {
    return "BN";
}

template<>
inline const char* getIdPrefix<Medicine>() {
    return "ME";
}

template<>
inline const char* getIdPrefix<TestService>() {
    return "CLS";
}

template<>
inline const char* getIdPrefix<RoomExamination>() {
    return "PHG";
}

template<>
inline const char* getIdPrefix<MedicineUsage>() {
    return "MEUSE";
}

template<>
inline const char* getIdPrefix<ClinicalTest>() {
    return "CLSUSE";
}

template<>
inline const char* getIdPrefix<MedicalRecord>() {
    return "HS";
}

template<class T>
inline std::string getFormat() {
    return std::string(getIdPrefix<T>()) + "-%03d";
}

#endif // !UTILS_TEMPLATE_H
