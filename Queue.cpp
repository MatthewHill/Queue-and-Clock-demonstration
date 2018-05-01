/*
* File:   Queue.cpp
* Author: jmbind1@ilstu.edu
*
* Created on February 2, 2018, 4:15 PM
*/

#include "Queue.h"
#include <iostream>

#define NULL nullptr

Queue::Queue() {
	size = 0;
    head = NULL;
    tail = NULL;
    temp = NULL;
}
Queue::~Queue() {}

void Queue::enqueue(Customer cust) {
	temp = new node;
	temp->data = cust;
	temp->next = NULL;

	if (head == NULL) {
		head = tail = temp;
        head->next = NULL;
	}
	else {
		tail->next = temp;
		tail = temp;
        tail->next = NULL;
	}

	size++;
}

Customer Queue::getCustomer() {
	return head->data;
}

void Queue::dequeue() {
    if(head == NULL){
        std::cout<<"Empty queue.\n";    
    }else{
        head = head->next;
    }
}

int Queue::getSize() {
	return size;
}
