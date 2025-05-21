#include "TxtPatientRepository.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

TxtPatientRepository::TxtPatientRepository()
    : _filePath("patients.txt"), _delim('|') {
}

TxtPatientRepository::TxtPatientRepository(const std::string& filePath, char delim) : _filePath(filePath), _delim(delim) {
}

const std::string& TxtPatientRepository::fileName() const {
    return _filePath;
}

void TxtPatientRepository::setFileName(const std::string& filePath) {
    _filePath = filePath;
}

char TxtPatientRepository::delim() const {
    return _delim;
}

void TxtPatientRepository::setDelim(char delim) {
    _delim = delim;
}

void TxtPatientRepository::save() const {
    ::save(_patients, _delim, _filePath);
}

void TxtPatientRepository::load() {
    _patients.clear();
    ::load(_patients, _delim, _filePath);
}

void TxtPatientRepository::add(std::unique_ptr<Patient> patient) {
    _patients.push_back(std::move(patient));
    save();
}

void TxtPatientRepository::removeById(const std::string& id) {
    auto it = std::remove_if(_patients.begin(), _patients.end(),
        [&id](const std::unique_ptr<Patient>& patient) { return patient->id() == id; });
    _patients.erase(it, _patients.end());
    save();
}

void TxtPatientRepository::update(const Patient& patient) {
    auto ptr = from(_patients)
        .where(&Patient::id, patient.id()).findOne();
    if (ptr) {
        *ptr = patient;
    } else {
        throw std::runtime_error("Patient not found");
    }
    save();
}

std::vector<const Patient*> TxtPatientRepository::data() const {
    std::vector<const Patient*> result;
    for (const auto& patient : _patients) {
        result.push_back(patient.get());
    }
    return result;  
}
