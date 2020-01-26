#pragma once

#include "Object.h"

class Array : public Object
{
public:
    //constructor
    Array();

    //destructor
    ~Array();

    //insert element at given index and push back rest of elements
    void insert(void *val, size_t index);

    //insert element at end of array
    void insertAtEnd(void *val);

    //insert multiple elements at index
    void insertMultiple(Array *vals, size_t index);

    //set element at index to given value
    void *set(void *val, size_t index);

    //clear Array
    void clear();

    //remove object at given index and return that object
    void *remove(size_t index);

    //return element at given index and error if out-of-bounds
    void *getElementAt(size_t index);

    //return size of Array
    size_t getSize();

    //first index of that element and -1 if doesn't exist
    int indexOf(void *val);
};