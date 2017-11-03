//Created by Tung Thai on 10/26/2017
//ELEC 3150-01
//Lab 5 Queue implementation 
#ifndef	QUEUE_H //if not define
#define QUEUE_H //preprocessor QUEUE_H
#define ARR_SIZE 30 //define arr size
//create a class Queue
class Queue {
private: //private class to protect data
	int tail; //initialize tail or rear
	int head; //initialize head of front
	int count; //count element
	int num; 
	char *arr; //array pointer
	int value;
public: //public function
	Queue(int); //initialize value in queue
	int enqueue(char); //enqueue char
	int dequeue(char& read_value); //dequeue by reference
	int dequeue(char* read_ptr); //dequeue by pointer
	char peektail(int);
	char peekhead();
	~Queue() { delete[] arr; } //destructor
};

#endif //end if