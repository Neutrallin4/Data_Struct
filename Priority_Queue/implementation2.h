#include <iostream>

#ifndef SYMB
#define SYMB >
#endif

using namespace std;

// Insert: first empty place - Remove: search for biggest - removal tag

template <class T, int MAX>
class Implementation2
{
private:
    T data_arr[MAX];
    bool is_ascending = false;

public:
    Implementation2(bool order) : is_ascending(order)
    {
        fill_n(data_arr, MAX, -1);
        // Change the order if the queue is ascending
        if (is_ascending)
        {
#undef SYMB
#define SYMB <
        }
    }

    bool is_empty()
    {
        for (int i = 0; i < MAX; i++)
            if (data_arr[i] != -1)
                return false;
        return true;
    }

    bool is_full()
    {
        for (int i = 0; i < MAX; i++)
            if (data_arr[i] == -1)
                return false;
        return true;
    }

    bool insert(T data)
    {
        for (int i = 0; i < MAX; i++)
            if (data_arr[i] == -1)
            {
                data_arr[i] = data;
                return true;
            }
        cout << "Queue is full. Insertion failed" << endl;
        return false;
    }

    T del()
    {
        if (is_empty())
        {
            cout << "Queue is empty. Panic imminent" << endl;
            exit(0);
        }
        
        // Find the maximum or minimum value based on the order of the queue
        int delete_value_index = 0;
        for (int i = 0; i < MAX; i++)
            if (data_arr[i] SYMB data_arr[delete_value_index])
                delete_value_index = i;
        T temp = data_arr[delete_value_index];
        // Delete the value by shifting
        data_arr[delete_value_index] = -1;
        // Return the temporary variable
        return temp;
    }

    void display()
    {
        cout << "Displaying Implementation 2 Queue:" << endl;
        // Find, print and save the first element
        int first = 0;
        for (first = 0; first < MAX; first++)
            if (data_arr[first] != -1)
                break;
        cout << data_arr[first];
        // Print the rest of the elements
        first++;
        for (int i = first; i < MAX; i++)
            if (data_arr[i] != -1)
                cout << " - " << data_arr[i];
        cout << endl;
    }
};