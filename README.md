# Hotel Reservation System (OOP Project)

A simple Hotel Reservation System built using C++ applying Object-Oriented Programming (OOP) principles.

## Key Features
- **Room Management**: Supports various room types (Deluxe, Superior, Suite) using the *Factory Pattern*.
- **Customer Management**: Registration and management of hotel guest data.
- **Reservation System**: Process for room bookings, cancellations, and availability status checks.
- **Hotel Summary**: Displays a summary of the hotel's operational status.

## Project Structure
- `Hotel.h/cpp`: Core hotel management logic.
- `Room.h/cpp`: Room representations and factory for creating room types.
- `Customer.h/cpp`: Guest data management.
- `Reservation.h/cpp`: Reservation transaction logic.
- `Payment.h/cpp`: Payment process handling.
- `Utils.h/cpp`: Helper/utility functions.
- `main.cpp`: CLI (Command Line Interface) for the application.

## How to Run
1. Ensure you have a C++ compiler installed (e.g., `g++`).
2. Clone this repository:
   ```bash
   git clone https://github.com/kuchikamizake05/pbo-project.git
   ```
3. Compile the code:
   ```bash
   g++ -o hotel main.cpp Hotel.cpp Room.cpp Customer.cpp Reservation.cpp Payment.cpp Utils.cpp
   ```
4. Run the application:
   ```bash
   ./hotel
   ```

## Applied OOP Principles
- **Encapsulation**: Each class hides implementation details.
- **Inheritance & Polymorphism**: Implemented in the room type structure.
- **Abstraction**: Simplifies complex reservation logic into a user-friendly interface.
- **Factory Pattern**: Used for creating room objects.
