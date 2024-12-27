#include <iostream>
#include "implementation1.h"
#include "implementation2.h"
#include "implementation3.h"
#include "implementation4.h"

using namespace std;

int main()
{
    Implementation1<int, 10> test(false);
    cout << test.is_empty() << endl;
    return 0;
}