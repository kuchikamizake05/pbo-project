#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <memory>
#include <iostream>
#include "Reservation.h"

class Payment {
private:
    int idPayment;
    std::shared_ptr<Reservation> reservation;
    double totalAmount;
    std::string paymentStatus;

public:
    Payment(int id, std::shared_ptr<Reservation> res) 
        : idPayment(id), reservation(res), paymentStatus("Pending") {
        calculateTotalAmount();
    }

    void calculateTotalAmount();
    void confirmPayment();
    
    double getAmount() const { return totalAmount; }
    std::string getStatus() const { return paymentStatus; }
};

#endif // PAYMENT_H
