/**
 * @file lib.h
 * Header File for Standard Libraries
 * @date January 2014
 * @author Sai Koppula
 */


#ifndef _LIB_H
#define _LIB_H

#include <string>
using namespace std;

//Custom COUT Function
void coutc(string color, string text);

//String to LowerCase
string toLower(string input);

//Case insensitive string compare
int strcmp(string input, string key);

#endif