ticket : flightsclass.h bookingsclass.h functions.h flightsclass.cpp bookingsclass.cpp functions.cpp main.cpp
	g++ main.cpp flightsclass.cpp bookingsclass.cpp functions.cpp -o main
	
check : ticket
	./main -f flights.csv -b bookingsfile.csv

dist : ticket
	gzip ticket
	
distcheck : dist
	gunzip ticket.gz