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
    Nurse(const std::string& id, const std::string& name, const Date& dob,
        const Department& department, const Date& startWorkingAt, double salary);

    double calculateSalary() override;
    void checkPatientStatus(const Patient& patient); // should be in `Patient` class
    void updateRoomStatus(const Room& room); // should be in `Room` class
};

#endif
