/**
 * @file main.cpp
 * Executes program
 * @date January 2014
 * @author Sai Koppula
 */


#include "parser.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{

    cout << "Program Beginning" << endl;
    if (argc < 2)
    {
        cout << "No input file" << endl;
        cout << "Terminating Program" << endl;
        return 0;
    }
    if (init_parser(argv[1]) == -1)
    {
        cout << "Terminating Program" << endl;
        return 0;
    }
    pp_comments();
    create_symbol_table();
    create_object_file();
    //test << "Hello World" << endl;
   
    return 0;
    
}