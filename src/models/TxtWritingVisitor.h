#ifndef TXT_WRITING_VISITOR_H
#define TXT_WRITING_VISITOR_H

#include "../interfaces/IWritingVisitor.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Receptionist.h"
#include "Department.h"

class TxtWritingVisitor : public IWritingVisitor {
private:
    char _delim;

public:
    TxtWritingVisitor(char delim = '|');

public:
    void write(Doctor* doctor, std::ostream& os) override;
    void write(Nurse* nurse, std::ostream& os) override;
    void write(Receptionist* receptionist, std::ostream& os) override;
    void write(Department* department, std::ostream& os) override;
};

#endif // !TXT_WRITING_VISITOR_H
