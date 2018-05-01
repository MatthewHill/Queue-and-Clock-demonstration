/*
* File:   Customer.cpp
* Author: jmbind1@ilstu.edu
*
* Created on February 7, 2018, 6:59 PM
*/

#include "Customer.h"
#include <cstdlib>
#include <iostream>
using namespace std;


Customer::Customer() {
	Customer(0, 0, 0, 0);
}
Customer::~Customer() { }
Customer::Customer(int arrivalMinute, int departureMinute, int serviceTime, int customerNumber) {
	Customer::arrivalMinute = arrivalMinute;
	Customer::departureMinute = departureMinute;
	Customer::serviceTime = serviceTime;
	Customer::customerNumber = customerNumber;
}

int Customer::getArrivalMinute() { return arrivalMinute; }
int Customer::getDepartureMinute() { return departureMinute; }
int Customer::getServiceTime() { return serviceTime; }
int Customer::getCustomerNumber() { return customerNumber; }
void Customer::setCustomerNumber(int N) { customerNumber = N; }
void Customer::setServiceTime(int T) { serviceTime = T; }
void Customer::setArrivalTime(int A) { arrivalMinute = A; }
void Customer::setDepartureTime(int D) { departureMinute = D; }