/**
 * @file lib.c
 * Support File for Custom Libraries
 * @date January 2014
 * @author Sai Koppula
 */

#include "lib.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//Global Constants
#define REDTEXT "\033[1;31m"
#define DEFTEXT "\033[0m"
#define YELTEXT "\033[1;33m"
#define BLUTEXT "\033[1;34m"
#define GRETEXT "\033[1;31m"

//Global Variables

void coutc(string color, string text)
{
    if (color.compare("red") == 0)
        cout << REDTEXT;
    else if (color.compare("yellow") == 0)
        cout << YELTEXT;
    else if (color.compare("blue") == 0)
        cout << BLUTEXT;
    else if (color.compare("green") == 0)
        cout << GRETEXT;
    else cout << DEFTEXT;
    
    cout << text << DEFTEXT << endl;
    
}