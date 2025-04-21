#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>

class Appointment {
public:
    friend std::ostream& operator<<(std::ostream& os, const Appointment& appointment);
};

#endif
