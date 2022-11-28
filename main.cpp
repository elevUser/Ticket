/**
 * @file main.cpp
 * @author Mohib Akbari (mohibali.akbari@studerande.movant.se)
 * @brief Program to print out tickets
 * @version 1
 * @date 2022-11-24
 *
 * @copyright NULL
 *
 */
#include <iostream>
#include <list>
#include <unistd.h>
#include "functions.hh"
#include "flight_informations.hh"
#include "booking_informations.hh"
using namespace std;

/**
 * Main entry point of the program.
 * @param[in] argc Number of command line arguments.
 * @param[in] argv An array of pointers to null terminated arrays of characters (command line arguments).
 * @param[out] return 0 on success.
 */
int main(int argc, char **argv)
{
    /**
     * @brief Declare variables
     */
    char *flightCsv = NULL;
    char *bookingCsv = NULL;
    int option;

    /**
     * @brief Get file names with getopt function
     * -f flight file name
     * -b booking file name
     */
    while ((option = getopt(argc, argv, "f:b:h")) != -1)
    {
        switch (option)
        {
        case 'f':
            flightCsv = optarg;
            break;
        case 'b':
            bookingCsv = optarg;
            break;
        case '?':
            cout << "Usage: " << argv[0] << "\n\t-f {flights.csv}\n\t-b {bookingsfile.csv}" << endl;
            exit(-1);
            break;
        default:
            cout << "Usage: " << argv[0] << "\n\t-f {flights.csv}\n\t-b {bookingsfile.csv}" << endl;
            exit(-1);
            break;
        }
    }

    /**
     * @brief Declare flight list and booking list
     */
    list<flight_informations *> flights;
    list<booking_informations *> bookings;
    /**
     * @brief Call funtion flight_list
     * @param[in] flightCsv Name of flight file
     * @param[in] flights Flight list
     */
    flight_list(flightCsv, &flights);
    cout << "Reading flight_information...\n";
    /**
     * @brief Call function booking_list
     * @param[in] bookingCsv Name of booking file
     * @param[in] bookings Booking list
     */
    booking_list(bookingCsv, &bookings);
    cout << "Reading bookings...\n";
    /**
     * @brief Call function printTicket
     * @param[in] flights Flight list
     * @param[in] bookings Booking list
     */
    printTickets(flights, bookings);
    cout << "Printing tickets...\n";
    /**
     * @brief Call function cancelFlights
     * @param[in] flights Flight list
     */
    cancelFlights(flights);
    cout << "Cancel flights...\n";
    /**
     * @brief Call function seatingChart
     * @param[in] flights Flight list
     */
    seatingChart(flights);
    cout << "Creating seating chart...\n";

    return 0;
}
