#include<iostream>

#define min_capacity 16
using namespace std;
 
// main function -
// where the execution of program begins

class dArray {

	public:
		dArray(int capacity);
		~dArray();
		void printIndex(int index);
		void modifyIndex(int index, int value); 
		void append(int value); 
		void removeAt(int index); 
		void printdArray(void); 

	private:
		int* arr; 
		int arr_len; 
		int arr_capacity; 

};

dArray::dArray(int capacity = min_capacity){
	arr_capacity = capacity;
	arr_len = 0;
	arr = (int*)malloc(arr_capacity * sizeof(*arr)); 
	cout << "Capacity = " << capacity << "\n";
}       	

dArray::~dArray(){
	free(arr);
}; 

void dArray::append(int value){
	if ((arr_len + 1) > arr_capacity) { 
		int *temp_arr = (int*)malloc(arr_capacity * sizeof(*arr)); //Creating a Temporary array
	       	temp_arr = arr; 	
		arr_capacity *= 2; 
		arr = (int*)malloc(arr_capacity * sizeof(*arr));

		cout<< "Doubling in size. New Capacity = " << arr_capacity << "\n"; 

		//Copy elements from temporary array 
		for (int i = 0; i < arr_capacity/2; i++){
			arr[i] = temp_arr[i];
		}

		free(temp_arr); 
		arr[arr_len] = value; 
		cout << arr[arr_len] << "\n";
		arr_len++; 


	}
	else {
		arr_len++;
		arr[arr_len] = value;
		cout << arr[arr_len] << "\n";
	}
}


void dArray::removeAt(int index){
	if (((arr_len - 1) < arr_capacity/2) && ((arr_len - 1) > min_capacity)) {
		cout << "Array Can be shortened \n";
	}
	else {
		for (int i = index; i < arr_len; i++){
			arr[i] = arr[i+1];
		}
		arr_len--; 

		cout << "Item removed \n";
	}
}

		
void dArray::printdArray(void){
	for (int i = 0; i < arr_len; i++){
		cout << arr[i] << "\n"; 
	}
}		


void dArray::printIndex(int index){
	if (index >= arr_len){
		cout << "Invalid Index"; 
	}
	else {
		cout << "The value at index " << index << " = " << arr[index] << "\n";
	}
}	


void dArray::modifyIndex(int index, int value){
	if (index > arr_len - 1){
		cout << "Invalid Index"; 
	}
	else {
		arr[index] = value;
		cout << "Value Changed \n";
	}
}




int main()
{
	dArray test;
	for (int i = 0; i < 18; i++){
		test.append(i);
	}	
	test.printIndex(17);
	test.modifyIndex(17, 45);
	test.printIndex(17);

}
