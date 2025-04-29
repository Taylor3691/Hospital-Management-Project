#ifndef MEDICINEMANAGER_H_
#define MEDICINEMANAGER_H_
#include "iostream"
#include "../models/Medicine.h"
#include <vector>
class MedicineManager {
private:
    std::vector<Medicine*> _allMedicines;
public:
    MedicineManager();
public:
    ~MedicineManager();
public:
    void addMedicine(Medicine*);
    void addQuantityById(std::string id, int quantity);
    void useMedicineById(std::string id, int quantity);
    void useMedicineByName(std::string name, int quantity);
    std::vector<Medicine*> getAllAvailabilityMedicines();
    std::vector<Medicine*> getAllExpiredMedicines();
    void removeMedicine(std::string id);
public:
};

#endif // !MEDICINEMANAGER_H_
