/**
 * @file lib.h
 * Header File for Standard Libraries
 * @date January 2014
 * @author Sai Koppula
 */


#ifndef _LIB_H
#define _LIB_H

#include <string>
#include <vector>
using namespace std;

//Custom COUT Function
void coutc(string color, string text);

//String to LowerCase
string toLower(string input);

//Turn input string into vector of words
vector<string> getWords(string input);

//Case insensitive string compare
int strcmp(string input, string key);

//Print Vector Indices and Values
void print(vector<string> words);

#endif