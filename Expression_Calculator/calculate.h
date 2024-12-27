#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "infix_to_postfix.h"

using namespace std;

// Returns true if the provided string is a number
bool is_numeric(string input)
{
    // dot stores the number of '.' in the input
    int dot = 0;

    for (int i = 0; i < input.length(); i++)
    {
        // If you found a '.' add 1 to dot
        if (input[i] == '.')
            dot++;
        // If input[i] is not digit or '.' then invalid input
        else
            if (!is_digit(input[i]))
                return false;
    }
    // If more than one dot then invalid input
    if (dot > 1)
        return false;

    return true;
}

// Converts a string into float assuming that str is numeric
float convert_to_float(string str)
{
    std::stringstream ss(str);
    float value;
    ss >> value;
    return value;
}

// Create a custom structure that stores keys and values for the variables
struct map_struct
{
    string key;
    float value;
};

// Create a map class that is used to store the values of the variables
class map
{
private:
    map_struct values[50];
    int top = 0;

public:
    // Check if the provided input exists
    bool exists(string input)
    {
        bool find = 0;
        for (int i = 0; i < 50; i++)
            if (values[i].key == input)
                find = 1;
        return find;
    }

    // Adds a value to the array
    bool add(string var, float val)
    {
        if (exists(var))
            return false;
        values[top].key = var;
        values[top].value = val;
        top++;
        return true;
    }

    // Get a value from the array
    float get_value(string var)
    {
        // For this special case, if the input is a digit, return its own numeric form
        if (is_numeric(var))
        {
            return convert_to_float(var);
        }
        else
        {
            for (int i = 0; i < top; i++)
            {
                if (values[i].key == var)
                    return values[i].value;
            }
            return 0;
        }
    }

    // Get a key from the array
    string get_key(float val)
    {
        for (int i = 0; i < top; i++)
        {
            if (values[i].value == val)
                return values[i].key;
        }
        return 0;
    }
};

map input_gen(string);
float solve(string, map);
float factorial(float);

// Returns the factorial of a number. Only workd with int. Returns float to be stored in floating stack
float factorial(float n)
{
    if (n < 0)
    {
        cout << "Factorial of " << n << " is invalid" << endl;
        exit(1);
    }
    
    return tgamma(n + 1);
}

// Takes the expression and returns an object of the Map class that contains the variables and their values
map input_gen(string expression)
{
    map Map;
    float temp = 0;
    for (int i = 0; i < expression.length(); i++)
    {
        // If it is an operand:
        if (!is_operator(expression[i]) && expression[i] != ' ')
        {
            // buff helps store operands longer than one char
            string buff = "";
            int count = i;
            do
            {
                buff += expression[count++];
            }
            while (!is_operator(expression[count]) && expression[count] != ' ');
            i = count - 1;

            // If it is numeric do nothing. map.get_value() takes care of it
            if (is_numeric(buff));
            // Else input the value of the variable and store it in a map
            else if (!Map.exists(buff))
            {
                cout << "Enter " << buff << ": ";
                cin >> temp;
                Map.add(buff, temp);
            }
        }
    }

    return Map;
}

// Takes the postfix expression along with the Map object and returns the answer
float solve(string expression, map inputs)
{
    Stack<float, 50> operands;

    for (int i = 0; i < expression.length(); i++)
    {
        // If it is not an operator, add its value to the stack
        if (!is_operator(expression[i]) && expression[i] != ' ')
        {
            string buff = "";
            int count = i;
            do
            {
                buff += expression[count++];
            }
            while (!is_operator(expression[count]) && expression[count] != ' ');
            i = count - 1;
            operands.push(inputs.get_value(buff));
        }
        // If its an operator, operate
        else
        {
            float temp;
            switch (expression[i])
            {
            case '_':
                operands.push(-operands.pop());
                break;
            case '+':
                operands.push(operands.pop() + operands.pop());
                break;
            case '-':
                operands.push(-(operands.pop() - operands.pop()));
                break;
            case '*':
                operands.push(operands.pop() * operands.pop());
                break;
            case '/':
                temp = operands.pop();
                operands.push(operands.pop() / temp);
                break;
            case '^':
                temp = operands.pop();
                operands.push(pow(operands.pop() , temp));
                break;
            case '!':
                operands.push(factorial(operands.pop()));
                break;
            case '#':
                operands.push(sin(operands.pop() * M_PI / 180));
                break;
            case ',':
                operands.push(cos(operands.pop() * M_PI / 180));
                break;
            }
        }
    }

    return operands.pop();
}