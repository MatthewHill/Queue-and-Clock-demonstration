/*
* File:   Queue.h
* Author: jmbind1@ilstu.edu
*
* Created on February 2, 2018, 4:15 PM
*/
#include "Customer.h"
#ifndef QUEUE_H
#define QUEUE_H

struct node {
	Customer data;
	node* next;
};

class Queue {
public:
	Queue();
	~Queue();
	void enqueue(Customer cust);
	Customer getCustomer();
	void dequeue();
	int getSize();
private:
	node* head;
    node* tail;
    node* temp;
	int size;
};

#endif /* QUEUE_H */
