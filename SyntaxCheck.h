#pragma once

#include<iostream>
#include<string>
#include "Stack.h"
using namespace std;
#define MAX 100

//it has functions to check keywords and parentheses
class SyntaxCheck
{
public:
    //it checks if the content are brackets
    static bool are_brackets(const string& expression)
    {
        for (char i : expression) {
            if (i == '{' || i == '}'
                || i == ')' || i == '(')
                return true;
        }
        return false;
    }
    //it compares the keywords 
    static bool keywords(string data[], int size)
    {
        if (data[0] != "Begin")
        {
            cout << "begin NOT found!" << endl;
            exit(0);
        }
      

        string keywords[MAX];
        int keyword_size = 0;
        for (int i = 0; i < size; i++)
        {       
            if (data[i].find("Begin") != std::string::npos)
                keywords[keyword_size++] = "Begin";
            if ((data[i].find("if") != std::string::npos)
                && data[i].find("endif") == std::string::npos
                && data[i].find("elseif") == std::string::npos)
            {
                keywords[keyword_size++] = "if";
            }
            if ((data[i].find("else") != std::string::npos)
                && data[i].find("elseif") == std::string::npos) {
                keywords[keyword_size++] = "else";
            }
            if ((data[i].find("elseif") != std::string::npos))
                keywords[keyword_size++] = "elseif";
            if ((data[i].find("while") != std::string::npos)
                && data[i].find("endwhile") == std::string::npos) {
                keywords[keyword_size++] = "while";
            }
            if ((data[i].find("for") != std::string::npos)
                && data[i].find("endfor") == std::string::npos) {
                keywords[keyword_size++] = "for";
            }
            if (data[i].find("endif") != std::string::npos)
                keywords[keyword_size++] = "endif";
            if (data[i].find("endfor") != std::string::npos)
                keywords[keyword_size++] = "endfor";
            if (data[i].find("endwhile") != std::string::npos)
                keywords[keyword_size++] = "endwhile";
            if
                (
                    (data[i].find("end") != std::string::npos)
                    && data[i].find("endfor") == std::string::npos
                    && data[i].find("endwhile") == std::string::npos
                    && data[i].find("endif") == std::string::npos
                    )
            {
                keywords[keyword_size++] = "end";
            }
        }
        Stack s;
        string temp;

        int else_ifs = 1;

        for (int i = 0; i < keyword_size; i++) {
            if (keywords[i] == "Begin"
                || keywords[i] == "if"
                || keywords[i] == "elseif"
                || keywords[i] == "else"
                || keywords[i] == "for"
                || keywords[i] == "while")
            {
                if (keywords[i] == "else" || keywords[i] == "elseif")
                    else_ifs++;
                s.push(keywords[i]);
                continue;
            }

            if (s.empty())
                return false;

            if (keywords[i] == "endif") {
                for (int i = 0; i < else_ifs; i++) {
                    temp = s.Top();
                    s.pop();
                    if (temp == "for" || temp == "while" || temp == "Begin") {
                        cout << "Invalid if/endif declaration" << endl;;
                        exit(0);
                    }
                }
            }
            else if (keywords[i] == "endwhile") {
                temp = s.Top();
                s.pop();
                if (temp != "while") {
                    cout << "endwhile found but while was not!" << endl;
                    exit(0);
                }
            }
            else if (keywords[i] == "endfor") {
                temp = s.Top();
                s.pop();
                if (temp != "for") {
                    cout << "endfor found but for was not!" << endl;
                    exit(0);
                }
            }
            else if (keywords[i] == "end") {
                if (i != keyword_size - 1) {
                    cout << "Multiple end statements found!" << endl;
                    exit(0);
                }
                else if (s.Top() == "Begin")
                    s.pop();
            }
        }
        return s.empty();
    }
    //it checks the brackets
    static bool check_brackets(string* data, int size) {
        string expr = "";
        // Get all the brackets in the entire string array.
        for (int i = 0; i < size; i++)
        {
            string f = data[i];
            for (char j : f) {
                if (j == '(')
                    expr += '(';
                else if (j == ')')
                    expr += ')';
                else if (j == '{')
                    expr += '{';
                else if (j == '}')
                    expr += '}';
                else if (j == '[')
                    expr += '[';
                else if (j == ']')
                    expr += ']';
            }
        }

        // Verifying the brackets
        Stack s;
        string parse;
        char popped;
        for (char i : expr)
        {
            if (i == '(' || i == '[' || i == '{') {
                parse = i;
                s.push(parse);
                continue;
            }
            if (s.empty())
                return false;
            switch (i) {
            case ')':
                popped = s.Top()[0];
                s.pop();
                if (popped == '{' || popped == '[')
                    return false;
                break;
            case '}':
                popped = s.Top()[0];
                s.pop();
                if (popped == '(' || popped == '[')
                    return false;
                break;
            case ']':
                popped = s.Top()[0];
                s.pop();
                if (popped == '(' || popped == '{')
                    return false;
                break;
            }
           

        }

        return s.empty();
    }
    static bool substring(const string& toCheck, const string& subString)
    {
        return toCheck.find(subString) != std::string::npos;
    }
};
