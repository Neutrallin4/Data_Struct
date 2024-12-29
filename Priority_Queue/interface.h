#pragma once
#include <iostream>

#include "main_structure.h"
#include "art.h"

using namespace std;

int get_int()
{
    int temp;
    cin >> temp;
    return temp;
}

int get_float()
{
    float temp;
    cin >> temp;
    return temp;
}

double get_double()
{
    double temp;
    cin >> temp;
    return temp;
}

char get_char()
{
    char temp;
    cin >> temp;
    return temp;
}

bool get_bool()
{
    bool temp;
    cin >> temp;
    return temp;
}

bool interface();
bool menu_1();
bool menu_2();
bool menu_3();
bool menu_4();
bool menu_5();

bool interface()
{
    // Keep the program running unless commanded otherwise (or in case of a possible error)
    while (true)
    {
        art_line();
        art_priority_queue();
        art_line();
        cout << "1 - Queue type 1\n2 - Queue type 2\n3 - Queue type 3" << endl;
        cout << "4 - Queue type 4\n5 - Queue type 5\n0 - exit\n: ";
        int a;
        cin >> a;
        switch (a)
        {
        case 0:
            return 0;
        case 1:
            menu_1();
            break;
        case 2:
            menu_2();
            break;
        case 3:
            menu_3();
            break;
        case 4:
            menu_4();
            break;
        case 5:
            menu_5();
            break;
        }
    }
}

bool menu_1()
{
    art_queue_handler();
    art_line();

    bool order;
    int type, inp;

    cout << "Select the order of the queue:\n0 - descending\n1 - ascending\n: ";
    cin >> order;
    art_line();
    cout << "Select the type of the queue:\n1 - int\n2 - float\n3 - double\n4 - char\n5 - bool\n0 - exit\n: ";
    cin >> type;

    switch (type)
    {
    case 0:
        return 0;
    case 1:
    {
        Implementation1<int, 100> temp(order);

        while (true)
        {
            art_line();
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;
            art_line();

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_int());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 2:
    {
        Implementation1<float, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_float());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 3:
    {
        Implementation1<double, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_double());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 4:
    {
        Implementation1<char, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_char());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 5:
    {
        Implementation1<bool, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_bool());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }
        
        break;
    }
    }
    return 0;
}

bool menu_2()
{
    art_queue_handler();
    art_line();

    bool order;
    int type, inp;

    cout << "Select the order of the queue:\n0 - descending\n1 - ascending\n: ";
    cin >> order;
    art_line();
    cout << "Select the type of the queue:\n1 - int\n2 - float\n3 - double\n4 - char\n5 - bool\n0 - exit\n: ";
    cin >> type;

    switch (type)
    {
    case 0:
        return 0;
    case 1:
    {
        Implementation2<int, 100> temp(order);

        while (true)
        {
            art_line();
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;
            art_line();

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_int());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 2:
    {
        Implementation1<float, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_float());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 3:
    {
        Implementation1<double, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_double());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 4:
    {
        Implementation1<char, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_char());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 5:
    {
        Implementation1<bool, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_bool());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }
        
        break;
    }
    }
    return 0;
}

bool menu_3()
{
    art_queue_handler();
    art_line();

    bool order;
    int type, inp;

    cout << "Select the order of the queue:\n0 - descending\n1 - ascending\n: ";
    cin >> order;
    art_line();
    cout << "Select the type of the queue:\n1 - int\n2 - float\n3 - double\n4 - char\n5 - bool\n0 - exit\n: ";
    cin >> type;

    switch (type)
    {
    case 0:
        return 0;
    case 1:
    {
        Implementation3<int, 100> temp(order);

        while (true)
        {
            art_line();
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;
            art_line();

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_int());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 2:
    {
        Implementation1<float, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_float());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 3:
    {
        Implementation1<double, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_double());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 4:
    {
        Implementation1<char, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_char());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 5:
    {
        Implementation1<bool, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_bool());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }
        
        break;
    }
    }
    return 0;
}

bool menu_4()
{
    art_queue_handler();
    art_line();

    bool order;
    int type, inp;

    cout << "Select the order of the queue:\n0 - descending\n1 - ascending\n: ";
    cin >> order;
    art_line();
    cout << "Select the type of the queue:\n1 - int\n2 - float\n3 - double\n4 - char\n5 - bool\n0 - exit\n: ";
    cin >> type;

    switch (type)
    {
    case 0:
        return 0;
    case 1:
    {
        Implementation4<int, 100> temp(order);

        while (true)
        {
            art_line();
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;
            art_line();

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_int());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 2:
    {
        Implementation1<float, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_float());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 3:
    {
        Implementation1<double, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_double());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 4:
    {
        Implementation1<char, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_char());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 5:
    {
        Implementation1<bool, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_bool());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }
        
        break;
    }
    }
    return 0;
}

bool menu_5()
{
    art_queue_handler();
    art_line();

    bool order;
    int type, inp;

    cout << "Select the order of the queue:\n0 - descending\n1 - ascending\n: ";
    cin >> order;
    art_line();
    cout << "Select the type of the queue:\n1 - int\n2 - float\n3 - double\n4 - char\n5 - bool\n0 - exit\n: ";
    cin >> type;

    switch (type)
    {
    case 0:
        return 0;
    case 1:
    {
        Implementation5<int, 100> temp(order);

        while (true)
        {
            art_line();
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;
            art_line();

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_int());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 2:
    {
        Implementation1<float, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_float());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 3:
    {
        Implementation1<double, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_double());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 4:
    {
        Implementation1<char, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_char());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }

        break;
    }
    case 5:
    {
        Implementation1<bool, 100> temp(order);

        while (true)
        {
            cout << "1 - insert\n2 - delete\n3 - display\n0 - exit\n: ";
            cin >> inp;

            switch (inp)
            {
            case 0:
                return 0;
            case 1:
                cout << "Enter the data: ";
                temp.insert(get_bool());
                break;
            case 2:
                cout << "Data: " << temp.del() << endl;
                break;
            case 3:
                temp.display();
                break;
            }
        }
        
        break;
    }
    }
    return 0;
}