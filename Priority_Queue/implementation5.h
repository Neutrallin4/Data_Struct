#pragma once
#include "main_structure.h"

using namespace std;

// Insert: rear - Remove: search for biggest and replace rear with it

template <class T, int MAX>
class Implementation5
{
private:
    T data_arr[MAX];
    int rear = 0;
    bool is_ascending = false;

public:
    Implementation5(bool order = false);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

DECLARE(, Implementation5)
Implementation5(bool order) : is_ascending(order)
{
    // Change the order if the queue is ascending
    if (is_ascending)
    {
#undef SYMB
#define SYMB <
    }
}

DECLARE(bool, Implementation5)
is_empty() { return (rear == 0 ? true : false); }

DECLARE(bool, Implementation5)
is_full() { return (rear == MAX ? true : false); }

DECLARE(bool, Implementation5)
insert(T data)
{
    if (is_full())
    {
        cout << "Queue is full. Insertion failed" << endl;
        return false;
    }
    // Add the value and increase the rear
    data_arr[rear++] = data;
    return true;
}

DECLARE(T, Implementation5)
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
    // Delete the value by replacing it with the last element
    data_arr[delete_value_index] = data_arr[--rear];
    // Return the temporary variable
    return temp;
}

DECLARE(void, Implementation5)
display()
{
    cout << "Diaplaying Implementation 5 Queue:" << endl;
    for(int i = 0; i < rear - 1; i++)
        cout << data_arr[i] << " - ";
    cout << data_arr[rear - 1] << endl;
}