
# Ticket Printer

A program that reads data from 2 separate CSV files, "flights.csv" and "bookingfile.csv".

Then based on data in Csv files the program prints flight tickets.
## Deployment

To deploy this project run

```bash
  ~git clone https://github.com/elevUser/Ticket.git
```
```bash
  ~make
  ~./main -f flights.csv -b bookingsfile.csv
```
For help type
```bash
  ~./main -h
```
##Example

Running the program
```bash
  ./main -f flights.csv -b bookingsfile.csv
```
will produce
```bash
  ticket-1001.txt ticket-1002.txt ticket-1003.txt ticket-1004.txt
  ticket-1005.txt ticket-1006.txt ticket-1007.txt ticket-1008.txt
... etc

```
Example from ticket content
```bash
  BOOKING:2007
  FLIGHT:304 DEPARTURE:GOT DESTINATION:CPH 2022-10-27 06:30
  PASSENGER: Kalle Kula
  CLASS: first
  ROW:4 SEAT:24
```


