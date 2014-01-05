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
    ofstream test;
    test.open(argv[1]);
    init_parser();
    pp_comments();
    create_symbol_table();
    create_object_file();
    test << "Hello World" << endl;
    test.close();
    return 0;
    
}