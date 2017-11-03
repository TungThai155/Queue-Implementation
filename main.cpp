//Created by Tung Thai on 10/26/2017
//ELEC 3150-01
//lab 5 Queue implementation
#include <iostream>
#include "queue.h" //include header
using namespace std; //using standard namespace

int main()
{
	int j = 0; //counter for enqueue
	int test, enter;
	int n; //number of elements
	int dt = 10; //the number of times that user want to dequeue 
	char read_value = NULL;
	char*read_ptr = &read_value;
	char mycstr[] = "Hello world, this is ELEC3150";
	int size = sizeof(mycstr) - 1; //not include the null character at the end
	cout << "Please enter the number of element you want to enqueue: ";
	cin >> n; //receive and process user input
	Queue q(n); //object q
	cout << "Please enter the test that you want to perform " << endl;
	cout << "1.Test 1 " << endl;
	cout << "2.Test 2 " << endl;
	cin >> test;
		//using switch, perform test 1 or test 2
		switch (test) {
		case 1: //test 1
			cout << "Enter which type of dequeue that you want" << endl;
			cout << "1.Dequeue by Reference" << endl; //dequeue by references
			cout << "2.Dequeue by Pointer" << endl; //dequeue by pointer
			cin >> enter;
			cout << "Test 1... \n";
			cout << endl;
			cout << "Enqueue " << endl;
			for (int i = 0; i < size; i++) //enqueue until the end of the array. n+1 is the address of NULL
			{
				if (q.enqueue(mycstr[i]) == -1) { cout << "\nQueue is full, can't enqueue more element"; } //check if the array is full
				else {
					cout << mycstr[i]; // print out element in mycstr
				}
			}
			cout << endl;
			cout << "\nPeek the queue... " << endl; //peek value
			cout << "The head is " << q.peekhead() << endl; //peek head
			cout << "The tail is " << q.peektail(n) << endl; //peek tail
			switch (enter) {
			case 1:	//Dequeue by Reference
				for (int i = 0; i < dt; i++) {// dequeue 10 times
					if (q.dequeue(read_value) == -1) { cout << "\nQueue is empty, can't dequeue "; } //check if the array is empty
					else {
						cout << "\nDequeued:" << read_value; //using public function denqueue to delete character by character until empty 
					}
				}
				break;
			case 2:	//Dequeue by Pointer
				for (int i = 0; i < dt; i++) {// dequeue 10 times
					if (q.dequeue(*read_ptr) == -1) { cout << "\nQueue is empty, can't dequeue "; } //check if the array is empty
					else {
						cout << "\nDequeued:" << *read_ptr; //using public function denqueue to delete character by character until empty 
					}
				}
				break;
			}
			break;
		case 2:
			cout << "Enter which type of dequeue that you want" << endl;
			cout << "1.Dequeue by Reference" << endl; //dequeue by references
			cout << "2.Dequeue by Pointer" << endl; //dequeue by pointer
			cin >> enter;
			cout << "Test 2... "; //test 2
			while (j <= size) // if enqueue counter less than or equal to the size of mycstr, execute the code
			{
				cout << "\nEnqueue:";
				for (int i = 0; i < 5; i++) //Enqueue 5 characters
				{
					if (q.enqueue(mycstr[i + j]) == -1) //check if the array is full 
					{
						cout << "\nQueue is full, can't enqueue: " << mycstr[i + j] << endl; // print out the character that can't enqueue
					}
					else {
						cout << mycstr[i + j]; //enqueue character
					}
				}
				//using switch, dequeue by reference or dequeue by pointer
				switch (enter) {
				case 1:	//Dequeue by Reference
					cout << "\nDequeue by Reference:";
					for (int i = 0; i < 5; i++) //Dequeue 5 characters
					{
						if (q.dequeue(read_value) == -1) //check if the array is empty
							cout << "\nQueue is empty, can't dequeue." << endl;
						else
							cout << read_value; //dequeue
					}
					break;
				case 2:	//Dequeue by Pointer
					cout << "\nDequeue by Pointer:";
					for (int i = 0; i < 5; i++) //Dequeue 5 characters
					{
						if (q.dequeue(read_ptr) == -1) //check if the array is empty
							cout << "\nQueue is empty, can't dequeue." << endl;
						else
							cout << *read_ptr; //dequeue
					}
					break;
				}
				j = j + 5; //increment the counter
				cout << endl;
			}
		}
	cout << endl;
	system("pause");
	return 0;
}