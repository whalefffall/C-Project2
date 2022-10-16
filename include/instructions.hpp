// implements most instructions for the calculator.
#pragma once
#include <iostream>
#include <map>
#include "functions.hpp"
#include <stack>
#include "status.hpp"
#include <stdio.h>
#include <string>
#include <string.h>
#include <regex>
// use macro to store some tip
#define _invalid_command_line_arguments "Please do not input arguments as command line arguments!\n"
#define _start "Project 2: a better calculator start!\nAuthor SID:12011124 \nName: Feng Baijun\n"
#define CLEAR "clear"
#define GUIDE "Instructions for the calculator.\n\
Input the correct expression the the calculator will output the result.\n\
Variables(only consists of lower-case English alphbets) are supported.\n\
  command                 explaination\n\
    quit              quit the calculator\n\
    list              list all variables\n\
    clear             clear all variables\n\
instructions          print instructions\n\
  functions           print functions supported by this calculator\n"
#define INSTRUCTIONS "instructions"
#define LIST "list"
#define QUIT "quit"
using namespace std;

// check whether to clear all stroed variables
bool check_clear(string input);

// check whether the input is a command
bool check_command(string input);

// check whether there are invalid command line arguments
void check_command_line_arguments(int argc);

// check whether to display supported functions
bool check_functions(string input);

// check whether to display the instructions
bool check_instructions(string input);

// check whether to list all variables
bool check_list(string input);

// check whether to quit
bool check_quit(string input);

// compute the result from postfix expression
bool compute(string &postfix, stack<long double> val);

// get the postfix expression from the normal one
bool get_postfix(string &input, string &to, stack<char> opt);

// handle the expression
int get_status(string input, bool print);

// get priority level for the operator
int level(char opt);

// display the instructions
void print_instructions();

// display the project information
void print_start();



