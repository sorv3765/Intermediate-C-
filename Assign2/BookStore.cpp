/***********************************************************
 CSCI 241 - Assignment 2 - Fall 2016
 
 Progammer: Shaniel O. Rivas
 Z-ID: z1123907
 Section: 3
 TA: Karthik Kondagalla
 Date Due: September 20, 2016
 
 Purpose: This is the BookStore Class
 ************************************************************/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include <array>

#include "BookStore.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::setprecision;
using std::left;
using std::right;
using std::setw;
using std::fixed;

/***************************************************
Default constructor for BookStore class

Uses: calls  to create an empty database and set the number of books.

Parameters: None.

Return: None.
***************************************************/
BookStore::BookStore()
{
totalQuantity = 0;
}


/**************************************************
**************************************************/
BookStore::BookStore(const char* fileName)
{
ifstream inFile;
inFile.open(fileName, ios::binary);
	if(!inFile)
	{

	cout << "Error file" << fileName << "cannot be accessed " << endl;
	exit(1);

	}

inFile.read((char*) this, sizeof(BookStore));

inFile.close();

sortByISBN();
}

/************************************************

************************************************/
void BookStore::print()
{

cout << "Book Inventory Listing " << endl << endl;

cout << "ISBN" << fixed << setw(15) << "Title" << setw(44) << "Price" << setw(7) << "Qty." << endl << endl;

	for(int i = 0; i < totalQuantity; i++)
	{
	book[i].print();

	}

cout << endl;

}

/************************************************

************************************************/
void BookStore::sortByISBN()
{
int i, j;
Book bucket;
	for(i=1; i<totalQuantity;i++)
	{
	bucket=book[i];
		for(j=i; (j>0) && (strcmp(book[j-1].getISBN(), bucket.getISBN())>0); j--)
		{
		book[j]=book[j-1];
		}

	book[j]=bucket;
	}
}

int BookStore::searchForISBN(char* searchISBN)
{
int low = 0;
int high = totalQuantity-1;
int mid;

	while(low<=high)
	{
		mid= (low+high) / 2;
		if(strcmp(searchISBN, book[mid].getISBN())==0)
		{
		return mid;
		}

		if(strcmp(searchISBN, book[mid].getISBN())<0)
		{
		high=mid-1;
		}
		else
		{
		low=mid+1;
		}
	}

return -1;
}

void BookStore::processOrders(const char* fileName)
{

char orderNumber[7];
char ISBN[11];
int orderQuantity;
int numShipped;
cout << "Order Listing " << endl << endl;

ifstream inFile;
inFile.open(fileName);
	if(!inFile)
	{
	cout << "Error file" << fileName << "cannot be processed" << endl;
	exit(1);
	}

	inFile >>orderNumber;
		while(inFile)
		{
		inFile >> ISBN;
		inFile >> orderQuantity;

		int index = searchForISBN(ISBN);
			if(index==-1)
			{
			cout << "Order #" << orderNumber << ": error - " << "ISBN " << ISBN << " does not exist" << endl;
			}
			else
			{
			numShipped=book[index].fulfillOrder(orderQuantity);
			cout << "Order #" << orderNumber << ": ";
			cout << " ISBN " << ISBN;
			cout << ", " << numShipped;
			cout << " of " << orderQuantity;
			cout << " shipped, order total " << "$" << numShipped*book[index].getPrice() << endl;
			}

			inFile >> orderNumber;
		}
inFile.close();
}
