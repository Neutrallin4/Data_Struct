#pragma once
#include <iostream>
#include "stack.h"
#include "validate.h"

using namespace std;

string initial_cleaning(string);
bool is_operator(char);
int settler(int, int, int);
string trig_map(string);
int operator_mapper(char);
bool precedence(char, char);
bool is_digit(char input) { return (input > 47 && input < 58);}
string infix_to_postfix(string);

// Convert all negative signs into '_' and remove spaces from the expression
string initial_cleaning(string input)
{
    // Iterate through the expression
    for (int i = 0; i < input.length(); i++)
    {
        // Convert negative to '-'
        if (input[i] == '-')
        {
            if (i == 0 || is_operator(input[i - 1]) || input[i - 1] == '(' || input[i + 1] == '(')
                input[i] = '_';
        }
        // Remove spaces
        if (input[i] == ' ')
        {
            input.replace(i, 1, "");
            i--;
        }
    }
    return input;
}

// Returns true if op is an operator
bool is_operator(char op)
{
    int iop = int(op);
    return (((iop > 41 && iop < 46) || (iop > 46 && iop < 48) || iop == 33 || iop == 35 || iop == 94 || iop == 95) ? true : false);
}

// Validator function that returns a or b if either are in range of 0 to len
int settler(int a, int b, int len)
{
    if (a < 0 || a >= len)
        return a;
    if (b < 0 || b >= len)
        return b;
    return -1;
}

// Helper function that converts all 'sin' to # and all 'cos' to ','
string trig_map(string input)
{
    // If 'sin' is found replace it
    int locator = input.find("sin");
    while(locator > -1 && locator < input.length())
    {
        input.replace(locator, 3, "#");
        locator = input.find("sin");
    }
    // If 'cos' is found replace it
    locator = input.find("cos");
    while(locator > -1 && locator < input.length())
    {
        input.replace(locator, 3, ",");
        locator = input.find("cos");
    }

    return input;
}

// Maps all the operators into their relative numeric precesence value
int operator_mapper(char op)
{
    switch (op)
    {
    case '(':
        return 7;
    case ',':
    case '#':
        return 6;
    case '!':
        return 5;
    case '^':
        return 4;
    case '_':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }
    return 0;
}

// Returns the precedence of op1 ralative to op2
bool precedence(char op1, char op2)
{
    int iop1 = operator_mapper(op1), iop2 = operator_mapper(op2);

    // Return True for two power operator together because '^' is a right side operator
    if (op1 == op2)
        if (op1 == '^')
            return true;
    // Push '(' on everything
    if (op2 == '(')
        return true;

    return iop1 > iop2;
}

// Converts an infix expression into postfix
string infix_to_postfix(string infix)
{
    // If the braces are invalid then exit the code
    if (!brace_validator(infix))
    {
        cout << "Invalid bracing." << endl;
        exit(1);
    }
    // Remove the spaces, convert '-' to '_' , map trigonometric functions, fix braces
    infix = initial_cleaning(infix);
    infix = convert_to_parenthesis(infix);
    infix = trig_map(infix);
    // Wrap the expression in parenthesis in order to flush the stack at the end of the expression
    infix = "(" + infix;
    infix += ")";

    cout << "Infix expression: " << infix << endl;

    string postfix = "";
    Stack<char, 50> operator_stack;
    
    // Iterate the expression
    for (int i = 0; i < infix.length(); i++)
    {
        // If it is an operand, add it to the string
        if (!is_operator(infix[i]) && infix[i] != '(' && infix[i] != ')')
        {
            // buff is used to help store operands and numbers that are longer than one char
            string buff = "";
            int count = i;
            do
            {
                buff += infix[count++];
            }
            while (!is_operator(infix[count]) && infix[count] != '(' && infix[count] != ')');

            postfix += buff;
            i = count - 1;      // Skip the chars that were added

            postfix += " ";     // Add a space to account for values longer than 1 char
        }
        else
        {
            // If its a ')' pop until you reach a '('
            if (infix[i] == ')')
            {
                while (!operator_stack.is_empty() && operator_stack.peek() != '(')
                {
                    postfix += operator_stack.pop();
                    postfix += " ";
                }
                operator_stack.pop();       // Pop the remaining '('
            }
            // If its an operator
            else
            {
                // If the precedence of the operator compared to the stack top is false then pop until it is true or stack is empty
                while (!operator_stack.is_empty() && !precedence(infix[i], operator_stack.peek()))
                {
                    postfix += operator_stack.pop();
                    postfix += " ";     // Add a space to account for values longer than 1 char
                }
                // Add the operator to the stack
                operator_stack.push(infix[i]);
            }
        }
        
    }

    return postfix;
}