// C++ project2: a better calculator by Feng Baijun, SID:12011124
#include <map>
#include <iostream>
#include <string>

#include "../include/instructions.hpp"

using namespace std;

string &replace_all(string& str, const string &old_value, const string &new_value);
void trim(string &s);


int main(int argc, char * argv[]) {

    // check number of command line arguments
    check_command_line_arguments(argc);

    // print start tip
    print_start();

    // print instructions to the calculator
    print_instructions();

    while(1)
    {
        char in[1000+5];
        
        cin.getline(in, 1000);
        string input = in;
        // erase all blanks
        trim(input);

        // handle negative notation starts 
        if (input[0] == '-') { input = '0' + input;}
        
        // handle negative notation starts after left parenthesis
        input = replace_all(input, "(-", "(0-");

        // quit 
        if (check_quit(input)) { return 0;}

        // other command
        if (check_command(input)) { continue;}
        
        // handle the expression
        get_status(input, 1);
    }
}

string &replace_all(string& str, const string &old_value, const string &new_value)     
{     
    for(string::size_type pos(0); pos!=string::npos; pos+=new_value.length())  
    {     
        if((pos=str.find(old_value,pos)) != string::npos )     
        { 
            str.replace(pos,old_value.length(),new_value);  
        } else{ break; }       
    }
    return str;
} 

void trim(string &s)
{
	int index = 0;
	if(!s.empty())
	{
		while( (index = s.find(' ',index)) != string::npos)
		{
			s.erase(index,1);
		}
	}
}
