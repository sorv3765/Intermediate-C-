 #ifndef VERIFIER_H
   #define VERIFIER_H
   //*****************************************************************
   // FILE:      Verifier.h
   // AUTHOR:    Shaniel O. Rivas
   // LOGON ID:  z1123907
   // DUE DATE:  09-27-16
   //
   // PURPOSE:   Contains the declaration for the Book class.
   //*****************************************************************

class Verifier
{
public:
	Verifier();
	void readGrid( const char* );
	void printGrid();
	bool verifySolution();

private:
	int rowColumn[9][9];
};

#endif
