#pragma once

#include <iostream>
#include "stack.h"

using namespace std;

bool brace_validator(string);
string convert_to_parenthesis(string);

// Checks if the braces are correctly implemented
bool brace_validator(string input)
{
    Stack<char, 50> braces;
    for (int i = 0; i < input.length(); i++)
    {
        // If its an opening brace add it to the stack
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
            braces.push(input[i]);
        else
        {
            // check if the closing braces are correctly implemented
            if (input[i] == ')')
                if (braces.pop() != '(')
                    return false;

            if (input[i] == ']')
                if (braces.pop() != '[')
                    return false;

            if (input[i] == '}')
                if (braces.pop() != '{')
                    return false;
        }
    }
    // If the stack is not empty then its incorrect
    if (!braces.is_empty())
        return false;
    // Otherwise its valid
    return true;
}

// Converts all brace forms to parenthesis
string convert_to_parenthesis(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '[')
            input[i] = '(';
        if (input[i] == ']')
            input[i] = ')';
        if (input[i] == '{')
            input[i] = '(';
        if (input[i] == '}')
            input[i] = ')';
    }
    return input;
}