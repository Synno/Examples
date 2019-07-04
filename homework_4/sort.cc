#include "sort.h"
#include<iostream>
#include <vector>
#include<typeinfo>
#include<cassert>
#include<stdio.h>
namespace homework_4 {

using std::vector;

template<class T> void BubbleSort(vector<T>* vec) {
	//vec is pointer to vector
	std::cout << "start sort now" << std::endl;
	
	int length = vec->size();
	int counter;
	int temp;
	while(counter != 0) {
		counter = 0;
		for (int i = 0; i < length-1; i++) { //one pass
			if (vec->at(i) > vec->at(i+1)) {
				temp = vec->at(i+1);
				vec->at(i+1) = vec->at(i);
				vec->at(i) = temp;
				counter = counter + 1;	
			}
		}
		length = length-1;
	}
}

template<class T> void InsertionSort(vector<T>* vec) {

  std::cout << "start again" << std::endl;
  int length = vec->size();
  int i = 1;
  int temp;

  while (i < length) {
  	int j = i;
  	while (j > 0 and vec->at(j-1) > vec->at(j)) {
  		temp = vec->at(j-1);
  		vec->at(j-1) = vec->at(j);
  		vec->at(j) = temp;
  		j--;
  	}
  	i++;
  }
}

template<class T> void quicksort_func(vector<T>* vec, int first,int last) {

  int i = first;
  int j = last;
  int pivot = vec->at((first+last)/2);
  int temp;
  
  while (i <= j) {
  	while (vec->at(i) < pivot) {
  		i++; //set ito a point higher than pivot
  	} // i = less than pivot, but value vec->at(i) greater than pivot, or
  	  // i = index of pivot
  	while (vec->at(j) > pivot) {
  		 j--; //set j to a power lower than pivot
  	}
  	if (i <= j) {
		temp = vec->at(i);
		vec->at(i) = vec->at(j);
		vec->at(j) = temp;
		i++;
		j--;
	  }
  }
  if (first < j) { //left of pivot
  	quicksort_func(vec,first,j);
  }
  if (i < last) { //right of pivot
  	quicksort_func(vec,i,last);
  }
}

template<class T> void QuickSort(vector<T>* vec) {
  std::cout << "start again" << std::endl;
  int length = vec->size()-1;
  quicksort_func(vec,0,length);
}

template <class T> void opposite_moses(vector<T>* vec, int left, int right, int mid) {
	int i; 
	int j;
	int k;

	int x = mid - left + 1; //rightmost on left array
	int y = right - mid; //leftmost on right array

	int left_array[x]; //initialize left array of x size 
	int right_array[y]; //initialize right array of y size

	for (i = 0; i < x; i++) { //copy data over to left/right array
		left_array[i] = vec->at(left+i);
	}
	for (j = 0; j < y; j++) {
		right_array[j] = vec->at(mid+j+1);
	}

	i = 0; //counter thru left array 
	j = 0; //counter thru right array 
	k = left; //goes thru all of it

	while (i < x and j < y) { //merge temp arrays back to vec - correctly! 
		if (left_array[i] <= right_array[j]) { //if left array is less than right array
			vec->at(k) = left_array[i];		   //set vec to left array value
			i++;
		}
		else {
			vec->at(k) = right_array[j];	   //set vec to right array otherwise
			j++;
		}
		k++;
	}
	while (i < x) { //bring that shit back if there are stuff left in left_array
		vec->at(k) = left_array[i];
		i++;
		k++;
	}
	while (j < y) { //same tbh
		vec->at(k) = right_array[j];
		j++;
		k++;
	}
}

template<class T> void fuck(vector<T>* vec, int left, int right) {
	if (left < right) {
		int mid = (left+right)/2;
		fuck(vec,left,mid); //left array
		fuck(vec,mid+1,right); //right array
		opposite_moses(vec,left,right,mid);
	}

}

template<class T> void MergeSort(vector<T>* vec) {
  std::cout << "run" << std::endl;
  int left = 0;
  int right = vec->size()-1;
  fuck(vec,left,right);
}

template void BubbleSort<int>(vector<int>* vec);
template void InsertionSort<int>(vector<int>* vec);
template void QuickSort<int>(vector<int>* vec);
template void MergeSort<int>(vector<int>* vec);

}  // namespace homework_4
