#pragma once
#include <iostream>

#define DECLARE(type, class_name) \
    template <class T, int MAX>   \
    type class_name<T, MAX>::

// Helper function for comparison
template <typename T>
T compare(T a, T b, bool lever) { return (lever ? (a < b) : (a > b)); }

template <class T, int MAX>
class Queue
{
protected:
    T data_arr[MAX];
    bool is_ascending = false;

public:
    Queue() : is_ascending(false) {}
    Queue(bool order) : is_ascending(order) {}
};

#include "implementation1.h"
#include "implementation2.h"
#include "implementation3.h"
#include "implementation4.h"
#include "implementation5.h"