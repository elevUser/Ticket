/**
 * @file functions.cpp
 * @author Mohib Akbari (mohibali.akbari@studerande.movant.se)
 * @brief Functions definition
 * @version 1
 * @date 2022-11-024
 *
 * @copyright NULL
 *
 */
#include "functions.hh"
using namespace std;
/**
 * @brief Flight_list function to parse CSV file
 * @param[in] filename = flightCsv
 * @param[in] List pointer to pushback
 */
void flight_list(string filename, list<flight_informations *> *List)
{
    ifstream flightCsv(filename);
    string line;

    if (flightCsv.is_open())
    {
        while (getline(flightCsv, line) && !line.empty())
        {
            flight_informations *newFlight = new flight_informations;

            stringstream data(line);
            string tempStr;

            getline(data, tempStr, ',');
            int temp = atoi(tempStr.c_str());

            newFlight->setFlightNum(temp);

            getline(data, tempStr, ',');
            newFlight->setDeparture(tempStr);
            getline(data, tempStr, ',');
            newFlight->setDestination(tempStr);
            getline(data, tempStr, ',');
            newFlight->setDate(tempStr);
            getline(data, tempStr, ',');
            newFlight->setTime(tempStr);

            getline(data, tempStr, ',');
            temp = atoi(tempStr.c_str());
            newFlight->setFirstClass(temp);

            getline(data, tempStr, ',');
            temp = atoi(tempStr.c_str());
            newFlight->setBusinessClass(temp);

            getline(data, tempStr, ',');
            temp = atoi(tempStr.c_str());
            newFlight->setEconomyClass(temp);

            getline(data, tempStr, '-');
            temp = atoi(tempStr.c_str());
            newFlight->setSection1(temp);
            getline(data, tempStr, '-');
            temp = atoi(tempStr.c_str());
            newFlight->setSection2(temp);
            getline(data, tempStr);
            temp = atoi(tempStr.c_str());
            newFlight->setSection3(temp);

            newFlight->setCurrentSeats();

            List->push_back(newFlight);
        }
        flightCsv.close();
    }
    else
    {
        cerr << "Unable to open file" << endl;
    }
}

/**
 * @brief Booking_list function to parse CSV file
 * @param[in] filename = bookingCsv
 * @param[in] List pointer to pushback
 */
void booking_list(string filename, list<booking_informations *> *List)
{
    ifstream bookingCsv(filename);
    string line;

    if (bookingCsv.is_open())
    {
        while (getline(bookingCsv, line) && !line.empty())
        {
            booking_informations *newBooking = new booking_informations;

            stringstream data(line);
            string tempStr;
            getline(data, tempStr, ',');
            int temp = atoi(tempStr.c_str());

            newBooking->setBookingNum(temp);

            getline(data, tempStr, ',');
            newBooking->setDate(tempStr);
            getline(data, tempStr, ',');
            newBooking->setTime(tempStr);
            getline(data, tempStr, ',');
            newBooking->setDeparture(tempStr);
            getline(data, tempStr, ',');
            newBooking->setDestination(tempStr);
            getline(data, tempStr, ',');
            newBooking->setSeatType(tempStr);
            getline(data, tempStr, ',');
            newBooking->setFirstName(tempStr);
            getline(data, tempStr);
            newBooking->setLastName(tempStr);

            List->push_back(newBooking);
        }
        bookingCsv.close();
    }
    else
    {
        cerr << "Unable to open file" << endl;
    }
}

/**
 * @brief Function to print out tickets
 * @param[in] f Flight list
 * @param[in] b Booking list
 */
void printTickets(list<flight_informations *> f, list<booking_informations *> b)
{
    list<booking_informations *>::iterator b_iterator;
    list<flight_informations *>::iterator f_iterator;

    for (b_iterator = b.begin(); b_iterator != b.end(); ++b_iterator)
    {
        for (f_iterator = f.begin(); f_iterator != f.end(); ++f_iterator)
        {
            /* !< Declairing pointers */
            booking_informations *bptr = *b_iterator;
            flight_informations *fptr = *f_iterator;

            /* !< Checking for conditions */
            if (bptr->getDate() == fptr->getDate() && bptr->getTime() == fptr->getTime() && bptr->getDeparture() == fptr->getDeparture() && bptr->getDestination() == fptr->getDestination())
            {

                char ticket[20];
                snprintf(ticket, sizeof(ticket), "ticket-%d.txt", bptr->getBookingNum());

                int seat;
                int row = 1;

                ofstream ticketFile(ticket);

                if (bptr->getSeatType() == "first")
                {
                    seat = fptr->getFirstClass();
                    fptr->increaseF();
                }
                else if (bptr->getSeatType() == "business")
                {
                    seat = fptr->getBusinessClass();
                    fptr->increaseB();
                }
                else if (bptr->getSeatType() == "economy")
                {
                    seat = fptr->getEconomyClass();
                    fptr->increaseE();
                }
                while (seat > (fptr->getSecTotal() * row))
                {
                    row++;
                }

                if (ticketFile.is_open())
                {
                    ticketFile << "BOOKING: " << bptr->getBookingNum() << "\nFLIGHT: " << fptr->getFlightNum() << " DEPARTURE: " << bptr->getDeparture() << " DESTINATION: " << bptr->getDestination() << " " << bptr->getDate() << " " << bptr->getTime() << "\nPASSENGER: " << bptr->getFirstName() << " " << bptr->getLastName() << "\nCLASS: " << bptr->getSeatType() << "\nROW: " << row << " SEAT: " << seat;
                }
                else
                {
                    cerr << "Unable to open file" << endl;
                }
                ticketFile.close();
            }
        }
    }
}

