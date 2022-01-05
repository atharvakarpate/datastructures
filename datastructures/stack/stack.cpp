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

class myStack {
	
	node* top = NULL; 
	int size = 0; 
	
	//Member Functions
	public:
	void push(int data){
		if (top == NULL){
			node* newNode = new node(); 
			newNode -> data = data; 
			top = newNode;
			size++;
		}
		else{
			node* newNode = new node(); 
			newNode -> data = data; 
			newNode -> next = top;
		       	top = newNode;
			size++;
		}	
	}
	void pop(){
		if (top != NULL){
			top = top -> next;
			size--; 
		}
		else{
			cout << "Stack Underflow" << endl;
		}

	}
	void peek(){
		if (top != NULL){
			cout << "Top element is: " << top -> data << endl;
		}
		else{
			cout << "Stack Empty" << endl;
		}
	}
	bool isEmpty(){
		if (top == NULL) return true;
		else return false;
	}	

	int stackSize(){
		return size;
	}
	
	void printStack(){
		node* iter = top; 
		while(iter != NULL){
			cout << iter -> data << " ";
			iter = iter -> next;
		}
		cout << endl;
	}
		
};
int main(){
	srand(time(0));	

	myStack obj; 
	cout << "Push 20 elements" << endl;
	for (int i = 0; i < 20; i++){
		int num = rand()%10;
		obj.push(num);
	}
	cout << "Printing stack" << endl;
	obj.printStack();
	cout << "Stack size: " <<  obj.stackSize() << endl;

	cout << "Poping 10 elements" << endl;
	for(int i = 0; i < 10; i++){
		obj.pop();
	}

	cout << "Printing stack" << endl;
	obj.printStack();
	cout << "Stack size: " <<  obj.stackSize() << endl;

	obj.peek();
	
	cout << "Poping 10 elements" << endl;
	for(int i = 0; i < 10; i++){
		obj.pop();
	}

	cout << "Printing stack" << endl;
	obj.printStack();
	cout << "Stack size: " <<  obj.stackSize() << endl;
	
	obj.peek();
	cout << "Poping 1 elements" << endl;
	obj.pop();

	cout << "Stack Empty? " << boolalpha << obj.isEmpty() << endl; //boolalpha to print false or true
return 0;
}

