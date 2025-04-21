#ifndef NURSE_H
#define NURSE_H

#include "Employee.h"
#include "Shift.h"
#include "Room.h"
#include "Patient.h"

class Nurse : public Employee {
private:
    std::vector<Shift*> _shifts;
    std::vector<Room*> _assignedRooms;

public:
    Nurse(const std::string& shifts, const std::string& rooms);

    double calculateSalary() override;
    void checkPatientStatus(const Patient& patient);
    void updateRoomStatus(const Room& room);
};

#endif
