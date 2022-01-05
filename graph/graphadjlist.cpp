#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

class node{
	public:
	int data;
	node* next;
};

class graph{
	int num_vertices;
	node** adjlist;
	public:
		graph(int num_vert = 10){
			num_vertices = num_vert;

			adjlist = new node*[num_vertices];

			for(int i = 0; i < num_vertices; i++){
				*(adjlist + i) = create_node(i);
			}
		}
		
		node* create_node(int val){
			node* temp = new node();
		       	temp -> data = val;
			temp -> next = NULL;
			return temp; 
		}

		void print_graph(){
			for(int i = 0; i < num_vertices; i++){
				cout <<  "Vertex: " << (*(adjlist + i)) -> data << " Edges: ";
				node* iter = (*(adjlist + i)) -> next;
			       	while (iter != NULL){
					cout << iter -> data << " ";
					iter = iter -> next;
				}
				cout << endl;
			}
		}

		void addEdge(int v, int u){
			//adding u to the adjacency list of v
			node* temp = new node();
			temp -> data = u; 
			node* iter = *(adjlist + v); 
			while(iter -> next != NULL){
				iter = iter -> next;
			}
			iter -> next = temp; 

			//adding v to the adjacency list of u
			node* temp2 = new node();
			temp2 -> data = v; 
			iter = *(adjlist + u); 
			while(iter -> next != NULL){
				iter = iter -> next;
			}
			iter -> next = temp2; 

		}

		~graph(){
			delete adjlist;
		}


};
			
			

int main(){

	graph obj(5); 
	obj.print_graph(); 

	obj.addEdge(1,2);
	obj.addEdge(1,4);
	obj.addEdge(1,3);
	obj.print_graph(); 
};
