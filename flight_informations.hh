/**
 * @file flightsclass.h
 * @author Mohib Akbari (mohibali.akbari@studerande.movant.se)
 * @brief Flights class header
 * @version 1
 * @date 2022-11-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef FLIGHT_CLASS_INCLUDED
#define FLIGHT_CLASS_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class flight_informations
{
    string departure;   /* !< Declaring variables */
    string destination; /* !< Declaring variables */
    string date;        /* !< Declaring variables */
    string time;        /* !< Declaring variables */
    int flightNum;      /* !< Declaring variables */
    int fRow;           /* !< Declaring variables */
    int fCurrent;       /* !< Declaring variables */
    int bRow;           /* !< Declaring variables */
    int bCurrent;       /* !< Declaring variables */
    int eRow;           /* !< Declaring variables */
    int eCurrent;       /* !< Declaring variables */
    int sec1;           /* !< Declaring variables */
    int sec2;           /* !< Declaring variables */
    int sec3;           /* !< Declaring variables */
public:
    void setFlightNum(int sfn);
    int getFlightNum();
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
    void setFirstClass(int sfc);
    int getFRow();
    int getFRowSeat();
    int getFirstClass();
    /* !< Defining Setters and Getters */
    void setBusinessClass(int sbc);
    int getBRow();
    int getBRowSeat();
    int getBusinessClass();
    /* !< Defining Setters and Getters */
    void setEconomyClass(int sec);
    int getERow();
    int getERowSeat();
    int getEconomyClass();
    /* !< Defining Setters and Getters */
    void setSection1(int c1);
    int getSec1();
    void setSection2(int c2);
    int getSec2();
    /* !< Defining Setters and Getters */
    void setSection3(int c3);
    int getSec3();
    /* !< Defining Setters and Getters */
    int getSecTotal();
    void setCurrentSeats();
    /* !< Defining Setters and Getters */
    void increaseF();
    void increaseB();
    void increaseE();
};
#endif
