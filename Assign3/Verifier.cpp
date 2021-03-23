#include <iostream>
#include <fstream>

#include "Verifier.h"

using std::cout;
using std::endl;
using std::ifstream;

Verifier::Verifier()
{
	for( int rowSub=0; rowSub < 9; rowSub++)				//each row
	{
		for(int colSub=0; colSub < 9; colSub++)				//each column
		{
		rowColumn[rowSub][colSub]=0;					// each box is set to 0 for 81 boxes
		}
	}
}

void Verifier::readGrid( const char* fileName )
{
 ifstream inFile;

inFile.open( fileName );							//reading to see if the file opens or not
        if(!inFile)
        {

        cout << "Error file" << fileName << "cannot be accessed " << endl;
        exit(1);

	
        }

	for( int rowSub=0; rowSub < 9; rowSub++)
        {

                for(int colSub=0; colSub < 9; colSub++)
                {
                inFile >> rowColumn[rowSub][colSub];				//replace each number/character in each box of rows/columns
                }

        }

inFile.close();
}

void Verifier::printGrid()
{
	cout << " ------------------- ";

	for( int rowSub=0; rowSub < 9; rowSub++)
        {
		cout << endl << "|";

                for(int colSub=0; colSub < 9; colSub++)
                {
               		cout << " " << rowColumn[rowSub][colSub];			//display a space then each number that has been read/replaced in from the file

		}

		cout << " |";
	}
	cout << endl << " ------------------- ";
}

bool Verifier::verifySolution()
{
	int product = 1;

 	for( int rowSub=0; rowSub < 9; rowSub++)						//starts checking each nine rows
        {
                for(int colSub=0; colSub < 9; colSub++)						//cheacking in every column by rows
                {
                	product=product*rowColumn[rowSub][colSub];
                }
        		if(product!=362880)
			{
				return false;
			}
			else
			{
				product=1;
			}
	}

 	for( int colSub=0; colSub < 9; colSub++)						//starts checking each nine columns
        {
                for(int rowSub=0; rowSub < 9; rowSub++)						//checking in every nine rows by column
                {
                	product=product*rowColumn[rowSub][colSub];
                }

     			if(product!=362880)
			{
				return false;
			}
			else
			{
				product=1;
			}


	}

	for( int rowSub=0; rowSub < 3; rowSub++)						//check each three rows in 3x3 grid
	{
		for( int colSub=0; colSub < 3; colSub++ )					//check each three column in 3x3 grid
		{
			for(int sqrowSub = rowSub*3; sqrowSub < rowSub*3+3; sqrowSub++)		//check for each 3x3 grid by row

				for(int sqcolSub = colSub*3; sqcolSub < colSub*3+3; sqcolSub++)	//check for each 3x3 grid by column
				{
					product=product*rowColumn[sqrowSub][sqcolSub];
				}

					if(product!=362880)					//if found an error its considered invalid
					{
						return false;
					}
					else
					{
						product=1;
					}
		}
	}

return true;
}
