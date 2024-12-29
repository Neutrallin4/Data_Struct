#pragma once
#include "main_structure.h"

using namespace std;

// Insert: rear - Remove: search for biggest - removal tag - Compression when rear = MAX

template <class T, int MAX>
class Implementation3 : public Queue<T, MAX>
{
private:
    int rear = 0;
    
public:
    Implementation3();

    Implementation3(bool order);

    bool is_empty();

    bool is_full();

    bool compress();

    bool insert(T data);

    T del();

    void display();
};

DECLARE(, Implementation3)
Implementation3() : Queue<T, MAX>() { fill_n(this->data_arr, MAX, -1); }

DECLARE(, Implementation3)
Implementation3(bool order) : Queue<T, MAX>(order) { fill_n(this->data_arr, MAX, -1); }

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
        if (this->data_arr[i] == -1)
            reduce_value++;
        else if (reduce_value != 0)
            this->data_arr[i - reduce_value] = this->data_arr[i];
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
    this->data_arr[rear++] = data;
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
        if (compare(this->data_arr[i], this->data_arr[delete_value_index], this->is_ascending))
            delete_value_index = i;
    T temp = this->data_arr[delete_value_index];
    // Delete the value by shifting
    this->data_arr[delete_value_index] = -1;
    // Return the temporary variable
    return temp;
}

DECLARE(void, Implementation3)
display()
{
    cout << "Displaying Implementation 3 Queue:" << endl;
    int count = 0;
    for (int i = 0; i < MAX - 1 ; i++)
        if (this->data_arr[i] != -1)
        {
            cout << this->data_arr[i];
            count = ++i;
            break;
        }
    for (int i = count; i < MAX - 1; i++)
    {
        if (this->data_arr[i] != -1)
            cout << " , " << this->data_arr[i];
    }
    cout << endl;
}