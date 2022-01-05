#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

class node{
	public:
	int data;
	node* left = NULL;
	node* right = NULL;
};

enum direction {l, r};

class bst{
	private:
		node* root = new node(); 
		int size = 0;
	public:
		void insert(int val){
			/* Insert:
			 * Find the element previous node and whether to insert on the right or the left
			 */

			if(size == 0){
				root -> data = val;
				size++;
			}
			else{
				node* iter = root;
			       	while(iter != NULL){
					if (val == iter -> data){
						return;
					}
					else if(val > iter -> data){
						if (iter -> right == NULL){
							node* temp = new node();
							temp -> data = val;
							iter -> right = temp;
							size++;
							return;
						}
						else{
							iter = iter -> right;
						}
					}
					else{
						if (iter -> left == NULL){
							node* temp = new node();
							temp -> data = val;
							iter -> left = temp;
							size++;
							return;
						}
						else{
							iter = iter -> left;
						}
					}
				}

			}	
		}

		bool search(int val){
			node* iter = root; 
			while(iter != NULL){
				if (iter -> data == val){
					return true;
				}
				else if (iter -> data < val){
					iter = iter -> right;
				}
				else{
					iter = iter -> left;
				}
			}
			return false;
		}
    
		void remove(int val){
			root = remove(val, root);	
		}

		node* remove(int val, node* r){
			if (r == NULL){
				return r;
			}
			else if(val < r -> data){
				r -> left = remove(val, r -> left);
			}
			else if(val > r -> data){
				r -> right = remove(val, r -> right);
			}
			else if(r -> left && r -> right){
				node* temp = findMin(r -> right); 
				r -> data = temp -> data; 
				r -> right = remove(r -> data, r -> right); 
			}
			else{
				if (r -> left == NULL){
					node* temp = r;
					r = r -> right;
					delete temp;
				}
				else if(r -> right == NULL){
					node* temp = r;
					r = r -> left;
					delete temp;
				}
			}
			return r;
					
		}
		node* findMin(node* t){
			if (t == NULL){
				return t;
			}
			else if(t -> left == NULL){
				return t;
			}
			else{
				return findMin(t -> left);
			}
		}

		void preordertrav(){
			preordertrav(root); 
		}

		void preordertrav(node* tree){
			if (tree == NULL){
				return;
			}
			cout << tree -> data << " - "; 
			preordertrav(tree -> left);
			preordertrav(tree -> right); 
		}

		void inordertrav(){
			inordertrav(root); 
		}

		void inordertrav(node* tree){
			if (tree == NULL){
				return;
			}
			inordertrav(tree -> left);
			cout << tree -> data << " - "; 
			inordertrav(tree -> right); 
		}

		void postordertrav(){
			postordertrav(root); 
		}

		void postordertrav(node* tree){
			if (tree == NULL){
				return;
			}
			postordertrav(tree -> left);
			postordertrav(tree -> right); 
			cout << tree -> data << " - "; 
		}
		
		int bstSize(){
			return size;
		}
};

int main(){
	srand(time(0));	
	
	bst obj; 
	
	cout << "Inserting 20 random elements ";
	for (int i = 0; i < 20; i++){
		int num = rand() % 10;
		cout << " - " << num;
		obj.insert(num);
	}
	cout << endl;

	cout << "Tree size: " <<  obj.bstSize() << endl;
	
	cout << "Printing Tree Pre-Order" << endl;
	obj.preordertrav();
	cout << "End" << endl;
	
	cout << "Printing Tree In-Order" << endl;
	obj.inordertrav();
	cout << "End" << endl;
	
	cout << "Printing Tree Post-Order" << endl;
	obj.postordertrav();
	cout << "End" << endl;

	cout << "Searching for 5 random elements" << endl;
	for (int i = 0; i < 5; i++){
		int num = rand() % 10;
		cout << "Element: " << num << " Present: " << boolalpha << obj.search(num) << endl;
	}

	cout << "Enter and Remove a value" << endl; 
	int search_val;
	cin >> search_val; 
	obj.remove(search_val);
	
	cout << "Printing Tree In-Order" << endl;
	obj.inordertrav();
	cout << "End" << endl;
	return 0;
};
