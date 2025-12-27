#include "Room.h"

// Room Implementation
void Room::showRoomDetails() const {
    std::cout << "ID: " << idRoom << " | Type: " << roomType 
              << " | Price: " << price << " | Status: " << status << std::endl;
}

void Room::changeRoomStatus(const std::string& newStatus) {
    status = newStatus;
}
