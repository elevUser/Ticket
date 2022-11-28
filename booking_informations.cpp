/**
 * @file bookingsclass.cpp
 * @author Mohib akbari (mohibali.akbari@studerande.movant.se)
 * @brief booking_information class headers
 * @version 1
 * @date 2022-11-24
 *
 * @copyright NULL
 *
 */
#include "booking_informations.hh"
using namespace std;

/* Define setters and getters*/
void booking_informations::setBookingNum(int sbn)
{
    this->bookingNum = sbn;
}
int booking_informations::getBookingNum()
{
    return this->bookingNum;
}
/* Define setters and getters*/
void booking_informations::setDeparture(string &sdep)
{
    this->departure = sdep;
}
string booking_informations::getDeparture()
{
    return this->departure;
}
/* Define setters and getters*/
void booking_informations::setDestination(string &sdest)
{
    this->destination = sdest;
}
string booking_informations::getDestination()
{
    return this->destination;
}
/* Define setters and getters*/
void booking_informations::setDate(string &sdate)
{
    this->date = sdate;
}

string booking_informations::getDate()
{
    return this->date;
}
/* Define setters and getters*/
void booking_informations::setTime(string &stime)
{
    this->time = stime;
}
string booking_informations::getTime()
{
    return this->time;
}
/* Define setters and getters*/
void booking_informations::setSeatType(string &sst)
{
    this->seatType = sst;
}
string booking_informations::getSeatType()
{
    return this->seatType;
}
/* Define setters and getters*/
void booking_informations::setFirstName(string &sfn)
{
    this->firstName = sfn;
}
string booking_informations::getFirstName()
{
    return this->firstName;
}
/* Define setters and getters*/
void booking_informations::setLastName(string &sln)
{
    this->lastName = sln;
}
string booking_informations::getLastName()
{
    return this->lastName;
}
