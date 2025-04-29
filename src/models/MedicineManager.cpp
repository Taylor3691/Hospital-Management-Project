#include "MedicineManager.h"

MedicineManager::MedicineManager() {

}

MedicineManager::MedicineManager(std::vector<Medicine*>& medicineList) {
    _allMedicines = medicineList;
}

MedicineManager::~MedicineManager() {
    //Destructor
}

void MedicineManager::addMedicine(Medicine* medicine) {
    _allMedicines.push_back(medicine);
}

void MedicineManager::addQuantityById(std::string id, int quantity) {
    for (int i = 0; i < _allMedicines.size(); i++) {
        if (_allMedicines[i]->id() == id) {
            _allMedicines[i]->addStock(quantity);
            return;
        }
    }
}

void MedicineManager::useMedicineById(std::string id, int quantity) {
    for (int i = 0; i < _allMedicines.size(); i++) {
        if (_allMedicines[i]->id() == id) {
            _allMedicines[i]->setQuantity(_allMedicines[i]->quantity() - quantity);
            return;
        }
    }
}

void MedicineManager::useMedicineByName(std::string name, int quantity) {
    for (int i = 0; i < _allMedicines.size(); i++) {
        if (_allMedicines[i]->name() == name) {
            _allMedicines[i]->setQuantity(_allMedicines[i]->quantity() - quantity);
            return;
        }
    }
}

std::vector<Medicine*> MedicineManager::getAllAvailabilityMedicines() {
    std::vector<Medicine*> result;
    for (int i = 0; i < _allMedicines.size(); i++) {
        if (_allMedicines[i]->expiryDate() >= Date::getDate()) {
            result.push_back(_allMedicines[i]);
        }
    }
    return result;
}

std::vector<Medicine*> MedicineManager::getAllExpiredMedicines(){
    std::vector<Medicine*> result;
    for (int i = 0; i < _allMedicines.size(); i++) {
        if (_allMedicines[i]->expiryDate() < Date::getDate()) {
            result.push_back(_allMedicines[i]);
        }
    }
    return result;
}

void MedicineManager::removeMedicine(std::string id) {
    for (int i = 0; i < _allMedicines.size(); i++) {
        if (_allMedicines[i]->id() == id) {
            delete _allMedicines[i];
            _allMedicines.erase(_allMedicines.begin() + i);
            return;
        }
    }
}
