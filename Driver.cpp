#include <iostream>
#include <string>
#include "Clock.h"
#include "Customer.h"
#include "Queue.h"
#include <vector>

using namespace std;

int main() //Not sure if we had an idea for a driver class so I started this.
{
	int currentCustomer = 0; //keeps track of the customer being serviced
	int customerLine = 0; //keeps track of how many customers are in line
	int MaxCustomers; //Most customers in line
	int MaxWait = 0; //Max wait time for all customers
	int arrival; //placeholder for arrival time
	int customerNumber = 1; //placeholder for customer numbers
	int i = 1; //customer index for arrival
	int input;
	Queue myQueue; //initialize Queue

	//1.	Choose a random integer between 1 and x to determine the minute at which the first customer arrives.
	cout << "Enter a value X for maximum arrival and service delay: ";
	cin >> input;
	Clock myClock(0, input); //initialize clock to 0 and a max value of user choosing
	arrival = myClock.generateArrival(); //generate the arrival time for the first Customer
	vector<Customer> custVector(1, Customer()); //Creates an Array of Customers with default constructor
	custVector[0].setCustomerNumber(1); //generate customer number 1
	custVector[0].setArrivalTime(arrival);

	//	2.	At the first customer’s arrival time :
	myClock.setCurrentTime(custVector[0].getArrivalMinute());
		//Print an arrival message;*/
	
		cout << "Customer " << custVector[0].getCustomerNumber() << " has arrived at "<< custVector[0].getArrivalMinute() << "\n";
	/*	Determine customer’s service time(random integer from 1 to x); */
		custVector[0].setServiceTime(myClock.generateServiceTime());
		custVector[0].setDepartureTime(custVector[0].getServiceTime() + myClock.getCurrentTime());
		/*Begin servicing the customer;
		Schedule the arrival time of the next customer(random integer 1 to x added to the current time) */
		arrival = myClock.generateArrival();
		custVector.push_back(Customer()); //Pushes a default customer into the Vector
		custVector[1].setArrivalTime(arrival);
		custVector[1].setCustomerNumber(2);
		//	3.	For each subsequent minute of the day :
		while (myClock.getCurrentTime() <= 760)
		{
		//If the next customer arrives,
			if (myClock.getCurrentTime() == arrival)
			{
				//Print an arrival message;
				cout << "Customer " << custVector[i].getCustomerNumber() << " has arrived at " << custVector[i].getArrivalMinute() << "\n";
				//Enqueue the customer;
				myQueue.enqueue(custVector[i]);
					customerLine++; 
				if (customerLine > MaxCustomers)   // Checks to see if this line is the largest line so far.
				{
					MaxCustomers = customerLine;
				}
					//Schedule the arrival time of the next customer;
					custVector.push_back(Customer());
					arrival = myClock.generateArrival();
					i++;
					custVector[i].setArrivalTime(arrival);
					custVector[i].setCustomerNumber(i + 1);
				//If service was completed for the last customer :
			}
				if (myClock.getCurrentTime() == custVector[currentCustomer].getDepartureMinute())
				{
					//Print a departure message;
					cout << "Customer " << custVector[currentCustomer].getCustomerNumber() << " left at " << custVector[currentCustomer].getDepartureMinute() << "\n";
						//Dequeue the next customer to be serviced;
					myQueue.dequeue();
					// cout << "Segmentation";
					customerLine = customerLine - 1;
						//Determine customer’s service completion time;
					if ((custVector[currentCustomer].getDepartureMinute() - custVector[currentCustomer].getServiceTime() - custVector[currentCustomer].getArrivalMinute()) > MaxWait) //Check wait time and compare with max
					{
						MaxWait = (custVector[currentCustomer].getDepartureMinute() - custVector[currentCustomer].getServiceTime() - custVector[currentCustomer].getArrivalMinute());
					}
					currentCustomer = currentCustomer + 1;  //Goes to the next customer
					custVector[currentCustomer].setServiceTime(myClock.generateServiceTime()); //Set service time for next customer
					custVector[currentCustomer].setDepartureTime(myClock.getCurrentTime() + custVector[currentCustomer].getServiceTime()); //Calculate the departure time for the next customer in line
				}
			myClock.setCurrentTime(myClock.getCurrentTime() + 1);
	}
	cout << "The maximum number of customers in the queue at one time was: " << MaxCustomers << "\n"; //Note that the number of customers in the queue does not include the one being waited on
	cout << "The longest wait any one customer experiences was: " << MaxWait << "\n"; //wait does not include service time
}
