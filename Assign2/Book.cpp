/***********************************************************
 CSCI 241 - Assignment 2 - Fall 2016
 
 Progammer: Shaniel O. Rivas
 Z-ID: z1123907
 Section: 3
 TA: Karthik Kondagalla
 Date Due: September 20, 2016
 
 Purpose: This is the Book Class
 ************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Book.h"

using std::cout;
using std::ios;
using std::endl;
using std::fixed;
using std::setw;
using std::setprecision;
using std::left;
using std::right;

/***************************************************************
 Methods:  Book: the default constructor
 
 Use: This Methods, the default constructor (the constructor that takes no paremters)
 
 Arguments: The class should initialize the data members so that:
 
 Use the strcpy function to initialize the ISBN and Title. Price and quantity should be set to 0.
 
 Returns: No data types
 ***************************************************************/

Book::Book()
{
    strcpy(ISBN," ");
    strcpy(title, " ");
    price=0;
    quantity=0;
    
}

/***************************************************************
 Methods:  Book: the alternative constructor
 
 Use: This constructor takes four parameters.
 
 Parameters: The class should char array that contains a new ISBN, a char array that contains a new title, a double variable that contains a new price, and an integer that contains a new quantity:
 
 Returns: all the data members
 ***************************************************************/
Book::Book( char newISBN [], char newTitle [], double newPrice, int newQuantity)
{
    
    strcpy(ISBN, newISBN);
    
    strcpy(title, newTitle);
    
    setPrice(newPrice);
    
    setQuantity(newQuantity);
}

/***************************************************************
 Methods:  Get ISBN
 
 Use: This accessor method takes no parameters
 
 Parameters: None.
 
 Returns: Nothing.
 ***************************************************************/
char* Book::getISBN()
{
     return ISBN;
}

/***************************************************************
 Methods:  Get Title
 
 Use: This accessor method takes no parameters.
 
 Parameters: None.
 
 Returns: Title data member
 ***************************************************************/
char* Book::getTitle()
{
    return title;
}

/***************************************************************
 Methods:  Get Price
 
 Use: This accessor method takes no parameters.

 Parameters: None.
 
 Returns: Price data member.
 ***************************************************************/
double Book::getPrice()
{
    return price;
}

/***************************************************************
 Methods:  Get Quantity of Stocks
 
 Use: This accessor method takes no parameters.
 
 Parameters: None. 
 
 Returns: Quantity data member.
 ***************************************************************/
int Book::getQuantity()
{
    return quantity;
}

/***************************************************************
 Methods:  Fulfill Order
 Use: This accessor method takes one parameter.
 
 Parameter: An integer that represents theat represent the quantity of this book that has been ordered.
 
 
 Returns: An integer.
 ***************************************************************/
int Book::fulfillOrder( int newQuantity)
{

    if(newQuantity < 0)
    {
        cout << "There's an error! " << endl;
	numShipped = 0;
    }
    else if(newQuantity <= quantity)
    {
        numShipped=newQuantity;
	quantity-=newQuantity;
    }
    else
    {
        numShipped=quantity;
	quantity=0;
    }
   
    return numShipped;
}

/***************************************************************
 Methods:  Set Price
 
 Use: This method takes a double arguement
 
 Arguments: New Price.
 
 Returns: double data type.
 ***************************************************************/
void Book::setPrice( double newPrice)
{
    if( newPrice >= 0)
    {
        price = newPrice;
    }
    else
    {
        newPrice=0;
    }
}

/***************************************************************
 Methods:  Set Quantity
 
 Use: This method to see if the program points are within the range.
 
 Arguments: New Quantity.
 
 Returns: An integer.
 ***************************************************************/
void Book::setQuantity( int newQuantity )
{
    
    if( newQuantity>=0 )
    {
        quantity=newQuantity;
    }
    else
    {
        newQuantity=0;
    }
}

/***************************************************************
 Methods:  Print
 
 Use: The method should print the ISBN, title, price, and quantity members on the console using cout. Use setw() to line the printed values up in columns (a width of 14 for the ISBN, 44 for the title, 5 for the price, and 6 for the quantity will match the sample output). The ISBN and title should be left justified; the price and quantity should be right justified. The price should be printed using fixed-point notation with two places after the decimal point.
 
 Parameters: None.
 
 
 Returns: Nothing.
 ***************************************************************/
void Book::print()
{
    cout << fixed << setw(14) << left << ISBN;
    
    cout << fixed << setw(44) << left << title;
    
    cout << fixed << setw(5) << right << setprecision(2) << price;
    
    cout << fixed << setw(6) << right << quantity << endl;
}

