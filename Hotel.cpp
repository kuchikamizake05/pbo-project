#include "Hotel.h"
#include <iostream>

void Hotel::showRoomList() const {
    std::cout << "\n--- Room List (" << hotelName << ") ---" << std::endl;
    for (const auto& room : roomList) {
        room->showRoomDetails();
    }
}

void Hotel::showReservationList() const {
    std::cout << "\n--- Reservation List ---" << std::endl;
    if (reservationList.empty()) {
        std::cout << "No active reservations." << std::endl;
        return;
    }
    for (const auto& res : reservationList) {
        res->showReservationDetails();
    }
}

void Hotel::createReservation(std::shared_ptr<Customer> customer, std::shared_ptr<Room> room, 
                              std::string checkIn, std::string checkOut) {
    
    // 1. Check availability
    for (const auto& res : reservationList) {
        if (res->getRoom()->getId() == room->getId()) {
            // Check date overlap
            if (Utils::isDateOverlap(checkIn, checkOut, res->getCheckIn(), res->getCheckOut())) {
                std::cout << "[Error] Room " << room->getId() << " is already booked for these dates." << std::endl;
                return;
            }
        }
    }

    // 2. Create Reservation
    auto newRes = std::make_shared<Reservation>(reservationCounter++, customer, room, checkIn, checkOut);
    reservationList.push_back(newRes);

    // 3. Notify Customer (Observer Pattern)
    customer->update("Reservation Confirmed! Room: " + room->getType() + " Dates: " + checkIn + " to " + checkOut);
    
    // 4. Update Room Status
    room->changeRoomStatus("Booked"); 
}

void Hotel::cancelReservation(std::shared_ptr<Customer> customer) {
    // Handle empty list case first
    if (reservationList.empty()) {
        std::cout << "No reservation found for customer " << customer->getName() << std::endl;
        return;
    }

    // STEP 1: First, find and collect all reservations to cancel BEFORE modifying the list
    std::vector<std::shared_ptr<Reservation>> toCancel;
    for (const auto& res : reservationList) {
        if (res->getCustomer()->getId() == customer->getId()) {
            toCancel.push_back(res);
        }
    }

    // STEP 2: Check if any reservations were found
    if (toCancel.empty()) {
        std::cout << "No reservation found for customer " << customer->getName() << std::endl;
        return;
    }

    // STEP 3: Process cancellations (update room status and notify customer)
    for (const auto& res : toCancel) {
        res->getRoom()->changeRoomStatus("Available");
        customer->update("Your reservation for Room " + std::to_string(res->getRoom()->getId()) + " has been cancelled.");
    }

    // STEP 4: Now safely remove from the list using erase-remove idiom
    reservationList.erase(
        std::remove_if(reservationList.begin(), reservationList.end(),
            [&](const std::shared_ptr<Reservation>& res) {
                return res->getCustomer()->getId() == customer->getId();
            }),
        reservationList.end()
    );

    std::cout << "Reservation(s) cancelled for customer " << customer->getName() << std::endl;
}

void Hotel::showSummary() const {
        std::cout << "\n=== HOTEL SUMMARY ===" << std::endl;
        std::cout << "Total Rooms: " << roomList.size() << std::endl;
        showRoomList();
        std::cout << "Total Active Reservations: " << reservationList.size() << std::endl;
}



