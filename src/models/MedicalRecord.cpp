#include "MedicalRecord.h"

MedicalRecord::MedicalRecord() {

}

MedicalRecord::MedicalRecord(std::string id, Patient* patient, Doctor* doctor,
    std::string diagnosis, std::string treatment, std::vector<MedicineUsage> medicine) {

}

MedicalRecord::~MedicalRecord() {

}

std::string MedicalRecord::id() {

}

Patient* MedicalRecord::patient() {

}

Doctor* MedicalRecord::doctor() {

}

std::string MedicalRecord::diagnosis() {

}

std::string MedicalRecord::treatment() {

}

std::vector<MedicineUsage>& MedicalRecord::prescribedMedicines() {

}

bool MedicalRecord::addMedicineUsage(const MedicineUsage&) {

}

bool MedicalRecord::removeMedicineUsage(std::string id) {

}
