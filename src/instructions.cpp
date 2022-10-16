#include "../include/instructions.hpp"

using namespace std;
map <string, long double> variable_dict;
long double result;
const char opt_set[12] = "+-*/()=|&^";

void check_command_line_arguments(int argc)
{
    if (argc > 1) { printf(_invalid_command_line_arguments);}    
}

bool check_command(string input)
{
    return check_clear(input) | check_instructions(input) | check_functions(input) | check_list(input); 
}

bool check_functions(string input)
{
    if (input.compare("functions") == 0)
    {
        printf("Functions\nabs(x)      the absolute value of c\nsquare(x)   the square of x\nsqrt(x)     the square root of x.\n");
        return 1;
    }
    return 0;
}

bool check_clear(string input)
{
    if (input.compare(CLEAR) == 0)
    {
        variable_dict.clear();
        return 1;
    }
    return 0;
}
 
bool check_list(string input)
{
    if (input.compare(LIST) == 0)
    {
        // printf("yes\n");
        map<string, long double>::iterator iter;
        for (iter = variable_dict.begin(); iter != variable_dict.end(); iter++)
        {
            printf("%s=%Lf\n", iter->first.c_str(), iter->second);
        }
        return 1;
    }
    return 0;
}

bool check_instructions(string input)
{
    if (input.compare(INSTRUCTIONS) == 0)
    {
        print_instructions();
        return 1;
    }
    return 0;
}

bool check_quit(string input)
{
    if (input.compare(QUIT) == 0)
    {
        printf("Quit!\n");
        return 1;
    }
    return 0;
}

int get_status(string input, bool print)
{
    // cout<<input<<endl;
    // printf("0\n");
    regex assign("([a-z]+)=([\\S]+)");
    regex variable("([a-z]+)");
    regex digit_int("([-+]?\\d+)");
    regex digit_float("([-+]?\\d+\\.\\d+)");
    regex valid_expression("[a-z0-9\\+\\-\\*\\/\\.\\(\\)]+");
    bool isAssign = regex_match(input, assign); 
    // printf("1\n");
    if (isAssign)
    {
        smatch search;
        regex_search(input, search, assign);
        string var = search.str(1);
        // printf("%s\n", search.str(2).c_str());
        int status = get_status(search.str(2), 0);
        if (status == INVALID) { return INVALID;}
        variable_dict.insert({var, result});
        // printf("inserted!\n");
        return ASSIGN;
    }

    bool isValid =  regex_match(input, valid_expression);
    if (!isValid) 
    {
        cout<<"Invalid expression!\n";
        return INVALID;
    }

    bool isInt = regex_match(input, digit_int);
    if (isInt)
    {
        smatch search;
        regex_search(input, search, digit_int);
        // cout<<search.str(1)<<endl;
        result = stold(search.str(1));
        return EXPRESSION;
    }

    bool isFloat = regex_match(input, digit_float);
    if (isFloat)
    {
        smatch search;
        regex_search(input, search, digit_float);
        // cout<<"2:"<<search.str(1)<<endl;
        result = stold(search.str(1));
        return EXPRESSION;
    }

    
    

    stack<char> opt;
    stack<long double> val;
    string postfix;
    if (!get_postfix(input, postfix, opt)) { return INVALID;}
    if (!compute(postfix, val)) { return INVALID;}
    if (print)
    {
        cout<<result<<endl;
    }
    
    return EXPRESSION;
    

}

void print_instructions()
{
    printf(GUIDE);
}

void print_start()
{
    printf(_start);
}



