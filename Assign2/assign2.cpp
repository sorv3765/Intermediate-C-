/***********************************************************
 CSCI 241 - Assignment 2 - Fall 2016
 
 Progammer: Shaniel O. Rivas
 Z-ID: z1123907
 Section: 3
 TA: Karthik Kondagalla
 Date Due: September 20, 2016
 
 Purpose: This is the main class
 ************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>

#include "BookStore.h"

using std::cout;
using std::endl;

int main()
{

BookStore store("bookdata");
store.print();
store.processOrders("orders.txt");
cout << endl;
store.print();

/*****
Create a BookStore object using the alternate constructor you wrote. Pass the filename string "bookdata" as an argument to the constructor.
Call the print() method for the BookStore object.
Call the processOrders() method for the BookStore object. Pass the filename string "orders.txt" as an argument to the method.
Call the print() method for the BookStore object.
******/
return 0;
}
