#include <iostream>
#include "stack.h"
#include "infix_to_postfix.h"
#include "calculate.h"

using namespace std;

int main()
{
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);
    expression = infix_to_postfix(expression);
    cout << "Postfix expression: " << expression << endl;
    map Map = input_gen(expression);
    cout << "Ans: " << solve(expression, Map) << endl;

    return 0;
}