/***********************************************************
 CSCI 241 - Assignment 1 - Fall 2016
 
 Progammer: Shaniel O. Rivas
 Z-ID: z1123907
 Section: 3
 TA: Karthik Kondagalla
 Date Due: September 8, 2016
 
 Purpose: Create a the Numerology Program using c class style strings
 ************************************************************/

#include <iostream>
#include <sstream>
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
void convertString();
int totalSum();
bool checkValue(int);
void outString(int);

//global variables
string str = "";
int *out = new int[256];
int size = 0;

int main()
{
    
    cout << std::setiosflags(ios::fixed);                       //Setting the IOS flag for the entire  program.
    bool contest = true;
    
    cout << "Numerology Program " << endl;
    cout << "Let's Begin " << endl << endl;
    
    while(contest)
    {
        getString();
        convertString();
        bool contest2 = false;
        
        while(!contest2)
        {
            str = "";
            ostringstream s;
            int check = totalSum();
            s << check;
            str = s.str();
            
            convertString();
            
            contest2 = checkValue(totalSum());
        }
        
        outString(totalSum());
        
        contest = false;
        cout << "Another? (y/n)";
        char response;
        cin >> response;
        cin.ignore(1000, '\n');
        cin.clear();
        
        if((response == 'y') || (response == 'Y'))                  //Asking user if wants to try again
        {
            contest = true;
        }
        cout << endl;
        
    }
    
    return 0;
}

/******************************************************
Getting inputs from user and clear previous inputs
******************************************************/
void getString()
{
    str = "";
    cout << "Enter a name: ";
    cin.clear();
    cin.sync();
    getline(cin, str);
}

/******************************************************
Convert all strings into proper numerical values
******************************************************/
void convertString()
{
    delete[] out;
    out = new int[256];
    size = str.length();
    for(int i = 0; i < size; i++)
    {
        out[i] = 0;
        if(isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
            out[i] = str[i] - 96;
        }
        else if(isdigit(str[i]))
        {
            out[i] = str[i] - 48;
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
void outString(int val)
{
    cout << "That name has the traits ";
    if(val == 0)
    {
        cout << "emptiness, nothingness, blank" << endl;
    }
    else if(val == 1)
    {
        cout << "independence, loneliness, creativity, originality, dominance, leadership, impatience" <<endl;
    }
    else if(val == 2)
    {
        cout << "quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient" << endl;
    }
    else if(val == 3)
    {
        cout << "charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud" << endl;
    }
    else if(val == 4)
    {
        cout << "harmony, truth, justice, order discipline, practicality" << endl;
    }
    else if(val == 5)
    {
        cout << "new directions, excitement, change, adventure" << endl;
    }
    else if(val == 6)
    {
        cout << "love, harmony, perfection, marriage, tolerance, public service" << endl;
    }
    else if(val == 7)
    {
        cout << "spirituality, completeness, isolation, introspection" << endl;
    }
    else if(val == 8)
    {
        cout << "organization, business, commerce, new beginnings" << endl;
    }
    else if(val == 9)
    {
        cout << "romantic, rebellious, determined, passionate, compassionate" << endl;
    }
    else if(val == 11)
    {
        cout << "idealism, visionary, inspirational" << endl;
    }
    else if(val == 12)
    {
        cout << "perfectionist, discriminating" << endl;
    }
    else if(val == 22)
    {
        cout << "builder, leader, humanitarian, practical, honest" << endl;
    }
    else
    {
        cout << val << endl;
    }
    cout << endl;
}
