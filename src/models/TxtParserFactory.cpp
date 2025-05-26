#include "TxtParserFactory.h"
#include "../utils/utils_template.h"

TxtParserFactory::TxtParserFactory(char delim)
    : _prototypes({
        { getIdPrefix<Doctor>(), new TxtDoctorParser(delim) },
        { getIdPrefix<Nurse>(), new TxtNurseParser(delim) },
        { getIdPrefix<Receptionist>(), new TxtReceptionistParser(delim) },
        { getIdPrefix<Department>(), new TxtDepartmentParser(delim) },
        { getIdPrefix<Patient>(), new TxtPatientParser(delim) },
        { getIdPrefix<Medicine>(), new TxtMedicineParser(delim)},
        { getIdPrefix<TestService>(), new TxtTestServiceParser(delim)},
        { getIdPrefix<RoomExamination>(), new TxtRoomExaminationParser(delim)},
        { getIdPrefix<MedicineUsage>(), new TxtMedicineUsageParser(delim)},
        { getIdPrefix<ClinicalTest>(), new TxtClinicalTestParser(delim)},
        { getIdPrefix<MedicalRecord>(), new TxtMedicalRecordParser(delim)},
    }) {}

TxtParserFactory::~TxtParserFactory() {
    for (auto& [key, parser] : _prototypes) {
        delete parser;
    }
}

IParser* TxtParserFactory::getParser(const std::string& type) const {
    auto it = _prototypes.find(type);
    if (it != _prototypes.end()) {
        return it->second;
    }
    return nullptr;
}
