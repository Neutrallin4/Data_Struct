#pragma once

#include <stdexcept>  // For std::out_of_range

template <class T, int MAX>
class Stack
{
private:
    int size = MAX;
    T *arr = new T[size];
    int top = -1;

public:
    // Push a new element onto the stack
    void push(T data)
    {
        if (top == size - 1) {
            throw std::out_of_range("Stack overflow");  // Handle overflow
        }
        arr[++top] = data;
    }

    // Pop an element from the stack
    T pop()
    {
        if (top == -1) {
            throw std::out_of_range("Stack underflow");  // Handle underflow
        }
        return arr[top--];
    }

    // Peek at the top element of the stack without removing it
    T peek() const
    {
        if (top == -1) {
            throw std::out_of_range("Stack is empty");  // Handle empty stack
        }
        return arr[top];
    }

    // Clear the stack
    void flush()
    {
        while (top > -1)
        {
            pop();  // Empty the stack
        }
    }

    // Check if the stack is empty
    bool is_empty() const { return top == -1; }
};
