#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

class minHeap{
	vector<int> mheap; 
	int size = 0; 

	public:
	void insert(int val){
		mheap.push_back(val);
		int index = size;		
		heapifyUp(index); 
		size++; 
	}

	void pop(){
		cout << "Popped: " << mheap[0] << endl;
		swapValues(0, size - 1); 
		mheap.pop_back(); 
		heapifyDown(0);
		size--; 
	}	

	int parentIndex(int index){
		int pIndex = ((index - 1) / 2);
		return pIndex; 
	}

	void swapValues(int index1, int index2){
		int temp = mheap[index1]; 
		mheap[index1] = mheap[index2]; 
		mheap[index2] = temp; 
	}

	void heapifyUp(int index){
		if(index > 0){
			int pIndex = parentIndex(index);
			if (mheap[pIndex] >  mheap[index]){
				swapValues(pIndex, index); 
				heapifyUp(pIndex);
			}
		}
	}

	bool hasLeftChild(int index){
		return (index * 2 + 1) < (size - 1); 
	}
	
	bool hasRightChild(int index){
		return (index * 2 + 2) < (size - 1); 
	}

	int getLeftChildIndex(int index){
		return (index * 2 + 1); 
	}

	int getRightChildIndex(int index){
		return (index * 2 + 2); 
	}

	void heapifyDown(int index){
		if(hasLeftChild(index)){
			int lcindex = getLeftChildIndex(index); 
			if(mheap[lcindex] < mheap[index]){
				swapValues(lcindex, index); 
				heapifyDown(lcindex);
			}
			else if(hasRightChild(index)){
				int rcindex = getRightChildIndex(index); 
				if(mheap[rcindex] < mheap[index]){
					swapValues(rcindex, index); 
					heapifyDown(rcindex);
				}
			}
		}
	}

	void printHeap(){
		for(int i = 0; i < mheap.size(); i++){
			cout << i << ":" << mheap[i] << " ";
		}
		cout << endl;
	}
};



int main(){

	srand(time(0));
	minHeap obj; 

	cout << "Adding 20 random elements to heap" << endl;
	for(int i = 0; i < 20; i++){
		int k = rand() % 100; 
		obj.insert(k);
		cout << k << " ";
	}
	cout << endl;
	obj.printHeap();

	int z = rand() % 10;
	cout << "Popping " << z << " elements" << endl;
	for(int i = 0; i < z; i++){
		obj.pop();
	}

	obj.printHeap();
};
