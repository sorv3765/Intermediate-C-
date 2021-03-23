/***********************************************************
 CSCI 241 - Assignment 1 - Fall 2016
 
 Progammer: Shaniel O. Rivas
 Z-ID: z1123907
 Section: 3
 TA: Karthik Kondagalla
 Date Due: September 8, 2016
 
 Purpose: Create a the Numerology Program using c strings 
 ************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::ostringstream;

//function prototypes
void getString();
void convString();
int totalSum();
bool checkValue(int);
void outString(int);

//global variables
char *stringer= new char[256];
int *out = new int[256];
int size = 0;




int main()
{
    
    cout << std::setiosflags(ios::fixed);               //Setting the IOS flag for the entire  program.
    bool contest = true;
    
    cout << "Numerology Program " << endl;
    cout << "Let's Begin " << endl << endl;
    
    while(contest)
    {
        getString();
        convString();
        bool contest2 = false;
        
        while(!contest2)
        {
            delete[] stringer;
            stringer= new char[256];
            int check = totalSum();
            sprintf (stringer, "%d", check);
            convString();
            
            contest2 = checkValue(totalSum());
        }
        
        outString(totalSum());
        
        contest = false;
        cout << "Another? (y/n)";
        char response;
        //cin.sync();
        cin >> response;
        cin.ignore(1000, '\n');
        cin.clear();
        
        if((response == 'y') || (response == 'Y'))
        {
            contest = true;
        }
        cout << endl;
        
    }
    
    cout << "Alright come play again next time! " << endl;
    
    return 0;
}

/******************************************************
 Getting inputs from user and clear previous inputs
 ******************************************************/
void getString()
{
    delete[] stringer;
    stringer= new char[256];
    cout << "Enter a name: ";
    cin.clear();
    cin.sync();
    cin.getline(stringer, 256);
}

/******************************************************
 Convert all strings into proper numerical values
 ******************************************************/
void convString()
{
    delete[] out;
    out = new int[256];
    size = strlen(stringer);
    for(int i = 0; i < size; i++)
    {
        out[i] = 0;
        if(isalpha(stringer[i]))
        {
            stringer[i] = tolower(stringer[i]);
            out[i] = stringer[i] - 96;
        }
        else if(isdigit(stringer[i]))
        {
            out[i] = stringer[i] - 48;
        }
    }
}

/******************************************************
 Adding and calculating the total numerical values
 ******************************************************/
int totalSum()
{
    int total = 0;
    for(int i = 0; i < size; i++)
    {
        total += out[i];
    }
    return total;
}

/******************************************************
 The purpose of this function is to checks if value is within range
 ******************************************************/
bool checkValue(int total)
{
    if((total == 11) || (total == 12) || (total == 22))
    {
        return true;
    }
    else if((total < 0) || (total > 9))
    {
        return false;
    }
    else
    {
        return true;
    }
}

/******************************************************
 Shows the traits for the name without returning anything
 ******************************************************/
void outString(int value)
{
    cout << "That name has the traits ";
    if(value == 0)
    {
        cout << "emptiness, nothingness, blank" << endl;
    }
    else if(value == 1)
    {
        cout << "independence, loneliness, creativity, originality, dominance, leadership, impatience" <<endl;
    }
    else if(value == 2)
    {
        cout << "quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient" << endl;
    }
    else if(value == 3)
    {
        cout << "charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud" << endl;
    }
    else if(value == 4)
    {
        cout << "harmony, truth, justice, order discipline, practicality" << endl;
    }
    else if(value == 5)
    {
        cout << "new directions, excitement, change, adventure" << endl;
    }
    else if(value == 6)
    {
        cout << "love, harmony, perfection, marriage, tolerance, public service" << endl;
    }
    else if(value == 7)
    {
        cout << "spirituality, completeness, isolation, introspection" << endl;
    }
    else if(value == 8)
    {
        cout << "organization, business, commerce, new beginnings" << endl;
    }
    else if(value == 9)
    {
        cout << "romantic, rebellious, determined, passionate, compassionate" << endl;
    }
    else if(value == 11)
    {
        cout << "idealism, visionary, inspirational" << endl;
    }
    else if(value == 12)
    {
        cout << "perfectionist, discriminating" << endl;
    }
    else if(value == 22)
    {
        cout << "builder, leader, humanitarian, practical, honest" << endl;
    }
    else
    {
        cout << value << endl;
    }
    cout << endl;
}

