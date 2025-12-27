#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Utils.h"

class Hotel {
private:
    std::string hotelName;
    std::string hotelAddress;
    std::vector<std::shared_ptr<Room>> roomList;
    std::vector<std::shared_ptr<Reservation>> reservationList;
    int reservationCounter;

public:
    Hotel(std::string name, std::string address) 
        : hotelName(name), hotelAddress(address), reservationCounter(1) {}

    void addRoom(std::shared_ptr<Room> room) {
        roomList.push_back(room);
    }

    void showRoomList() const;
    void showReservationList() const;
    void createReservation(std::shared_ptr<Customer> customer, std::shared_ptr<Room> room, 
                           std::string checkIn, std::string checkOut);
    void cancelReservation(std::shared_ptr<Customer> customer);
    void showSummary() const;
};

#endif // HOTEL_H
