#include <iostream>
#include <memory>
#include <limits>
#include <vector>
#include "Hotel.h"
#include "Room.h"
#include "Customer.h"

using namespace std;

// Helper to pause
void waitForKey() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer from previous input
    cin.get();
}

int main() {
    Hotel myHotel("Hotel Merdeka", "Jl. Proklamasi No. 17");

    // Local storage to access objects for booking
    vector<shared_ptr<Room>> allRooms;
    allRooms.push_back(RoomFactory::createRoom("Deluxe", 101));
    allRooms.push_back(RoomFactory::createRoom("Superior", 102));
    allRooms.push_back(RoomFactory::createRoom("Suite", 103));

    // Register rooms to Hotel
    for (const auto& r : allRooms) {
        myHotel.addRoom(r);
    }

    vector<shared_ptr<Customer>> customers;
    customers.push_back(make_shared<Customer>(1, "Budi", "budi@mail.com", "0811"));
    customers.push_back(make_shared<Customer>(2, "Siti", "siti@mail.com", "0812"));

    int choice;
    do {
        // Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "=== HOTEL RESERVATION SYSTEM ===" << endl;
        cout << "1. Tampilkan Kamar" << endl;
        cout << "2. Tampilkan Customer" << endl;
        cout << "3. Buat Reservasi" << endl;
        cout << "4. Batalkan Reservasi" << endl;
        cout << "5. Tampilkan Status Reservasi" << endl;
        cout << "6. Summary Hotel" << endl;
        cout << "0. Keluar" << endl;
        cout << ">> ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                myHotel.showRoomList();
                waitForKey();
                break;
            case 2:
                cout << "\n--- Customer List ---" << endl;
                for (const auto& c : customers) {
                    c->showCustomerDetails();
                }
                waitForKey();
                break;
            case 3: {
                int custId, roomId;
                string dateIn, dateOut;
                
                cout << "\n--- Form Reservasi ---" << endl;
                cout << "Customer ID : "; cin >> custId;
                cout << "Room ID     : "; cin >> roomId;
                cout << "Check-In (YYYY-MM-DD)  : "; cin >> dateIn;
                cout << "Check-Out (YYYY-MM-DD) : "; cin >> dateOut;

                // Find pointers
                shared_ptr<Customer> selCust = nullptr;
                shared_ptr<Room> selRoom = nullptr;

                for (const auto& c : customers) if (c->getId() == custId) selCust = c;
                for (const auto& r : allRooms)  if (r->getId() == roomId) selRoom = r;

                if (selCust && selRoom) {
                    cout << "Processing..." << endl;
                    myHotel.createReservation(selCust, selRoom, dateIn, dateOut);
                } else {
                    cout << "[Error] Customer ID or Room ID not found!" << endl;
                }
                waitForKey();
                break;
            }
            case 4: {
                int custId;
                cout << "\n--- Batalkan Reservasi ---" << endl;
                cout << "Customer ID : "; cin >> custId;
                
                shared_ptr<Customer> selCust = nullptr;
                for (const auto& c : customers) if (c->getId() == custId) selCust = c;

                if (selCust) {
                    myHotel.cancelReservation(selCust);
                } else {
                    cout << "[Error] Customer ID not found!" << endl;
                }
                waitForKey();
                break;
            }
            case 5:
                myHotel.showReservationList();
                waitForKey();
                break;
            case 6:
                myHotel.showSummary();
                waitForKey();
                break;
        }
    } while (choice != 0);

    return 0;
}
