// C++ project2: a better calculator by Feng Baijun, SID:12011124
#include <map>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/instructions.hpp"

using namespace std;

void trim(string &s);
string &replace_all(string& str, const string &old_value, const string &new_value);

int main(int argc, char * argv[]) {

    // check number of command line arguments
    check_command_line_arguments(argc);

    // print start tip
    print_start();

    print_instructions();

    while(1)
    {
        char in[1000+5];
        
        cin.getline(in, 1000);
        string input = in;
        trim(input);
        input = replace_all(input, "(-", "(0-");
        if (check_quit(input)) { return 0;}
        if (check_command(input)) { continue;}
        get_status(input, 1);
    }
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