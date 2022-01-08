#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>
#include <string>

using namespace std;

class node{
	public:
	map<char, node*> trie;
	bool isWord;
	node(){
		isWord = false;
	}
};

class Trie{
	node* root = new node(); 

	public:
	void insert(string val){
		node* curr = root;
		for(int i = 0; i < val.length(); i++){
			if (curr -> trie.find(val[i]) == curr -> trie.end()){
				node* newNode = new node();
			       	curr -> trie[val[i]] = newNode;
				curr = curr -> trie[val[i]];
			}
			else{
				curr = curr -> trie[val[i]];
			}
		}
		curr -> isWord = true;
	}

	void print(){
		for(auto it = root -> trie.begin(); it != root -> trie.end(); it++){
			cout << (*it).first << " -> ";
		       	print((*it).second); 
			cout << "End" << endl;
		}
	}

	void print(node* root){
		for(auto it = root -> trie.begin(); it != root -> trie.end(); it++){
			cout << (*it).first << " -> ";
		       	print((*it).second); 
		}
	}

	bool startsWith(string val){
		node* curr = root;
		for(int i = 0; i < val.length(); i++){
			if(curr -> trie.find(val[i]) == curr -> trie.end()){
				return false;
			}
			curr = curr -> trie[val[i]];
		}
		return true;
	}

	bool search(string val){
		node* curr = root;
		for(int i = 0; i < val.length(); i++){
			if(curr -> trie.find(val[i]) == curr -> trie.end()){
				return false;
			}
			curr = curr -> trie[val[i]];
		}
		if(curr -> isWord == true){
			return true;
		}
		return false;
	}
	
	// TODO: delete_word does not pass all cases For e.g deleting Hello deletes Hell
	void delete_word(string val){
		delete_word(root, val); 
	}

	void delete_word(node* root, string val){
		if(root -> trie.empty()){
			return;
		}
		if(root -> trie.find(val[0]) == root -> trie.end()){
			cout << "Word not present in Trie" << endl;
			return;
		}
		delete_word(root -> trie[val[0]], val.substr(1, val.length() - 1)); 
		if(root -> trie[val[0]] -> trie.empty()){
			node* temp = root -> trie[val[0]];
			root -> trie.erase(val[0]);
			delete temp;
			return;
		}
		else if(root -> trie[val[0]] -> isWord == true){
			root -> trie[val[0]] -> isWord = false;
		}

	}

};


int main(){

	Trie obj;

	vector<string> words = {"USA", "Cat", "Caton", "Cattle", "Hello", "Hell", "Halloween"};

	cout << "Inserting Words inside Trie" << endl;
	for(auto i: words){
		obj.insert(i);
	}

	cout << "Printing Trie" << endl;
	obj.print();

	cout << "Enter word to search: ";
	string word;
	cin >> word; 
	cout << "Word Present? " << boolalpha << obj.search(word) << endl;

	cout << "Enter prefix to search: ";
	string prefix;
	cin >> prefix; 
	cout << "Prefix Present? " << boolalpha << obj.startsWith(prefix) << endl;

	cout << "Enter String to Delete: ";
	string del_word;
	cin >> del_word;
	obj.delete_word(del_word);
	cout << "Word " << del_word << " Present? " << boolalpha << obj.search(del_word) << endl;

	cout << "Printing New Trie" << endl;
	obj.print();

	return 0;	
};
