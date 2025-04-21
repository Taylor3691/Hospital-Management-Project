#ifndef ROOM_H
#define ROOM_H

#include <string>
#include<iostream>
#include "Department.h"  // Nếu Room liên kết với Department

class Room {
private:
    std::string roomId;
    Department* department;  // Liên kết với Department
    int floor;
    double rent;
public:
    Room(std::string id, Department* dept, int fl, double r)
        : roomId(id), department(dept), floor(fl), rent(r) {}

    void displayInfo() {
        std::cout << "Room ID: " << roomId << std::endl;
        std::cout << "Floor: " << floor << std::endl;
        std::cout << "Rent: " << rent << std::endl;
    }
};

#endif