bool get_postfix(string &input, string &to, stack<char> opt)
{
    long double theNum = 0;
    int hasDot = 0;
    bool inNum = 0;
    bool inVar = 0;
    size_t start = 0;
    char c;
    string temp = "";
    for (size_t i = 0; i < input.length(); i++)
    {
        c = input[i];
        if ('0' <= c && c <= '9' || c == '.')
        {
            
            if (!inNum)
            {
                start = i;
                inNum = 1; 
            }

            if (i == input.length()-1)
            {
                // cout<<"1.5:"<<input.substr(start)<<endl;
                theNum = stold(input.substr(start));
                to += to_string(theNum) + ' ';
            }
            
            if (c == '.')
            {
                if (hasDot) return INVALID;
                hasDot = 1;
            }
            
        } else if ('a' <= c && c <= 'z')
        {
            if (!inVar)
            {
                if (input.length() - i >= 9 && strcmp(input.substr(i, 7).c_str(),"square(") == 0)
                {
                    c = '^';
                    while(true){
                        if(opt.empty() || opt.top() == '(')
                            opt.push(c);
                        else if(level(c) > level(opt.top()))
                            opt.push(c);
                        else{
                            to += opt.top();
                            to += ' ';
                            opt.pop();
                            continue;
                        }
                        break;
                    }
                    i = i+5; 
                    continue;
                }
                if (input.length() - i >= 7 && strcmp(input.substr(i, 5).c_str(),"sqrt(") == 0)
                {
                    
                    
                    c = '&';
                    while(true){
                        if(opt.empty() || opt.top() == '(')
                            opt.push(c);
                        else if(level(c) > level(opt.top()))
                            opt.push(c);
                        else{
                            to += opt.top();
                            to += ' ';
                            opt.pop();
                            continue;
                        }
                        break;
                    }
                    i = i+3; 
                    continue;
                }
                if (input.length() - i >= 6 && strcmp(input.substr(i, 4).c_str(),"abs(") == 0)
                {
                    c = '|';
                    while(true){
                        if(opt.empty() || opt.top() == '(')
                            opt.push(c);
                        else if(level(c) > level(opt.top()))
                            opt.push(c);
                        else{
                            to += opt.top();
                            to += ' ';
                            opt.pop();
                            continue;
                        }
                        break;
                    }
                    i = i+2; 
                    continue;
                }
                temp.clear();
                inVar = 1;
                
                
            }
            temp += c;
            if (i == input.length()-1)
            {
                theNum = variable_dict[temp];
                to += to_string(theNum) + ' ';
            }
            
        } else {
            
            if (inNum)
            {
                // cout<<"3:"<<input.substr(start, i - start)<<endl;
                theNum = stold(input.substr(start, i - start));
                to += to_string(theNum) + ' ';
            }
            if (inVar)
            {
                if (variable_dict.count(temp) == 0) { return INVALID;}
                theNum = variable_dict[temp];
                to += to_string(theNum) + ' ';
            }
            if (c == '(') { 
                opt.push(c);
            }
            else if (c == ')')
            {
                while(!opt.empty() && opt.top() != '('){
                    to += opt.top();
                    to += ' ';
                    opt.pop();
                }
                opt.pop();
            } else {
                while(true){
                    if(opt.empty() || opt.top() == '(')
                        opt.push(c);
                    else if(level(c) > level(opt.top()))
                        opt.push(c);
                    else{
                        to += opt.top();
                        to += ' ';
                        opt.pop();
                        continue;
                    }
                    break;
                }
            
            }
            inNum = 0;
            inVar = 0;
        }

        
    }
    while(!opt.empty())
    {
        to += opt.top();
        to += ' ';
        opt.pop();
    }
    return true;

}

bool compute(string &postfix, stack<long double> val)
{
    // cout<<postfix<<endl;
    long double theNum = 0;
    int hasDot = 0;
    bool inNum = 0;
    bool inVar = 0;
    size_t start = 0;
    char c;
    string temp = "";
    for (size_t i = 0; i < postfix.length(); i++)
    {
        c = postfix[i];
        if ('0' <= c && c <= '9' || c == '.')
        {
            if (!inNum)
            {
                start = i;
                inNum = 1; 
            }
            
        }
        else{
            // cout<<"4:"<<postfix.substr(start, i-start)<<endl;
            if(inNum == 1){ val.push(stold(postfix.substr(start, i-start)));}
            inNum = 0;
            long double x, y;
            if(c != ' '){
                x = val.top();
                val.pop();
                if (c == '^') { val.push(square(x));continue;}
                if (c == '&') { 
                    if (x < 0)
                    {
                        cout<<"The base of square root should be non-negtive!"<<endl;
                        return INVALID;
                    }
                    
                    val.push(sqrt(x));continue;
                }
                if (c == '|') { 
                    val.push(abs(x));continue;
                }
                y = val.top();
                val.pop();
                if (c == '+') { val.push(y+x);}
                if (c == '-') { val.push(y-x);}
                if (c == '*') { val.push(y*x);}
                if (c == '/') { val.push(y/x);}
            }
            
        }
    }
    result = val.top();
    // cout<<result<<endl;
    return true;
}

int level(char opt)
{
    for(int i = 0; i < 12; i++){
        if(opt == opt_set[i])
            return i;
    }
    return -1;
}
