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
#define GRETEXT "\033[1;32m"

//Global Variables

void coutc(string color, string text)
{
    if (strcmp(color, "red") == 0)
        cout << REDTEXT;
    else if (strcmp(color, "yellow") == 0)
        cout << YELTEXT;
    else if (strcmp(color, "blue") == 0)
        cout << BLUTEXT;
    else if (strcmp(color, "green") == 0)
        cout << GRETEXT;
    else cout << DEFTEXT;
    
    cout << text << DEFTEXT << endl;
    
}

//String to LowerCase
string toLower(string input)
{
	for(int i = 0; i < input.length(); i++)
		input[i] = tolower(input[i]);
	return input;
}

//Case insensitive string compare
int strcmp(string input, string key)
{
	return toLower(key).compare(toLower(input));
	
}