// project-two.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Header.h"

using namespace std;
using namespace FlightBooking;

int main() {
    const int FLIGHT_COUNT = 3; //Number of flight available

    // Array to manage flight schedules / initialized with fligh details
    Flight flights[FLIGHT_COUNT] = {
        {1, "New York", "9:00 AM", 5},
        {2, "Los Angeles", "2:00 PM", 3},
        {3, "San Francisco", "3:00 PM", 10}
    };

    Passenger* passenger = nullptr; //// Pointer to dynamically manage passenger details
    int choice = 0;

    while (choice != 4) {
        cout << "\nFlight Booking Management System\n";
        cout << "1. View Flights" << endl;
        cout << "2. Search and Book a Fligth" << endl;
        cout << "3. View Passenger Details" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayFlights(flights, FLIGHT_COUNT); //call function to dipsplay flight details
        }
        else if (choice == 2) {
            string destination;
            cout << "Enter destination to search: ";
            cin.ignore();
            getline(cin, destination);

            int flightChoice = searchFlight(flights, FLIGHT_COUNT, destination); //Searching flight using destination name
            if (flightChoice != -1) {
                passenger = bookFlight(flights[flightChoice]); //Book flight if available
            }
            else {
                cout << "No flights available for the entered destination." << endl;
            }
        }
        else if (choice == 3) {
            displayPassengerDetails(passenger); //call function to display booked passenger details 
        }
        else if (choice == 4) {
            cout << "Exiting the system." << endl;
        }
        else {
            cout << "Not in the system. Try again." << endl;
        }
    }

    // Cleanup dynamically allocated memory
    delete passenger;

    return 0;
}
