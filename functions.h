/**
 * @file functions.h
 * @author Mohib Akbari (mohibali.akbari@studerande.movant.se)
 * @brief Functions header
 * @version 1
 * @date 2022-11-024
 *
 * @copyright NULL
 *
 */
#include <iterator>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include "flightsclass.h"
#include "bookingsclass.h"
using namespace std;
/**
 * @brief Function prototype to fill flight_list
 * @param[in] filename Flight file name
 * @param[in] List Flight list
 */
void flight_list(string filename, list<flight_informations *> *List);
/**
 * @brief Function prototype to for booking_list
 * @param[in] filename Booking file name
 * @param[in] List Booking list
 */
void booking_list(string filename, list<booking_informations *> *List);
/**
 * @brief Function prototype to print tickets
 * @param[in] f Flight list
 * @param[in] b Booking list
 */
void printTickets(list<flight_informations *> f, list<booking_informations *> b);
/**
 * @brief Function prototype to cancel flights with no passengers
 * @param[in] f Flight list
 */
void cancelFlights(list<flight_informations *> &f);
/**
 * @brief Function prototype to print out seating report
 * @param[in] f Flight list
 */
void seatingChart(list<flight_informations *> f);