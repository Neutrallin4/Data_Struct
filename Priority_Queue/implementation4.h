#pragma once
#include "main_structure.h"

using namespace std;

// Insert: Always sorted manner - Remove: rear

template <class T, int MAX>
class Implementation4 : public Queue<T, MAX>
{
private:
    int rear = 0;
    
public:
    Implementation4();

    Implementation4(bool order);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

DECLARE(, Implementation4)
Implementation4() : Queue<T, MAX>() {}

DECLARE(, Implementation4)
Implementation4(bool order) : Queue<T, MAX>(order) {}

DECLARE(bool, Implementation4)
is_empty() { return (rear == 0 ? true : false); }

DECLARE(bool, Implementation4)
is_full() { return (rear == MAX ? true : false); }

DECLARE(bool, Implementation4)
insert(T data)
{
    if (is_full())
    {
        cout << "Queue is full. Insertion failed" << endl;
        return false;
    }

    // Add the value and increase the rear
    for (int i = rear - 1; i >= 0; i--)
        if (compare(this->data_arr[i], data, this->is_ascending))
            this->data_arr[i + 1] = this->data_arr[i];
        else
        {
            this->data_arr[i + 1] = data;
            rear++;
            return true;
        }
    this->data_arr[0] = data;
    rear++;
    return true;
}

DECLARE(T, Implementation4)
del()
{
    if (is_empty())
    {
        cout << "Queue is empty. Panic imminent" << endl;
        exit(0);
    }
    // Return rear
    return this->data_arr[--rear];
}

DECLARE(void, Implementation4)
display()
{
    cout << "Diaplaying Implementation 4 Queue:" << endl;
    for (int i = 0; i < rear - 1; i++)
        cout << this->data_arr[i] << " , ";
    cout << this->data_arr[rear - 1] << endl;
}