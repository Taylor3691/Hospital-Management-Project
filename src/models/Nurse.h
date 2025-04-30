#ifndef NURSE_H
#define NURSE_H

#include "Employee.h"
#include "Shift.h"
#include "Room.h"

class Nurse : public Employee {
private:
    std::vector<Shift*> _shifts;
    std::vector<Room*> _assignedRooms;

public:
    Nurse(const std::string& id, const std::string& name, const Date& dob,
        Department* department, const Date& startWorkingDate);

public:
    std::vector<Shift*> shifts() const;
    std::vector<Room*> assignedRooms() const;

public:
    void addShift(Shift* shift);
    void addRoom(Room* room);
    void removeShift(Shift* shift);
    void removeRoom(Room* room);
};

#endif
