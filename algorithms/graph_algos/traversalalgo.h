#ifndef TRAVERSALALGO_H
#define TRAVERSALALGO_H

#include <iostream> 
#include <bits/stdc++.h>
#include "graph.h"

#define graph_size 15

using namespace std;

void breadth_first_search(node** adjlist, int start_node){
	queue<int> bfs; 
	unordered_set<int> visited;

	bfs.push((*(adjlist + start_node)) -> data);
	visited.insert((*(adjlist + start_node)) -> data);

	while(!bfs.empty()){
		int i = bfs.front();
		bfs.pop();
		node* iter = (*(adjlist + i)) -> next; 
		cout << i  << " ";
		while(iter != NULL){
			if (visited.find(iter -> data) == visited.end()){
				bfs.push(iter -> data);
				visited.insert(iter -> data);
			}
			iter = iter -> next; 
		}
	}

	cout << endl;
}

void depth_first_search(node** adjlist, int start_node){
	stack<int> dfs;
	unordered_set<int> visited; 

	dfs.push((*(adjlist + start_node)) -> data);
	visited.insert((*(adjlist + start_node)) -> data);

	while(!dfs.empty()){
		int i = dfs.top();
		dfs.pop();
		cout << i << " "; 
		node* iter = (*(adjlist + i)) -> next; 

		while(iter != NULL){
			if(visited.find(iter -> data) == visited.end()){
				dfs.push(iter -> data);
				visited.insert(iter -> data); 
			}
			iter = iter -> next; 
		}

	}
	
	cout << endl;


}

#endif	
