/**
 * @file parser.h
 * Header File for Parser
 * @date January 2014
 * @author Sai Koppula
 */


#ifndef _PARSER_H
#define _PARSER_H

#include <map>
#include <string>
//#include <iostream>
//#include <fstream>
using namespace std;

    // Initialize Parser
    int init_parser(string src);

    // Preprocess Comments
    void pp_comments();

    // First Pass
    void create_symbol_table();

    // Second Pass
    void create_object_file();

#endif