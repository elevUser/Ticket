/**
 * @file flightsclass.cpp
 * @author Mohib akbari (mohibali.akbari@studerande.movant.se)
 * @brief Flight_information class definition
 * @version 1
 * @date 2022-11-24
 *
 * @copyright NULL
 *
 */
#include "flightsclass.h"
using namespace std;

/*  Define setters and getters */
void flight_informations::setFlightNum(int sfn)
{
    this->flightNum = sfn;
}
int flight_informations::getFlightNum()
{
    return this->flightNum;
}
/*  Define setters and getters */
void flight_informations::setDeparture(string &sdep)
{
    this->departure = sdep;
}
string flight_informations::getDeparture()
{
    return this->departure;
}
/*  Define setters and getters */
void flight_informations::setDestination(string &sdest)
{
    this->destination = sdest;
}
string flight_informations::getDestination()
{
    return this->destination;
}
/*  Define setters and getters */
void flight_informations::setDate(string &sdate)
{
    this->date = sdate;
}
string flight_informations::getDate()
{
    return this->date;
}
/*  Define setters and getters */
void flight_informations::setTime(string &stime)
{
    this->time = stime;
}
string flight_informations::getTime()
{
    return this->time;
}
/*  Define setters and getters */
void flight_informations::setFirstClass(int sfc)
{
    this->fRow = sfc;
}
int flight_informations::getFirstClass()
{
    return this->fCurrent;
}
int flight_informations::getFRow()
{
    return this->fRow;
}
int flight_informations::getFRowSeat()
{
    return (this->fRow * (this->sec1 + this->sec2 + this->sec3));
}
/*  Define setters and getters */
void flight_informations::setBusinessClass(int sbc)
{
    this->bRow = sbc;
}
int flight_informations::getBusinessClass()
{
    return this->bCurrent;
}
int flight_informations::getBRow()
{
    return this->bRow;
}
int flight_informations::getBRowSeat()
{
    return (this->bRow * (this->sec1 + this->sec2 + this->sec3));
}
/*  Define setters and getters */
void flight_informations::setEconomyClass(int sec)
{
    this->eRow = sec;
}
int flight_informations::getEconomyClass()
{
    return this->eCurrent;
}
int flight_informations::getERow()
{
    return this->eRow;
}
int flight_informations::getERowSeat()
{
    return (this->eRow * (this->sec1 + this->sec2 + this->sec3));
}
/*  Define setters and getters */
void flight_informations::setSection1(int c1)
{
    this->sec1 = c1;
}
int flight_informations::getSec1()
{
    return this->sec1;
}
/*  Define setters and getters */
void flight_informations::setSection2(int c2)
{
    this->sec2 = c2;
}
int flight_informations::getSec2()
{
    return this->sec2;
}
/*  Define setters and getters */
void flight_informations::setSection3(int c3)
{
    this->sec3 = c3;
}
int flight_informations::getSec3()
{
    return this->sec3;
}
/*  Define setters and getters */
int flight_informations::getSecTotal()
{
    return (this->sec1 + this->sec2 + this->sec3);
}
/*  Define setters and getters */
void flight_informations::setCurrentSeats()
{
    this->fCurrent = 1;
    this->bCurrent = (this->fRow * (this->sec1 + this->sec2 + this->sec3)) + 1;
    this->eCurrent = (this->fRow * (this->sec1 + this->sec2 + this->sec3)) + (this->bRow * (this->sec1 + this->sec2 + this->sec3)) + 1;
}

/* seat counter */
void flight_informations::increaseF()
{
    this->fCurrent++;
}
void flight_informations::increaseB()
{
    this->bCurrent++;
}
void flight_informations::increaseE()
{
    this->eCurrent++;
}
