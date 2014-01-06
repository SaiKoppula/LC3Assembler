/**
 * @file parser.cpp
 * Support File for Parser
 * @date January 2014
 * @author Sai Koppula
 */

#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Local Variables
map<string, int> symbol_table;
string sourcefile;
string pp_sourcefile;

/*
 * init_parser
 *   DESCRIPTION: Any Intializing of Parser included here.
 *   INPUTS: none
 *   OUTPUTS: none
 *   RETURN VALUE: none
 *   SIDE EFFECTS: none
 */
int init_parser(string src)
{
    int length = src.length();
    if (length < 4 || src[length -4] != '.' || src[length -3] != 'a' || src[length -2] != 's' || src[length -1] != 'm')
    {
        cout << "Not a valid .asm file" << endl;
        return -1;
    }
    
    sourcefile = src;
    pp_sourcefile = "temp.asm";
    
    cout << "Source File: " << sourcefile << endl;
    cout << "Preprocessed Storage: " << pp_sourcefile << endl;
    
    cout << "Parser Initialized" << endl;
    return 0;
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
   
    ifstream input;
    ofstream output;
    string buf;
    input.open(sourcefile);
    output.open(pp_sourcefile);
    
    if(input.is_open())
    {
        while(getline(input,buf))
        {
            for(int i = 0; i < buf.length(); i++)
            {
                //cout << "In LOOP: " << buf << endl;
                if(buf[i] == ';') break;
                output << buf[i];
            }
            if (buf.length()>0 &&buf[0] != ';' && buf[0] != '\n') output << endl;
        }
        
    }
    input.close();
    output.close();
    
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




