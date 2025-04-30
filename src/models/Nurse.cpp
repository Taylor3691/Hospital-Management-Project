#include "Nurse.h"

Nurse::Nurse(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    Department* department,
    const Date& startWorkingDate
) : Employee(id, name, dob, department, startWorkingDate) {}

std::vector<Shift*> Nurse::shifts() const {
    return _shifts;
}

std::vector<Room*> Nurse::assignedRooms() const {
    return _assignedRooms;
}

void Nurse::addShift(Shift* shift) {
    _shifts.push_back(shift);
}

void Nurse::addRoom(Room* room) {
    _assignedRooms.push_back(room);
}

void Nurse::removeShift(Shift* shift) {
    auto it = std::find(_shifts.begin(), _shifts.end(), shift);
    _shifts.erase(it);
}

void Nurse::removeRoom(Room* room) {
    auto it = std::find(_assignedRooms.begin(), _assignedRooms.end(), room);
    _assignedRooms.erase(it);
}
