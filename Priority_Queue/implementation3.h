#pragma once
#include "main_structure.h"

using namespace std;

// Insert: rear - Remove: search for biggest - removal tag - Compression when rear = MAX

DECLARE(, Implementation3)
Implementation3(bool order) : is_ascending(order)
{
    // Change the order if the queue is ascending
    if (is_ascending)
    {
#undef SYMB
#define SYMB <
    }
}

DECLARE(bool, Implementation3)
is_empty() { return (rear == 0 ? true : false); }

DECLARE(bool, Implementation3)
is_full() { return (rear == MAX ? true : false); }

DECLARE(bool, Implementation3)
compress()
{
    int reduce_value = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (data_arr[i] == -1)
            reduce_value++;
        else if (reduce_value != 0)
            data_arr[i - reduce_value] = data_arr[i];
    }
    rear -= reduce_value;
    return (reduce_value != 0);
}

DECLARE(bool, Implementation3)
insert(T data)
{
    if (is_full())
        if (!compress())
        {
            cout << "Queue is full. Insertion failed" << endl;
            return false;
        }
    // Add the value and increase the rear
    data_arr[rear++] = data;
    return true;
}

DECLARE(T, Implementation3)
del()
{
    if (is_empty())
    {
        cout << "Queue is empty. Panic imminent" << endl;
        exit(0);
    }
    
    // Find the maximum or minimum value based on the order of the queue
    int delete_value_index = 0;
    for (int i = 0; i < rear; i++)
        if (data_arr[i] SYMB data_arr[delete_value_index])
            delete_value_index = i;
    T temp = data_arr[delete_value_index];
    // Delete the value by shifting
    data_arr[delete_value_index] = -1;
    // Return the temporary variable
    rear--;
    return temp;
}

DECLARE(void, Implementation3)
display()
{
    cout << "Diaplaying Implementation 3 Queue:" << endl;
    for(int i = 0; i < rear - 1; i++)
        cout << data_arr[i] << " - ";
    cout << data_arr[rear - 1] << endl;
}