 #ifndef BOOK_H
   #define BOOK_H
   //*****************************************************************
   // FILE:      Book.h
   // AUTHOR:    Shaniel O. Rivas
   // LOGON ID:  z1123907
   // DUE DATE:  09-20-16
   //
   // PURPOSE:   Contains the declaration for the Book class.
   //*****************************************************************

class Book
{
public:
    Book();
    Book( char [], char [], double , int );

    char* getISBN();
    char* getTitle();
    double getPrice();
    int getQuantity();
    int fulfillOrder( int );
    
    void setPrice( double );
    void setQuantity( int );
    void print();
    
private:
    char ISBN[11];
    char title[41];
    double price=0;
    int quantity=0;
    int numShipped;
    
};

#endif
