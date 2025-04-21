#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <iostream>

class MedicalRecord{
public:
    friend std::ostream& operator<<(std::ostream& os, const MedicalRecord& record);
};

#endif
