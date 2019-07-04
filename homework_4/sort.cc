#include "sort.h"
#include <vector>
#include <iostream>
#include <typeinfo>
#include <cassert>
namespace homework_4 {

using std::vector;

template<class T> void BubbleSort(vector<T>* vec) {
	//vec is an undsorted vector 
	int length = vec->size();
	int counter;
	int temp;

	while(counter != 0) {
		//counter is to count how many swaps there are so the program knows.
		counter = 0;
		//start of buble sort algorithm
		for (int i=0; i<length-1; i++){
			if (vec->at(i) > vec->at(i+1)) {
				temp = vec->at(i+1);
				vec->at(i+1) = vec->at(i);
				vec->at(i) = temp;
				counter = counter + 1;
			}
		}

		length--;
	}
}

 
template<class T> void InsertionSort(vector<T>* vec) {
	int length = vec->size();
	int temp;
	int i = 1;
	while(i < length) {
		int j=i;
		while (j>0 and vec->at(j-1) > vec->at(j)){
			temp = vec->at(j-1);
			vec->at(j-1) = vec->at(j);
			vec->at(j) = temp;
			j=j-1;
		}
		i = i+1;
	}
}

//this function will split the array into values higher and lower than the pivot point,
//which will be the value at the highest index. 
int Moses(vector<int>* vec, int low, int high) {
	int temp;
	int pivot = vec->at(high); //pivot at highest index
	int i = (low-1); //index of smaller element, because this function will be running multiple times
	//this loop will be for cycling and sorting all values as it goes through the vector. Records
	//i Indicates the index of the highest value less than the Pivot. 
	for (int j=low; j<=high-1; j++) {
		//comparing the vec value at location J to pivot
		if (vec->at(j) <= pivot){
			//increment i to go through and record the lowest index of the value which is lower than pivot
			i++;
			temp = vec->at(i);
			vec->at(i) = vec->at(j);
			vec->at(j) = temp;
		}
	}
	//once the for loop goes through the vector, i should indicate the number closest to, the pivot.

	//swap the pivot with the number in the index one higher than i. 
	temp = vec->at(i+1);
	vec->at(i+1) = vec->at(high);
	vec->at(high) = temp;

	//return the location of the next "high" location for the recursive process. 
	return (i+1);
}
template<class T> void Quickie(vector<T>* vec, int low, int high){
	if (low < high){
		//call upon moses to split the red sea that is vec
		int pivot_index = Moses(vec, low, high);
		//runs quicksort again and sorts through everything less than the pivot. Also generates
		//new pivots for smaller segments as the recursion happens.
		Quickie(vec, low, pivot_index-1);
		//same but for everything larger than the pivot
		Quickie(vec, pivot_index+1, high);

	}

}
template<class T> void QuickSort(vector<T>* vec) {
	int length = vec->size();
	int high = length-1;
	int low = 0;
	Quickie(vec, low, high);
}

//Merge Function. takes the given ranges left-mid, and mid+1-right and stores it into an array.
//Compares the two arrays and merges them into a larger array sorted. 
//Will work and sort longer arrays as well.
template <class T> void Merge(vector<T>* vec, int left, int right, int mid){
	int left_counter = 0; //will be a counter utilized multiple times to go through the left array
	int right_counter = 0;//will be a counter utilized multiple times to go through the right array
	int thru_counter = left; //a counter that ges through the entire length of each array.

	int left_size = mid - left+1; //Left might be 0, and index 0 holds a value, so we add one. 
	int right_size = right - mid; 

	int left_array[left_size];		//initialize left array of size left_size
	int right_array[right_size];	//initialize right array of size right_size

	//copies data from vector vec in range left to the size of left_size into an array to be compared later
	for (left_counter = 0; left_counter < left_size; left_counter++){
		left_array[left_counter] = vec->at(left + left_counter);
	}

	for (right_counter = 0; right_counter < right_size; right_counter++){
		right_array[right_counter] = vec->at(mid + 1 + right_counter);
	}

	left_counter = 0; //reset left counter to 0 to be utilized again
	right_counter = 0;	//reset right counter to 0 to be utilized again

	//the while loop will compare left array and right array and store the corresponding correct, sorted
	//values within vector vec.
	while (left_counter < left_size and right_counter < right_size){ 
		//if left side of the array is less than the right side of the array, store the value of left array
		//at index (thru_counter). 
		if (left_array[left_counter] <= right_array[right_counter]){
			vec->at(thru_counter) = left_array[left_counter];
			left_counter++;
		}
		//same as above but for right counter.
		else {
			vec->at(thru_counter) = right_array[right_counter];
			right_counter++;
		}
		//increment thru_counter for the next index in vector for longer array sizes.
		thru_counter++;
	}

	//if there are still values left within the arrays in case right array gets finished sorting first, 
	//place leftover values in vec in order. 
	while (left_counter < left_size){ 
		vec->at(thru_counter) = left_array[left_counter];
		left_counter++;
		thru_counter++;
	}

	while (right_counter < right_size){
		vec->at(thru_counter) = right_array[right_counter];
		right_counter++;
		thru_counter++;
	}

} 
//"splits" vector vec into smaller ranges that will be stored into an array in Merge Function
//and will then overwrite vec with the sorted values.
template<class T> void Recursive_Split(vector<T>* vec, int left, int right){
	//if left < right, continue with recursion to split and then merges once all the arrays are size 1.
	//if right = left or right>left, stops recursive split.
	if (left < right) {
		//mid is the index of vector of the average of left and right. ie, if left = 4 and right = 9
		//mid will then equal (4+9)/2 => 6.
		int mid = (left+right)/2;

		//Creates an instance where the vector values accessible are between the left most value and mid.
		Recursive_Split(vec, left, mid);

		//creates an instance where vector values accessible is between mid+1 (no overlap) and right.
		Recursive_Split(vec, mid+1, right);
		
		//Starts the merge
		Merge(vec, left, right, mid);
	}	
}

template<class T> void MergeSort(vector<T>* vec) {
  	int left = 0;
  	int right = vec->size()-1;
  	Recursive_Split(vec, left, right);
}

template void BubbleSort<int>(vector<int>* vec);
template void InsertionSort<int>(vector<int>* vec);
template void QuickSort<int>(vector<int>* vec);
template void MergeSort<int>(vector<int>* vec); 

 

}  // namespace homework_4



 