#ifndef TXT_PARSER_FACTORY_H
#define TXT_PARSER_FACTORY_H

#include <map>
#include "../interfaces/IParserFactory.h"
#include "TxtDoctorParser.h"
#include "TxtNurseParser.h"
#include "TxtReceptionistParser.h"
#include "TxtDepartmentParser.h"
#include "TxtPatientParser.h"
#include "TxtMedicineParser.h"
#include "TxtTestServiceParser.h"
#include "TxtRoomExaminationParser.h"
#include "TxtMedicalRecordParser.h"

class TxtParserFactory : public IParserFactory {
private:
    std::map<std::string, IParser*> _prototypes;

public:
    TxtParserFactory(char delim = '|');
    ~TxtParserFactory();

public:
    IParser* getParser(const std::string& type) const override;
};

#endif // !TXT_PARSER_FACTORY_H
