ticket : flight_informations.hh booking_informations.hh functions.hh flight_informations.cpp booking_informations.cpp functions.cpp main.cpp
	g++ main.cpp flight_informations.cpp booking_informations.cpp functions.cpp -o main
	
check : ticket
	./main -f flights.csv -b bookingsfile.csv

dist : ticket
	gzip ticket
	
distcheck : dist
	gunzip ticket.gz
