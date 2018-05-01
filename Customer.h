/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   Customer.h
* Author: jmbind1@ilstu.edu
*
* Created on February 7, 2018, 6:59 PM
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
	Customer();
	~Customer();
	Customer(int arrivalMinute, int departureMinute, int serviceTime, int customerNumber);

	int getArrivalMinute();
	int getDepartureMinute();
	int getServiceTime();
	int getCustomerNumber();
	void setCustomerNumber(int N);
	void setServiceTime(int T);
	void setArrivalTime(int A);
	void setDepartureTime(int D);
private:
	int arrivalMinute;
	int departureMinute;
	int serviceTime;
	int customerNumber;
};

#endif /* CUSTOMER_H */
