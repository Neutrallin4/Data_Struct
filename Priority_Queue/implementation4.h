#include <iostream>

#ifndef SYMB
#define SYMB >
#endif

using namespace std;

// Insert: Always sorted manner - Remove: rear

template <class T, int MAX>
class Implementation4
{
private:
    T data_arr[MAX];
    int rear = 0;
    bool is_ascending = false;

public:
    Implementation4(bool order = false) : is_ascending(order)
    {
        // Change the order if the queue is ascending
        if (is_ascending)
        {
#undef SYMB
#define SYMB <
        }
    }

    bool is_empty() { return (rear == 0 ? true : false); }

    bool is_full() { return (rear == MAX ? true : false); }

    bool insert(T data)
    {
        if (is_full())
        {
            cout << "Queue is full. Insertion failed" << endl;
            return false;
        }

        // Add the value and increase the rear
        for (int i = rear - 1; i >= 0; i--)
            if (data_arr[i] SYMB data)
                data_arr[i + 1] = data[i];
            else
            {
                data_arr[i + 1] = data;
                rear++;
                return true;
            }
        data_arr[0] = data;
        rear++;
        return true;
    }

    T del()
    {
        if (is_empty())
        {
            cout << "Queue is empty. Panic imminent" << endl;
            exit(0);
        }
        // Return rear
        return data_arr[--rear];
    }

    void display()
    {
        cout << "Diaplaying Implementation 1 Queue:" << endl;
        for (int i = 0; i < rear - 1; i++)
            cout << data_arr[i] << " - ";
        cout << data_arr[rear - 1] << endl;
    }
};