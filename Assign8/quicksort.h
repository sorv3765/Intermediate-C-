#ifndef QUICKSORTS_H
#define QUICKSORTS_H

/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Shaniel O. Rivas Verdejo
   LOGON ID:   Z1123907
   DUE DATE:   11-22-16

   FUNCTION:   This program builds and sorts lists using the quick
               sort and merge sort algorithms.
*********************************************************************/

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*************************** Prototype *************************************/

template <class T>
void quickSort(vector<T>&, bool (*)(const T&, const T&));

template <class T>
void quickSort(vector<T>&, int , int , bool (*)(const T&, const T&));

template <class T>
int partition(vector<T>&, int , int , bool (*)(const T&, const T&));


//methods starts here

/***************************************************************
Function: quickSort 
Use: sort vector set using quick sort algorithm. 
Parameters: vector that have list of items, pointer to comparison function that compare two items of template type. 
Returns: nothing 
***************************************************************/ 
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	//call the recursive quick sort function
	quickSort(set, 0, set.size()-1, compare);
}

/***************************************************************
Function: quickSort 
Use: Performs the recursive calls to implement the quick sort algorithms
Parameters: vector set that have list of items, integer start, integer end, pointer to comparison function that compare two items of template type. 
Returns: nothing 
***************************************************************/ 
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotPoint;

	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
	}
}
/***************************************************************
Function: partition
Use: Select a pivot element and then partition the vector around the pivot 
Parameters: vector that have list of items, pointer to comparison function that compare two items of template type. 
Returns: pivotIndex
***************************************************************/ 
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotIndex;
	int mid;

	T pivotValue, temp;

	mid = (start + end) / 2;

	//swap elemnts start and mid of the vector
		temp = set[start];
		set[start] = set[mid];
		set[mid] = temp;

	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++)
	{
		if (compare(set[scan], pivotValue))
		{
			pivotIndex++;
			//swap elements pivotIndex and scan of the vector
			temp = set[pivotIndex];
                	set[pivotIndex] = set[scan];
                	set[scan] = temp;
		}
	}
	//swap elements start and pivotIndex of the vector
	temp = set[start];
	set[start] = set[pivotIndex];
	set[pivotIndex] = temp;


	return pivotIndex;
}

#endif
