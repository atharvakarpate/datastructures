#include <iostream> 
#include <stdlib.h>
#include <typeinfo> 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

void swapel(vector<int>& arr, int index1, int index2){
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int partition(vector<int>& arr, int left, int right, int pivot){
	// swap right and pivot_el
	swapel(arr, pivot, right);
	pivot = right; 
	right--;
	
	while(left <= right){
		if(arr[left] <= arr[pivot]){
			left++;
		}
		else if(arr[right] > arr[pivot]){
			right--;
		}
		else{
			swapel(arr, left, right);
			left++;
			right--;
		}
	}
	swapel(arr, left, pivot);

       	return left;
}	


void quicksort(vector<int>& arr, int left, int right){
	if (left >= right || left < 0){
		return;
	}

	int pivot = (left + right) / 2; 
	int index = partition(arr, left, right, pivot);
	quicksort(arr, left, index - 1); 
	quicksort(arr, index + 1, right);
}

		

void quicksort(vector<int>& arr){
	quicksort(arr, 0, arr.size() - 1);
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

	quicksort(arr);
	cout << "Printing Sorted Array " << endl;
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;	
};
