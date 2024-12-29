#pragma once
#include "main_structure.h"

using namespace std;

// Insert: first empty place - Remove: search for biggest - removal tag

template <class T, int MAX>
class Implementation2 : public Queue<T, MAX>
{
private:

public:
    Implementation2();

    Implementation2(bool order);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

DECLARE(, Implementation2)
Implementation2() : Queue<T, MAX>() { fill_n(this->data_arr, MAX, -1); }

DECLARE(, Implementation2)
Implementation2(bool order) : Queue<T, MAX>() { fill_n(this->data_arr, MAX, -1); }

DECLARE(bool, Implementation2)
is_empty()
{
    for (int i = 0; i < MAX; i++)
        if (this->data_arr[i] != -1)
            return false;
    return true;
}

DECLARE(bool, Implementation2)
is_full()
{
    for (int i = 0; i < MAX; i++)
        if (this->data_arr[i] == -1)
            return false;
    return true;
}

DECLARE(bool, Implementation2)
insert(T data)
{
    for (int i = 0; i < MAX; i++)
        if (this->data_arr[i] == -1)
        {
            this->data_arr[i] = data;
            return true;
        }
    cout << "Queue is full. Insertion failed" << endl;
    return false;
}

DECLARE(T, Implementation2)
del()
{
    if (is_empty())
    {
        cout << "Queue is empty. Panic imminent" << endl;
        exit(0);
    }
    
    // Find the maximum or minimum value based on the order of the queue
    int delete_value_index = 0;
    for (int i = 0; i < MAX; i++)
        if (compare(this->data_arr[i], this->data_arr[delete_value_index], this->is_ascending))
            delete_value_index = i;
    T temp = this->data_arr[delete_value_index];
    // Delete the value by shifting
    this->data_arr[delete_value_index] = -1;
    // Return the temporary variable
    return temp;
}

DECLARE(void, Implementation2)
display()
{
    cout << "Displaying Implementation 2 Queue:" << endl;
    // Find, print and save the first element
    int first = 0;
    for (first = 0; first < MAX; first++)
        if (this->data_arr[first] != -1)
            break;
    cout << this->data_arr[first];
    // Print the rest of the elements
    first++;
    for (int i = first; i < MAX; i++)
        if (this->data_arr[i] != -1)
            cout << " , " << this->data_arr[i];
    cout << endl;
}