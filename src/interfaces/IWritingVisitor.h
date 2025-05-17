#ifndef IWRITING_VISITOR_H
#define IWRITING_VISITOR_H

#include <iostream>
#include "IVisitor.h"
#include "../models/Doctor.h"
#include "../models/Nurse.h"
#include "../models/Receptionist.h"
#include "../models/Department.h"

class IWritingVisitor : public IVisitor {
public:
    virtual ~IWritingVisitor() = default;

public:
    virtual void write(Doctor* doctor, std::ostream& os) = 0;
    virtual void write(Nurse* nurse, std::ostream& os) = 0;
    virtual void write(Receptionist* receptionist, std::ostream& os) = 0;
    virtual void write(Department* department, std::ostream& os) = 0;
};

#endif // !IWRITING_VISITOR_H
