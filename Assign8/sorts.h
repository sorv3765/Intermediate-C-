#ifndef SORT_H
#define SORT_H

/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Shaniel O. Rivas Verdejo
   LOGON ID:   Z1123907
   DUE DATE:   11-22-16

   FUNCTION:   This program builds and sorts lists using the quick
               sort and merge sort algorithms.
*********************************************************************/

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::setw;
using std::right;
using std::vector;

/**************** Prototypes *******************************/
template <class T>
void buildList(vector<T>&, const char*);

template <class T>
void printList(const vector<T>&, int, int);

template <class T>
bool lessThan(const T&, const T&);

template <class T>
bool greaterThan(const T& item1, const T& item2);



//Method starts here

/***************************************************************
Function: BuildList 
Use: Read items from an input file and put them into a vector 
Parameters: vector that will be used to store the items, string conating the full pathnae of the input file. 
Returns: nothing 
***************************************************************/ 
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile;
	inFile.open(fileName);		// Open inFile for input using fileName as the name of the file to ope

	if (!inFile)	// Check that the file has been successfully opened
  	{
  		cout << "open for test.dat failed" << fileName << endl;	// exit the program
  	}

  	// Check that the file has been successfully opened
	inFile >> item;
  	// Read item from input file
	while (inFile)
      	{
      		set.push_back(item);
    	//  Read item from input file
      		inFile >> item;
	}

 	// Close the input file
	inFile.close();

}

/***************************************************************
Function: printList 
Use: Print a list of items stored in a vector. 
Parameters: vector object conatin the items to print, integer of width an item should occupy when printed, integer specify the max number of items that should be printed in a single line of output 
Returns: nothing 
***************************************************************/ 

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int i;

	for (i = 0; i < set.size(); i++)
	{
		cout << setw(itemWidth) << right << set[i] << ' ';

		if ((i+1) % numPerLine == 0)
			cout <<endl;
	}

	cout << endl;
}

/***************************************************************
Function: lessThan 
Use: compare two items to see which is less than 
Parameters: item1, item2 
Returns: boolean
***************************************************************/ 

template <class T>
bool lessThan(const T& item1, const T& item2)
{
	if (item1 < item2)
		return true;
	else
		return false;
}

/***************************************************************
Function: greaterThan 
Use: compare two items to see which is greater than 
Parameters: item1, item2 
Returns: boolean
***************************************************************/ 

template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	if (item1 > item2)
		return true;
	else
		return false;
}

#endif
