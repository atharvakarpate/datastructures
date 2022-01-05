#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>
#include "graph.h"
#include "traversalalgo.h"

#define graph_size 15

using namespace std;

int main(){

	srand(time(0));

	graph obj(graph_size);
	cout << "Size of Graph: " << obj.size() << endl; 	
	

	cout << "Adding 40 edges randomly" << endl;
	for(int i = 0; i < 40; i++){
		int k = rand() % graph_size; 
		int z = rand() % graph_size; 
		cout << "{" << k << "," << z << "}" << " ";
		obj.addEdge(k, z);
	}
	cout << endl;
	obj.print_graph();

	cout << "Graph Traversal: BFS and DFS" << endl;	
	cout << "Choose starting Node" << endl;
	int start_node;
	cin >> start_node;
	node** adjlist = obj.get_adjlist();
	
	cout << "Breadth First Search: " << endl;
	breadth_first_search(adjlist, start_node);	

	cout << "Depth First Search: " << endl;
	depth_first_search(adjlist, start_node);	
};
