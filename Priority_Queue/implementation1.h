#pragma once
#include "main_structure.h"

using namespace std;

// Insert: rear - Remove: search for biggest - shift everything left

template <class T, int MAX>
class Implementation1 : public Queue<T, MAX>
{
private:
    int rear = 0;

public:
    Implementation1();

    Implementation1(bool);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

DECLARE(, Implementation1)
Implementation1() : Queue<T, MAX>() {}

DECLARE(, Implementation1)
Implementation1(bool order) : Queue<T, MAX>(order) {}

DECLARE(bool, Implementation1)
is_empty() { return (rear == 0 ? true : false); }

DECLARE(bool, Implementation1)
is_full() { return (rear == MAX ? true : false); }

DECLARE(bool, Implementation1)
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

DECLARE(T, Implementation1)
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
    // Delete the value by shifting
    for (int i = delete_value_index; i < rear; i++)
        this->data_arr[i] = this->data_arr[i + 1];
    // Return the temporary variable
    rear--;
    return temp;
}

DECLARE(void, Implementation1)
display()
{
    cout << "Displaying Implementation 1 Queue:" << endl;
    for (int i = 0; i < rear - 1; i++)
        cout << this->data_arr[i] << " , ";
    cout << this->data_arr[rear - 1] << endl;
}