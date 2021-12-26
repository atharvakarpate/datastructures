#include <iostream> 

using namespace std;

class node{
	public:
	int data;
	node* next;
};
int length(node* head){ 
	int len = 0;
	for(node* current = head; current != NULL; current = current -> next){
		len++;
	}
	return len;
}
void wrongPush(node* head, int data){
	node* newNode = new node();
	newNode -> data = data;
	newNode -> next = head;
	head = newNode;
}

void Push(node*& head, int data){
	node* newNode = new node();
	newNode -> data = data;
	newNode -> next = head; 
	head = newNode;
}

void addatend(node** head, int data){
	node* newNode = new node();
	newNode -> data = data; 
	newNode -> next = NULL;
	
	if (*head == NULL){
		*head = newNode;
		return;	
	}
	node* current;
	for(current = *head; current -> next != NULL; current = current -> next){
	}

	current -> next = newNode; 
	
}

void printList(node* head){
	for(node* current = head; current != NULL; current = current -> next){
		cout << current -> data << "->";
	}
	cout << "NULL" << endl;
}
int main(){
	node* head;
	node* first = new node();
	node* second = new node();
	node* third = new node();

	head  = first;

	
	first -> data = 1;
	first -> next = second;

	second -> data = 2;
	second -> next = third;

	third -> data = 3;
	third -> next = NULL;
	
	node* newNode = new node(); 
	

	printList(head);
	cout << "Wrong Push at Front " << endl;
	cout << "Length of Linkedlist " << length(head) << endl;
	wrongPush(head, 5); 
	cout << "Length of Linkedlist " << length(head) << endl;
	printList(head);
	
	cout << "Right Push at Front " << endl;
	cout << "Length of Linkedlist " << length(head) << endl;
	Push(head, 5);
	cout << "Length of Linkedlist " << length(head) << endl;
	printList(head);
	
	cout << "Push at Back " << endl;
	cout << "Length of Linkedlist " << length(head) << endl;
	addatend(&head, 6);
	cout << "Length of Linkedlist " << length(head) << endl;
	printList(head);
	
	delete first;
	delete second;
	delete third;
	delete newNode;

}

