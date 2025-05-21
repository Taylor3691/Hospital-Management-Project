#include "TxtParserFactory.h"

TxtParserFactory::TxtParserFactory(char delim)
    : _prototypes({
        { "BS", new TxtDoctorParser(delim) },
        { "YT", new TxtNurseParser(delim) },
        { "TT", new TxtReceptionistParser(delim) },
        { "DEPT", new TxtDepartmentParser(delim) },
        { "BN", new TxtPatientParser(delim) },
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
