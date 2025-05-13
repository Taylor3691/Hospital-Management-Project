// TxtDepartmentRepository.cpp
#include "TxtDepartmentRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>

TxtHouseholdRepository::TxtDepartmentRepository() : _fileName("departments.txt") {
    load();
}

TxtDepartmentRepository::TxtDepartmentRepository(const std::string& fileName) : _fileName(fileName) {
    load();
}

void TxtDepartmentRepository::add(Department* department) {
    _departments.push_back(department);
    save();
}

void TxtDepartmentRepository::remove(const std::string& id) {
    _departments.erase(
        std::remove_if(_departments.begin(), _departments.end(),
            [&id](Department* dept) { return dept->id() == id; }),
        _departments.end()
    );
    save();
}

Department* TxtDepartmentRepository::find(const std::string& id) {
    for (Department* dept : _departments) {
        if (dept->id() == id) {
            return dept;
        }
    }
    return nullptr;
}

std::vector<Department*> TxtDepartmentRepository::findAll() {
    return _departments;
}

void TxtDepartmentRepository::save() {
    std::ofstream outFile(_fileName);
    if (!outFile.is_open()) {
        throw std::runtime_error("Cannot open file: " + _fileName);
    }

    for (const Department* dept : _departments) {
        outFile << dept->id() << "|"
                << dept->name() << "|"
                << dept->getHeadId() << "|"
                << formatDate(dept->getFoundedDay()) << "|"
                << dept->getSubscription() << "\n";
    }
    outFile.close();
}

void TxtDepartmentRepository::load() {
    // Xóa dữ liệu cũ để tránh rò rỉ bộ nhớ
    for (Department* dept : _departments) {
        delete dept;
    }
    _departments.clear();

    std::ifstream inFile(_fileName);
    if (!inFile.is_open()) {
        return; // File không tồn tại, khởi tạo rỗng
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string id, name, headId, foundedDayStr, subscription;

        std::getline(ss, id, '|');
        std::getline(ss, name, '|');
        std::getline(ss, headId, '|');
        std::getline(ss, foundedDayStr, '|');
        std::getline(ss, subscription, '|');

        std::tm foundedDay = parseDate(foundedDayStr);
        Department* dept = new Department(id, name, headId, foundedDay, subscription);
        _departments.push_back(dept);
    }
    inFile.close();
}

std::tm TxtDepartmentRepository::parseDate(const std::string& dateStr) {
    std::tm date = {};
    std::stringstream ss(dateStr);
    int year, month, day;
    char dash;
    ss >> year >> dash >> month >> dash >> day;
    date.tm_year = year - 1900; // std::tm tính năm từ 1900
    date.tm_mon = month - 1;    // std::tm tính tháng từ 0
    date.tm_mday = day;
    return date;
}

std::string TxtDepartmentRepository::formatDate(const std::tm& date) {
    std::stringstream ss;
    ss << (date.tm_year + 1900) << "-"
       << (date.tm_mon + 1) << "-"
       << date.tm_mday;
    return ss.str();
}

TxtDepartmentRepository::~TxtDepartmentRepository() {
    for (Department* dept : _departments) {
        delete dept;
    }
}