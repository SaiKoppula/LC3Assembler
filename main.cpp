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