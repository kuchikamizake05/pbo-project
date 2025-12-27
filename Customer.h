#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <memory>
#include "Room.h"

// Observer Interface (Behavioral Pattern)
class IObserver {
public:
    virtual void update(const std::string& message) = 0;
};

class Customer : public IObserver {
private:
    int idCustomer;
    std::string name;
    std::string email;
    std::string phoneNumber;

public:
    Customer(int id, std::string n, std::string e, std::string p)
        : idCustomer(id), name(n), email(e), phoneNumber(p) {}

    void showCustomerDetails() const;
    void bookRoom(std::shared_ptr<Room> room);
    void update(const std::string& message) override;

    std::string getName() const { return name; }
    int getId() const { return idCustomer; }
};

#endif // CUSTOMER_H
