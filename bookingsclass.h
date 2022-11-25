/**
 * @file bookingsclass.h
 * @author Mohib Akbari (mohibali.akbari@studerande.movant.se)
 * @brief Booking_informations class headers
 * @version 1
 * @date 2022-11-24
 *
 * @copyright NULL
 *
 */
#ifndef BOOKING_CLASS_INCLUDED
#define BOOKING_CLASS_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class booking_informations
{
    int bookingNum;     /* !< Declaring variables */
    string destination; /* !< Declaring variables */
    string date;        /* !< Declaring variables */
    string time;        /* !< Declaring variables */
    string seatType;    /* !< Declaring variables */
    string departure;   /* !< Declaring variables */
    string firstName;   /* !< Declaring variables */
    string lastName;    /* !< Declaring variables */

public:
    /* !< Defining Setters and Getters */
    void setBookingNum(int sbn);
    int getBookingNum();
    /* !< Defining Setters and Getters */
    void setDeparture(string &sdepart);
    string getDeparture();
    /* !< Defining Setters and Getters */
    void setDestination(string &sdest);
    string getDestination();
    /* !< Defining Setters and Getters */
    void setDate(string &sdate);
    string getDate();
    /* !< Defining Setters and Getters */
    void setTime(string &stime);
    string getTime();
    /* !< Defining Setters and Getters */
    void setSeatType(string &sst);
    string getSeatType();
    /* !< Defining Setters and Getters */
    void setFirstName(string &sfn);
    string getFirstName();
    /* !< Defining Setters and Getters */
    void setLastName(string &sln);
    string getLastName();
};
#endif