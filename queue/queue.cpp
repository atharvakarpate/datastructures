#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

class node{
	public:
	int data;
	node* next = NULL;
};

class Queue{
	node* head;
	node* tail;
	int size;

	public:
	Queue(){
	head = NULL;
	tail = NULL;
	size = 0;
	}

	Queue(int data){
	head = NULL;
	tail = NULL;
	size = 0;
	this -> enqueue(data);
	}	

	void enqueue(int data){
		if(head == NULL){
			node* newNode = new node();
			newNode -> data = data; 
			head = newNode;
			tail = newNode;
			size++;
		}
		else{
			node* newNode = new node();
			newNode -> data = data;
			tail -> next = newNode;
			tail = tail -> next;
			size++;
		}
	}

	void dequeue(){
		if (head == NULL){
			cout << "Empty Queue" << endl;
		}
		else{
			head = head -> next;
			if (head == NULL){
				tail = NULL;
			}
			size--;
		}
	}

	bool isEmpty(){
		if (head == NULL){
			return true;
		}
		else{
			return false;
		}
	}

	void peek(){
		if (head == NULL){
			cout << "Empty Queue" << endl;
		}
		else{
			cout << "Top Element: " << head -> data << endl;
		}
	}

	int Qsize(){
		return size;
	}

	void printQueue(){
		node* iter = head;
		while(iter != NULL){
			cout << iter -> data << "->";
			iter = iter -> next;
		}
		cout << "NULL" << endl;
	}

};
int main(){
	srand(time(0));	

	cout << "Inserting single object with constructor" << endl;
	Queue obj(10); 
	cout << "Printing Queue" << endl;
	obj.printQueue();
	cout << "Queue size: " <<  obj.Qsize() << endl;
	
	cout << "Inserting 20 elements" << endl;
	for (int i = 0; i < 20; i++){
		int num = rand()%10;
		obj.enqueue(num);
	}
	cout << "Printing Queue" << endl;
	obj.printQueue();
	cout << "Queue size: " <<  obj.Qsize() << endl;
	
	cout << "Dequeue 10 elements" << endl;
	for(int i = 0; i < 10; i++){
		obj.dequeue();
	}

	cout << "Printing Queue" << endl;
	obj.printQueue();
	cout << "Queue size: " <<  obj.Qsize() << endl;
	
	obj.peek();

	
	cout << "Dequeue 12 elements" << endl;
	for(int i = 0; i < 12; i++){
		obj.dequeue();
	}

	cout << "Printing Queue" << endl;
	obj.printQueue();
	cout << "Queue size: " <<  obj.Qsize() << endl;
	
	obj.peek();

	cout << "Queue Empty? " << boolalpha << obj.isEmpty() << endl; //boolalpha to print false or true
	
	return 0;
}

