/**
 * @file main.cpp
 * Executes program
 * @date January 2014
 * @author Sai Koppula
 */


#include "parser.h"
#include "lib.h"
#include <iostream>
#include <fstream>

using namespace std;

#define TESTFUNC 1

#if TESTFUNC == 0
int main(int argc, char* argv[])
{

	
    coutc("blue","Program Beginning");
    if (argc < 2)
    {
        coutc("red", "No input file");
        coutc("red", "Terminating Program");
        return 0;
    }
    if (init_parser(argv[1]) == -1)
    {
        coutc("red", "Terminating Program");
        return 0;
    }
    pp_comments();
    create_symbol_table();
    create_object_file();
    //test << "Hello World" << endl;
	
    return 0;
    
}
#endif

#if TESTFUNC == 1
int main(int argc, char* argv[])
{
	
    cout << "Hello World" << endl;
	vector<string> words;
	string test = "Hi my name is Sai";
	words = getWords(test);
	print(words);
    return 0;
    
}
#endif
