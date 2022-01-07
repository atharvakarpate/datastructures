#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int binarysearch(vector<int> arr, int val){
	int mid_point = arr.size() / 2;
	//cout << "Midpoint" << mid_point <<  " " << arr[mid_point] << endl;
	if (val == arr[mid_point]){
		return mid_point;
	}
	if (arr.size() < 2){
		return -1;
	}
	else if(val > arr[mid_point]){
		vector<int> new_arr = vector<int>(arr.begin() + mid_point, arr.end()); 
		return binarysearch(new_arr, val) + mid_point;
	}
	else if(val < arr[mid_point]){
		vector<int> new_arr = vector<int>(arr.begin(), arr.begin() + mid_point); 
		return binarysearch(new_arr, val);
	}
}
			

		


int main(){

	srand(time(0));

	vector<int> arr; 
	cout << "Adding 20 random elements to array" << endl;
	for(int i = 0; i < 20; i++){
		int k = rand() % 100; 
		arr.push_back(k);
		cout << k << " ";
	}
	cout << endl;

	sort(arr.begin(), arr.end());
	cout << "Printing Sorted Array " << endl;
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Choose element to search" << endl;
	int k;
	cin >> k; 

	int index = binarysearch(arr, k); 

	if(index != -1){
		cout << "Element found at index: " << index << endl; 
	}
	else{
		cout << "Element not found!"  << endl;
	}	
		
};
