#pragma once

/*
BUG List: Default constructors
*/

#include <iostream>

#define DECLARE(type, class_name) template <class T, int MAX> \
type class_name<T, MAX>::

#ifndef SYMB
#define SYMB >
#endif

template <class T, int MAX>
class Implementation1       // Insert: rear - Remove: search for biggest - shift everything left
{
private:
    T data_arr[MAX];
    int rear = 0;
    bool is_ascending = false;

public:
    Implementation1(bool);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

template <class T, int MAX>
class Implementation2       // Insert: first empty place - Remove: search for biggest - removal tag
{
private:
    T data_arr[MAX];
    bool is_ascending = false;

public:
    Implementation2(bool order);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

template <class T, int MAX>
class Implementation3       // Insert: rear - Remove: search for biggest - removal tag - Compression when rear = MAX
{
private:
    T data_arr[MAX];
    int rear = 0;
    bool is_ascending = false;

public:
    Implementation3(bool order = false);

    bool is_empty();

    bool is_full();

    bool compress();

    bool insert(T data);

    T del();

    void display();
};

template <class T, int MAX>
class Implementation4       // Insert: Always sorted manner - Remove: rear
{
private:
    T data_arr[MAX];
    int rear = 0;
    bool is_ascending = false;

public:
    Implementation4(bool order = false);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};

template <class T, int MAX>
class Implementation5       // Insert: rear - Remove: search for biggest and replace rear with it
{
private:
    T data_arr[MAX];
    int rear = 0;
    bool is_ascending = false;

public:
    Implementation5(bool order = false);

    bool is_empty();

    bool is_full();

    bool insert(T);

    T del();

    void display();
};