//Created by Tung Thai 10/26/2017
//ELEC 3150-01
//Lab 5 Queue implementation
#include <iostream>
#include "queue.h"
using namespace std;
//initialize Queue
Queue::Queue(int value) {
	tail = 0; //initialize tail as 0
	head = 0; //initialize head as 0
	count = 0; //initialize # of element is 0
	num = value; //set the parameter equal to num
	arr = new char[num]; //char arr size num
}
//function enqueue for input char
int Queue::enqueue(char read_val) {
	if (count < num) {
			arr[tail] = read_val; //put character input into tail position (First In)
			tail = (tail + 1) % num; //increment value of tail if receive input
			count++; //increment the # of element in queue
			return 0;
	}
	else {
		return -1;
	}
}
//function denqueue for input char by reference
int Queue::dequeue(char &read_val) {
	if (count > 0) { //if the queue is not empty
			read_val = arr[head];
			count--; //decrement the # of element in queue
			head = (head + 1) % num; //increment the head value
			return 0;
	}
	else {
		return -1;
	}
}

int Queue::dequeue(char *read_val) {
	if (count > 0) { //if the queue is not empty
		*read_val = arr[head];
		count--; //decrement the # of element in queue
		head = (head + 1) % num; //increment the head value
		return 0;
	}
	else {
		return -1;
	}
	
}

//peek tail function
char Queue::peektail(int n) {
	return arr[n-1]; //set peek tail equail to the character next to NULL character
	}
//peek head function
char Queue::peekhead() {
		return arr[head]; //set peek head equal to head
	}