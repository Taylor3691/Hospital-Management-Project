#include "TxtPatientRepository.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>


TxtPatientRepository::TxtPatientRepository(const std::string& filePath) : _filePath(filePath) {
    load();
}

TxtPatientRepository::~TxtPatientRepository() {
    save();
}

void TxtPatientRepository::save() const {
    std::ofstream file(_filePath, std::ios::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open patient file for writing");
    }

    for(auto const& patient : _patients) {
        file << patient->id() << "|" << patient->name() << "|" << patient->age() << "|"
            << patient->gender() << "|" << patient->address() << "|"
            << patient->phone()<<"|";
        for(int i = 0; i < patient->allergies().size(); i++) {
            file << patient->allergies()[i];
            if(i != patient->allergies().size() - 1) {
                file << ",";
            }
        }
        file << "|";
        for(int i = 0; i < patient->symptoms().size(); i++) {
            file << patient->symptoms()[i];
            if(i != patient->symptoms().size() - 1) {
                file << ",";
            }
        }
    }
    file.close();
}

void TxtPatientRepository::load() {
    std::ifstream file(_filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open patient file for reading");
    }

    std::string line;
    while (std::getline(file, line,'|')) {
        auto patient = std::make_unique<Patient>();
        std::string symtoms;
        std::string allergies;
        std::stringstream ss(line);
        std::string buffer;
        std::getline(ss, buffer, '|');
        patient->setId(buffer);
        std::getline(ss, buffer, '|');
        patient->setName(buffer);
        std::getline(ss, buffer, '|');
        patient->setDob(buffer);
        std::getline(ss, buffer, '|');
        patient->setGender(buffer);
        std::getline(ss, buffer, '|');
        patient->setPhone(buffer);
        std::getline(ss, buffer, '|');
        patient->setAddress(buffer);
        std::getline(ss, allergies, '|');
        std::getline(ss, symtoms, '|');
        std::stringstream ssAllergies(allergies);
        std::string allergy;
        while (std::getline(ssAllergies, allergy, ',')) {
            patient->addAllergy(allergy);
        }
        std::stringstream ssSymptoms(symtoms);
        std::string symptom;
        while (std::getline(ssSymptoms, symptom, ',')) {
            patient->addSymptom(symptom);
        }
    }
    file.close();
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
