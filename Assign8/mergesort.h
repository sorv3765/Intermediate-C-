#ifndef MERGESORT_H
#define MERGESORT_H

/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Shaniel O. Rivas Verdejo
   LOGON ID:   Z1123907
   DUE DATE:   11-22-16

   FUNCTION:   This program builds and sorts lists using the quick
               sort and merge sort algorithms.
*********************************************************************/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/********************* Prototype *****************************/
template <class T>
void mergeSort(vector<T>&, bool (*)(const T&, const T&));

template <class T>
void mergeSort(vector<T>&, int, int, bool (*)(const T&, const T&));

template <class T>
void merge(vector<T>&, int, int, int, bool (*)(const T&, const T&));

//Methods starts here
/***************************************************************
Function: mergeSort 
Use: sort vector set using merge sort algorithm. 
Parameters: vector that have list of items, integer low, integer high, pointer to comparison function that compare two items of template type. 
Returns: nothing 
***************************************************************/ 
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	// should call the recursive merge sort function
	mergeSort(set, 0, set.size()-1, compare);
}

/***************************************************************
Function: mergeSort 
Use: recursive function divide a vector into two subvectors, sorts them, and then merges the two sorted subvectors. 
Parameters: vector that have list of items, integer low, integer high, pointer to comparison function that compare two items of template type. 
Returns: nothing 
***************************************************************/ 
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{

	int mid;

	if (low < high)
      	{
      		mid = (low + high) / 2;

      		// Divide and conquer
      		mergeSort(set, low, mid, compare);
      		mergeSort(set, mid+1, high, compare);

      		// Combine
      		merge(set, low, mid, high, compare);
      	}

}

/***************************************************************
Function: merge 
Use: merges two sorted subvectors. 
Parameters: vector that have list of items, integer low, integer mid, integer high, pointer to comparison function that compare two items of template type. 
Returns: nothing 
***************************************************************/ 

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
	// Create temporary vector to hold merged subvectors
   	vector<T> temp(high - low + 1);

   	int i = low;      // Subscript for start of left sorted subvector
   	int j = mid+1;    // Subscript for start of right sorted subvector
   	int k = 0;        // Subscript for start of merged vector

   	// While not at the end of either subvector
   	while (i <= mid && j <= high)
      	{
      		if (compare(set[j], set[i]))
         	{
         		temp[k++] = set[j++];	//Copy element j of set into element k of temp....Add one to j....Add one to k
         	}
      		else
        	{
         		temp[k++] = set[i++];	//Copy element i of set into element k of temp.......Add one to i.....Add one to k
        	}
	}

   	// Copy over any remaining elements of left subvector
   	while (i <= mid)
      	{
      		temp[k++] = set[i++];	//Copy element i of set into element k of temp......Add one to i......Add one to k
      	}

   	// Copy over any remaining elements of right subvector
   	while (j <= high)
      	{
      		temp[k++] = set[j++];	//Copy element j of set into element k of temp.......Add one to j.......Add one to k
      	}

   	// Copy merged elements back into original vector
   	for (i = 0, j = low; j <= high; i++, j++)
      	{
		set[j] = temp[i];	//Copy element i of temp into element j of set
	}
}
#endif
