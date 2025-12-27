#include "Customer.h"

void Customer::showCustomerDetails() const {
    std::cout << "ID: " << idCustomer << ", Name: " << name 
              << ", Email: " << email << std::endl;
}

void Customer::bookRoom(std::shared_ptr<Room> room) {
    std::cout << "Customer " << name << " initiates booking for Room " << room->getId() << std::endl;
}

void Customer::update(const std::string& message) {
    std::cout << "[Notification to " << name << "]: " << message << std::endl;
}
