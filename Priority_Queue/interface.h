#pragma once
#include <iostream>

#include "main_structure.h"
#include "art.h"

using namespace std;

void interface();
void main_menu();
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void menu_5();

void interface()
{
    // Keep the program running unless commanded otherwise (or in case of a possible error)
    while (true)
    {
        art_priority_queue();
        art_line();
        cout << "1 - Queue type 1\n2 - Queue type 2\n3 - Queue type 3" << endl;
        cout << "4 - Queue type 4\n5 - Queue type 5\n0 - exit" << endl;
        int a;
        cin >> a;
        switch (a)
        {
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