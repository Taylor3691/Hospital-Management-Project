#ifndef MEDICINEUSAGE_H
#define MEDICINEUSAGE_H

#include "Medicine.h"

class MedicineUsage {
private:
    Medicine _medicine;
    int _dosage;
    std::pair<int, std::string> _frequency;
    std::string _instructions;

public:
    MedicineUsage();
    MedicineUsage(const Medicine& medicine, int dosage, std::pair<int, std::string> frequency, std::string instruction);
    ~MedicineUsage();

public:
    std::string getMedicineInfo();
    std::string getInstructions();
    void setMedicine(Medicine& medicine);
    void setInstructions(std::string instruction);
};

#endif // !MEDICINEUSAGE_H_
