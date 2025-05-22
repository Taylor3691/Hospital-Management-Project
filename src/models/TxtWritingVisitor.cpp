#include "TxtWritingVisitor.h"
#include <sstream>
#include <string>
#include <iomanip>
TxtWritingVisitor::TxtWritingVisitor(char delim)
    : _delim(delim) {}

void TxtWritingVisitor::write(Doctor* doctor, std::ostream& os) {
    os << doctor->id() << _delim
        << doctor->name() << _delim
        << doctor->gender() << _delim
        << doctor->address() << _delim
        << doctor->phone() << _delim
        << doctor->dob() << _delim
        << doctor->education() << _delim
        <<std::fixed<< std::setprecision(2)
        << doctor->baseSalary() << _delim
        << doctor->specialty() << _delim
        << doctor->license();
}

void TxtWritingVisitor::write(Nurse* nurse, std::ostream& os) {
    os << nurse->id() << _delim
        << nurse->name() << _delim
        << nurse->gender()<<_delim
        << nurse->address() << _delim
        << nurse->phone() << _delim
        << nurse->dob() << _delim
        << nurse->education() << _delim
        << std::fixed << std::setprecision(2)
        << nurse->baseSalary() << _delim
        << nurse->duty();
}

void TxtWritingVisitor::write(Receptionist* receptionist, std::ostream& os) {
    os << receptionist->id() << _delim
        << receptionist->name() << _delim
        << receptionist->gender()<<_delim
        << receptionist->address() << _delim
        << receptionist->phone() << _delim
        << receptionist->dob() << _delim
        << receptionist->education() << _delim
        << std::fixed << std::setprecision(2)
        << receptionist->baseSalary() << _delim
        << std::fixed << std::setprecision(2)
        << receptionist->subsidies() << _delim
        << std::fixed << std::setprecision(2)
        << receptionist->workingDays();
}

void TxtWritingVisitor::write(Department* department, std::ostream& os) {
    os << department->id() << _delim
        << department->name() << _delim
        << department->headId() << _delim
        << department->foundationDate() << _delim
        << department->description();
}

void TxtWritingVisitor::write(Patient* patient, std::ostream& os) {
    os << patient->id() << _delim
        << patient->name() << _delim
        << patient->gender() << _delim
        << patient->address() << _delim
        << patient->phone() << _delim
        << patient->dob() << _delim;
        if (patient->insuranceCard() != nullptr) {
            os << patient->insuranceCard()->cardNumber() << ','
                << patient->insuranceCard()->issueDate() << ','
                << patient->insuranceCard()->expiryDate() << ','
                << std::fixed << std::setprecision(2)
                << patient->insuranceCard()->coveragePercent();
        }else{
            os << "null";
        }
    os << _delim;
    for (int i = 0; i < patient->symptoms().size(); i++) {
        os << patient->symptoms()[i];
        if(i != patient->symptoms().size() - 1) {
            os << ',';
        }
    }
}

void TxtWritingVisitor::write(Medicine* medicine, std::ostream& os) {
    os << medicine->id() << _delim
        << medicine->name() << _delim
        << medicine->unit() << _delim
        << std::fixed << std::setprecision(2)
        << medicine->pricePerUnit() << _delim
        << std::fixed << std::setprecision(2)
        << medicine->quantity();
}
