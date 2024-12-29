#pragma once
#include "main_structure.h"

using namespace std;

// Insert: rear - Remove: search for biggest and replace rear with it

template <class T, int MAX>
class Implementation5 : public Queue<T, MAX>
{
private:
    int rear = 0;
    
public:
    Implementation5();

    Implementation5(bool);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

DECLARE(, Implementation5)
Implementation5() : Queue<T, MAX>() {}

DECLARE(, Implementation5)
Implementation5(bool order) : Queue<T, MAX>(order) {}

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
    this->data_arr[rear++] = data;
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
        if (compare(this->data_arr[i], this->data_arr[delete_value_index], this->is_ascending))
            delete_value_index = i;
    T temp = this->data_arr[delete_value_index];
    // Delete the value by replacing it with the last element
    this->data_arr[delete_value_index] = this->data_arr[--rear];
    // Return the temporary variable
    return temp;
}

DECLARE(void, Implementation5)
display()
{
    cout << "Diaplaying Implementation 5 Queue:" << endl;
    for(int i = 0; i < rear - 1; i++)
        cout << this->data_arr[i] << " , ";
    cout << this->data_arr[rear - 1] << endl;
}