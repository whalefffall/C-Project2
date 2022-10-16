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
#define _invalid_command_line_arguments "Please do not input arguments as command line arguments!\n"
#define _start "Project 2: a better calculator start!\n"
#define CLEAR "clear"
#define INSTRUCTIONS "instructions"
#define LIST "list"
#define GUIDE "Instructions for the calculator.\n\
Input the correct expression the the calculator will output the result.\n\
Variables(only consists of lower-case English alphbets) are supported.\n\
  command                 explaination\n\
    quit              quit the calculator\n\
    list              list all variables\n\
    clear             clear all variables\n\
instructions          print instructions\n\
  functions           print functions supported by this calculator\n"

#define QUIT "quit"
using namespace std;





bool check_command(string input);
bool check_functions(string input);
void check_command_line_arguments(int argc);
bool check_instructions(string input);
bool check_quit(string input);

bool check_clear(string input);
bool check_list(string input);
int get_status(string input, bool print);
void print_instructions();
void print_start();
int level(char opt);
bool compute(string &postfix, stack<long double> val);
bool get_postfix(string &input, string &to, stack<char> opt);



