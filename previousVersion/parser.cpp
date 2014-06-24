/**
 * @file parser.cpp
 * Support File for Parser
 * @date January 2014
 * @author Sai Koppula
 */

#include "parser.h"
#include "lib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//Global Variables
map<string, int> symbol_table;
string sourcefile;
string pp_sourcefile;
string st_file;
vector<string> OPCODES;
int start_addr;

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
        coutc("red","Not a valid .asm file");
        return -1;
    }
    
    sourcefile = src;
    pp_sourcefile = "temp.asm";
    st_file = "temp.sym";
    
    coutc("green","Source File: "+sourcefile);
    coutc("green", "Preprocessed Storage: "+pp_sourcefile);
    
    OPCODES.push_back("add");
    OPCODES.push_back("and");
    OPCODES.push_back("br");
    OPCODES.push_back("jmp");
    OPCODES.push_back("jsr");
    OPCODES.push_back("jsrr");
    OPCODES.push_back("ld");
    OPCODES.push_back("ldi");
    OPCODES.push_back("ldr");
    OPCODES.push_back("lea");
    OPCODES.push_back("not");
    OPCODES.push_back("ret");
    OPCODES.push_back("rti");
    OPCODES.push_back("st");
    OPCODES.push_back("sti");
    OPCODES.push_back("str");
    OPCODES.push_back("trap");
    OPCODES.push_back(".end");
    OPCODES.push_back("halt");
    OPCODES.push_back("puts");
	
    OPCODES.push_back("brn");
    OPCODES.push_back("brnz");
    OPCODES.push_back("brnp");
    OPCODES.push_back("brnzp");
	
    OPCODES.push_back("brz");
    OPCODES.push_back("brzp");
    OPCODES.push_back("brp");
	
	
	
    coutc("blue","Parser Initialized");
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
    
    coutc("blue","Parser PPing Comments");
   
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
int create_symbol_table()
{
    coutc("blue","Generating Symbol Table");
	
    ifstream input;
    ofstream output;
    string buf;
    string temp;
    vector<string> words;
    input.open(pp_sourcefile);
    output.open(st_file);
    
    if(getline(input,buf))
    {
	words = getWords(buf);
	if (strcmp(words[0], ".orig") != 0)
	{
	    coutc("red", ".ORIG operative does not exist");
    	    return -1;
	}
	else
	{
    	    if(words[1].length() != 5) //CRITICAL: Add check for "x"
	    {
		coutc("red", "Invalid starting address");
		return -1;
	    }
		words[1].erase(0,1);
		stringstream ss;
		ss << hex << words[1];
		ss >> start_addr;
		cout << "Start Address " << hex << start_addr << endl;
	}
		//print(words);	
    }
    int curr_addr = start_addr;
    if(input.is_open())
    {
        while(getline(input,buf))
        {
            words = getWords(buf);
	    if(isOpCode(words[0]) != 0)
	    {
		cout << curr_addr << endl;
		symbol_table[words[0]] = curr_addr;
		if(words.size() == 1) curr_addr--;
		else if(strcmp(".blkw", words[1]) == 0) curr_addr--;
	    }
	    if(words.size()>0 )
	    {	
		curr_addr++;
	    }		
	    print(words);
        }        
    }
	
    output << hex << "++++++++++++Symbol Table++++++++++++" << endl;
	
    output << "\tIndex\t\tValue\t" << endl;

    for (std::map<string,int>::iterator it=symbol_table.begin(); it!=symbol_table.end(); ++it)
	output << "\t" << it->first << "\t => \t0x" << it->second << '\n';
    output << "++++++++++++End of Table+++++++++++++" << endl;
	
    input.close();
    output.close();
    return 0;
	
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
    coutc("blue","Creating Machine Code File");
}


/*
 * isOpCode
 *   DESCRIPTION: Creates machine code file
 *   INPUTS: file - file descriptor of source code
 *   OUTPUTS: none
 *   RETURN VALUE: 0 if Opcode, else -1
 *   SIDE EFFECTS: Saves machine code in working directory
 */
int isOpCode(string test)
{
    for(int i = 0; i < OPCODES.size(); i++)
	if(strcmp(OPCODES[i], test) == 0) return 0;
    return -1;
}




