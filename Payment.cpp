#include "Payment.h"
#include <cmath>

// Helper to calculate nights between two dates (YYYY-MM-DD format)
static int calculateNights(const std::string& checkIn, const std::string& checkOut) {
    // Parse dates (simple approach for YYYY-MM-DD format)
    int y1 = std::stoi(checkIn.substr(0, 4));
    int m1 = std::stoi(checkIn.substr(5, 2));
    int d1 = std::stoi(checkIn.substr(8, 2));
    
    int y2 = std::stoi(checkOut.substr(0, 4));
    int m2 = std::stoi(checkOut.substr(5, 2));
    int d2 = std::stoi(checkOut.substr(8, 2));
    
    // Simple day calculation (approximate, works for most cases)
    int days1 = y1 * 365 + m1 * 30 + d1;
    int days2 = y2 * 365 + m2 * 30 + d2;
    
    return std::max(1, days2 - days1); // At least 1 night
}

void Payment::calculateTotalAmount() {
    int nights = calculateNights(reservation->getCheckIn(), reservation->getCheckOut());
    totalAmount = reservation->getRoom()->getPrice() * nights;
}

void Payment::confirmPayment() {
    paymentStatus = "Paid";
    std::cout << "Payment " << idPayment << " confirmed. Amount: " << totalAmount << std::endl;
}
