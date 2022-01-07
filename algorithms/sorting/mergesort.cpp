#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

vector<int> merge(vector<int> leftarr, vector<int> rightarr){
	vector<int> res; 
	vector<int>::iterator iterl = leftarr.begin(); 
	vector<int>::iterator iterr = rightarr.begin(); 
	//cout << leftarr.size() << " " << rightarr.size() << endl;

	while(iterl != leftarr.end() && iterr != rightarr.end()){
		if (*iterl > *iterr){
			res.push_back(*iterr);
			iterr++;
		}
		else if(*iterl < *iterr){
			res.push_back(*iterl);
			iterl++;
		}
		else{
			res.push_back(*iterl);
			res.push_back(*iterl);
			iterl++;
			iterr++;
		}
	}

	while(iterl != leftarr.end()){
		res.push_back(*iterl);
		iterl++;	
	}
	while(iterr != rightarr.end()){
		res.push_back(*iterr);
		iterr++;
	}
	
	return res;
}

void mergesort(vector<int>& arr){
	if(arr.size() < 2){
		return;
	}
	int mid_point = arr.size() / 2;
	vector<int> leftarr = vector<int>(arr.begin(), arr.begin() + mid_point);
	vector<int> rightarr = vector<int>(arr.begin() + mid_point, arr.end());
	mergesort(leftarr);
	mergesort(rightarr);
	arr = merge(leftarr, rightarr);
}




int main(){

	srand(time(0));

	vector<int> arr; 
	cout << "Adding 20 random elements to array" << endl;
	for(int i = 0; i < 10; i++){
		int k = rand() % 100; 
		arr.push_back(k);
		cout << k << " ";
	}
	cout << endl;

	mergesort(arr);
	cout << "Printing Sorted Array " << endl;
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;	
};
