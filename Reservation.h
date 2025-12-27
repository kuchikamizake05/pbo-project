#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <memory>
#include <iostream> 
// Ideally remove iostream from header if not used in declaration, but used for size_t or output operators in templates
// Keeping it for now as it's safe.

#include "Customer.h"
#include "Room.h"

class Reservation {
private:
    int idReservation;
    std::shared_ptr<Customer> customer;
    std::shared_ptr<Room> room;
    std::string checkInDate;
    std::string checkOutDate;

public:
    Reservation(int id, std::shared_ptr<Customer> c, std::shared_ptr<Room> r, 
                std::string in, std::string out)
        : idReservation(id), customer(c), room(r), checkInDate(in), checkOutDate(out) {}

    void showReservationDetails() const;
    void cancelReservation();

    std::shared_ptr<Room> getRoom() const { return room; }
    std::string getCheckIn() const { return checkInDate; }
    std::string getCheckOut() const { return checkOutDate; }
    int getId() const { return idReservation; }
    std::shared_ptr<Customer> getCustomer() const { return customer; }
};

#endif // RESERVATION_H