/**
 * @brief Function for canceling flights
 * @param[in] f Flight list
 */
void cancelFlights(list<flight_informations *> &f)
{

    /* !< Declairing iterator */
    list<flight_informations *>::iterator b_iterator;
    ofstream cancel("cancelled-flights.txt");

    b_iterator = f.begin();

    while (b_iterator != f.end())
    {

        flight_informations *fptr = *b_iterator;

        if (fptr->getFirstClass() == 1 && fptr->getBusinessClass() == fptr->getFRowSeat() + 1 && fptr->getEconomyClass() == fptr->getFRowSeat() + fptr->getBRowSeat() + 1)
        {

            cancel << fptr->getFlightNum() << "," << fptr->getDeparture() << "," << fptr->getDestination() << "," << fptr->getDate() << "," << fptr->getTime() << "," << fptr->getFRow() << "," << fptr->getBRow() << "," << fptr->getERow() << "," << fptr->getSec1() << "-" << fptr->getSec2() << "-" << fptr->getSec3() << "\n";

            f.remove(fptr);

            delete fptr;
            b_iterator = f.begin();
        }
        else
        {
            b_iterator++;
        }
    }
    cancel.close();
}

/**
 * @brief Function to print out seating report
 * @param[in] f Flight list
 */
void seatingChart(list<flight_informations *> f)
{
    list<flight_informations *>::iterator b_iterator;

    ofstream seating("seating-report.txt");

    for (b_iterator = f.begin(); b_iterator != f.end(); b_iterator++)
    {

        flight_informations *fptr = *b_iterator;

        int row = 1;
        int count = 0;

        seating << "Flight " << fptr->getFlightNum() << ", Departure " << fptr->getDeparture() << ", Destination " << fptr->getDestination() << ", Date " << fptr->getDate() << ", Time " << fptr->getTime() << "\n";

        seating << "First Class\n";
        for (int seat = 1; seat <= fptr->getFRowSeat(); seat++)
        {
            if (seat > (fptr->getSecTotal() * row))
            {
                row++;
                seating << "\n";
                count = 0;
            }

            if (seat < fptr->getFirstClass())
            {
                seating << "[1]";
            }
            else
            {
                seating << "[0]";
            }
            count++;
            if (count == fptr->getSec1() || count == fptr->getSec1() + fptr->getSec2())
            {
                seating << " ";
            }
        }
        seating << "\nBusiness Class";
        for (int seat = fptr->getFRowSeat() + 1; seat <= fptr->getFRowSeat() + fptr->getBRowSeat(); seat++)
        {
            if (seat > (fptr->getSecTotal() * row))
            {
                row++;
                seating << "\n";
                count = 0;
            }

            if (seat < fptr->getBusinessClass())
            {
                seating << "[1]";
            }
            else
            {
                seating << "[0]";
            }
            count++;
            if (count == fptr->getSec1() || count == fptr->getSec1() + fptr->getSec2())
            {
                seating << " ";
            }
        }
        seating << "\nEconomy Class";
        for (int seat = fptr->getFRowSeat() + fptr->getBRowSeat() + 1; seat <= fptr->getFRowSeat() + fptr->getBRowSeat() + fptr->getERowSeat(); seat++)
        {
            if (seat > (fptr->getSecTotal() * row))
            {
                row++;
                seating << "\n";
                count = 0;
            }

            if (seat < fptr->getEconomyClass())
            {
                seating << "[1]";
            }
            else
            {
                seating << "[0]";
            }
            count++;
            if (count == fptr->getSec1() || count == fptr->getSec1() + fptr->getSec2())
            {
                seating << " ";
            }
        }
        seating << "\n\n";
    }
    seating.close();
}
