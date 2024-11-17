#include <iostream>
#include "Header.h"

using namespace std;


namespace FlightBooking {
    // Function to display all available flights
    void displayFlights(Flight flights[], int size) {
        cout << "\nAvailable Flights:\n";
        for (int i = 0; i < size; ++i) {
            cout << flights[i] << endl;
        }
    }

    // Function to search a flight by destination name
    int searchFlight(Flight flights[], int size, const string& destination) {
        for (int i = 0; i < size; ++i) {
            if (flights[i].destination == destination && flights[i].availableSeats > 0) {
                return i;
            }
        }
        return -1;
    }

    // Function to book a flight 
   Passenger* bookFlight(Flight& flight) {
        if (flight.availableSeats <= 0) {
            cout << "No seats available on this flight." << endl;
            return nullptr;
        }

        Passenger* newPassenger = new Passenger;
        cout << "Enter passenger name: ";
        getline(cin, newPassenger->name);

        newPassenger->destination = flight.destination;

        int seatClassChoice;
        cout << "Choose seat class (0: Economy, 1: Business, 2: First Class): ";
        cin >> seatClassChoice;
        newPassenger->seatClass = static_cast<SeatClass>(seatClassChoice);

        flight.availableSeats--;
        cout << "Booking confirmed for " << newPassenger->name
            << " on flight to " << flight.destination << endl;

        return newPassenger;
    }

    // Function to display passenger details
    void displayPassengerDetails(Passenger* passenger) {
        if (!passenger) {
            cout << "No passenger details available." << endl;
        }

        cout << "\nPassenger Details:\n";
        cout << "Name: " << passenger->name << endl;
        cout << "Destination: " << passenger->destination << endl;
        cout << "Seat Class: ";
        switch (passenger->seatClass) {
        case Economy: cout << "Economy" << endl;
            break;
        case Business: cout << "Business" << endl;
            break;
        case FirstClass: cout << "First Class" << endl;
            break;
        }
    }
}



