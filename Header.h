#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <sstream>

namespace FlightBooking {
	enum SeatClass {
		Economy,
		Business,
		FirstClass
	};

	struct Passenger {
		std::string name;
		std::string destination;
		SeatClass seatClass;
	};

	struct Flight {
		short FlightID;
		std::string destination;
		std::string time;
		short availableSeats;

		// stream  operator for displaying Flight details
		friend std::ostream& operator<<(std::ostream& os, const Flight& flight) {
			os << "Flight ID: " << flight.FlightID
				<< ", Destination: " << flight.destination
				<< ", Time: " << flight.time
				<< ", Available Seats: " << flight.availableSeats;
			return os;
		}
	};

	//Functions
	void displayFlights(Flight flights[], int size);
	int searchFlight(Flight flights[], int size, const std::string& destination);
	Passenger* bookFlight(Flight& flight);
	void displayPassengerDetails(Passenger* passenger);
}
#endif