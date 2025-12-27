#include "Reservation.h"

// Note: Ensure string includes are handled
#include <iostream>

void Reservation::showReservationDetails() const {
    std::cout << "Res ID: " << idReservation << "\n" 
              << "   Customer: " << customer->getName() << "\n"
              << "   Room: " << room->getType() << " (ID: " << room->getId() << ")\n"
              << "   Check-In: " << checkInDate << " | Check-Out: " << checkOutDate << std::endl;
}

void Reservation::cancelReservation() {
    std::cout << "Reservation " << idReservation << " cancelled." << std::endl;
}
