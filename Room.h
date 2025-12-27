#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include <memory>

// Abstract Base Class (OCP: Open for extension)
class Room {
protected:
    int idRoom;
    std::string roomType;
    double price;
    std::string status; // "Available", "Booked"
    int capacity;

public:
    Room(int id, std::string type, double p, int cap) 
        : idRoom(id), roomType(type), price(p), capacity(cap), status("Available") {}
    
    virtual ~Room() {}

    virtual void showRoomDetails() const;

    void changeRoomStatus(const std::string& newStatus);

    int getId() const { return idRoom; }
    std::string getStatus() const { return status; }
    std::string getType() const { return roomType; }
    double getPrice() const { return price; }
};

// Concrete Classes (LSP: Substitutable for Room)
class DeluxeRoom : public Room {
public:
    DeluxeRoom(int id) : Room(id, "Deluxe", 500000, 2) {}
};

class SuperiorRoom : public Room {
public:
    SuperiorRoom(int id) : Room(id, "Superior", 750000, 2) {}
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int id) : Room(id, "Suite", 1500000, 4) {}
};

// Factory Method Pattern (Creational)
class RoomFactory {
public:
    static std::shared_ptr<Room> createRoom(const std::string& type, int id) {
        if (type == "Deluxe") return std::make_shared<DeluxeRoom>(id);
        if (type == "Superior") return std::make_shared<SuperiorRoom>(id);
        if (type == "Suite") return std::make_shared<SuiteRoom>(id);
        return nullptr;
    }
};

#endif // ROOM_H
