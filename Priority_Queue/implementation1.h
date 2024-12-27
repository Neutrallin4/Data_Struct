#include <iostream>

#ifndef SYMB
#define SYMB >
#endif

using namespace std;

// Insert: rear - Remove: search for biggest - shift everything left

template <class T, int MAX>
class Implementation1
{
private:
    T data_arr[MAX];
    int rear = 0;
    bool is_ascending = false;

public:
    Implementation1(bool order = false) { is_ascending = order; }

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
        data_arr[rear++] = data;
        return true;
    }

    T del()
    {
        if (is_empty())
        {
            cout << "Queue is empty. Panic imminent" << endl;
            exit(0);
        }
        // Change the order if the queue is ascending
        if (is_ascending)
        {
#undef SYMB
#define SYMB <
        }
        // Find the maximum or minimum value based on the order of the queue
        int delete_value_index = 0;
        for (int i = 0; i < rear; i++)
            if (data_arr[i] SYMB data_arr[delete_value_index])
                delete_value_index = i;
        T temp = data_arr[delete_value_index];
        // Delete the value by shifting
        for (int i = delete_value_index + 1; i < rear;)
            data_arr[i++] = data_arr[i];
        // Return the temporary variable
        rear--;
        return temp;
    }

    void display()
    {
        cout << "Diaplaying Implementation 1 Queue:" << endl;
        for(int i = 0; i < rear - 1; i++)
            cout << data_arr[i] << " - ";
        cout << data_arr[rear - 1] << endl;
    }
};