#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include "Book.h"

   //*****************************************************************
   // FILE:      BookStore.h
   // AUTHOR:    Shaniel O Rivas
   // LOGON ID:  z1123907
   // DUE DATE:  09-20-16
   //
   // PURPOSE:   Contains the declaration for the BookStore class.
   //*****************************************************************
class BookStore
 {
 public:
	BookStore();
	BookStore(const char*);
	void print();
	void sortByISBN();
	int searchForISBN(char* searchISBN);
	void processOrders(const char*);

 private:
 	Book book[30];
 	int totalQuantity;
 };

#endif
