/**
 * @file parser.cpp
 * Support File for Parser
 * @date January 2014
 * @author Sai Koppula
 */

#include "parser.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 * init_parser
 *   DESCRIPTION: Any Intializing of Parser included here.
 *   INPUTS: none
 *   OUTPUTS: none
 *   RETURN VALUE: none
 *   SIDE EFFECTS: none
 */
void init_parser()
{
 
    cout << "Parser Initialized" << endl;
    
}

/*
 * pp_comments
 *   DESCRIPTION: Removes any comments from source file,
 *                and stores comment free code in local temp file.
 *   INPUTS: file - file descriptor for source file
 *   OUTPUTS: none
 *   RETURN VALUE: none
 *   SIDE EFFECTS: Saves comment free code file in working directory
 */
void pp_comments()
{
    cout << "Parser PPing Comments" << endl;
}

/*
 * create_symbol_table
 *   DESCRIPTION: Creates symbol table for source file
 *   INPUTS: file - file descriptor of source file
 *   OUTPUTS: none
 *   RETURN VALUE: none
 *   SIDE EFFECTS: Populates hashmap symbol_table with data
 */
void create_symbol_table()
{
    cout << "Generating Symbol Table" << endl;
}

/*
 * create_object_file
 *   DESCRIPTION: Creates machine code file
 *   INPUTS: file - file descriptor of source code
 *   OUTPUTS: none
 *   RETURN VALUE: none
 *   SIDE EFFECTS: Saves machine code in working directory
 */
void create_object_file()
{
    cout << "Creating Machine Code File" << endl;
}




