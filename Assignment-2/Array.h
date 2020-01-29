#pragma once

#include "Object.h"

// general purpose array that stores Objects
class Array : public Object
{
public:
    //constructor
    Array();

    //destructor
    ~Array();

    //insert element at given index and push back rest of elements
    void insert(Object *val, size_t index);

    //insert element at end of array
    void insertAtEnd(Object *val);

    //insert multiple elements at index
    void insertMultiple(Array *vals, size_t index);

    //set element at index to given value
    Object *set(Object *val, size_t index);

    //clear Array
    void clear();

    //remove object at given index and return that object
    Object *remove(size_t index);

    //return element at given index and error if out-of-bounds
    Object *getElementAt(size_t index);

    //return size of Array
    size_t getSize();

    //first index of that element and -1 if doesn't exist
    int indexOf(Object *val);
};

// type strict array that stores Strings
class StringArray : public Object
{
public:
    //constructor
    StringArray();

    //destructor
    ~StringArray();

    //insert element at given index and push back rest of elements
    void insert(String *val, size_t index);

    //insert element at end of array
    void insertAtEnd(String *val);

    //insert multiple elements at index
    void insertMultiple(StringArray *vals, size_t index);

    //set element at index to given value
    String *set(String *val, size_t index);

    //clear Array
    void clear();

    //remove object at given index and return that object
    String *remove(size_t index);

    //return element at given index and error if out-of-bounds
    String *getElementAt(size_t index);

    //return size of Array
    size_t getSize();

    //first index of that element and -1 if doesn't exist
    int indexOf(String *val);
};

// type strict array that stores floats
class FloatArray : public Object
{
public:
    //constructor
    FloatArray();

    //destructor
    ~FloatArray();

    //insert element at given index and push back rest of elements
    void insert(float val, size_t index);

    //insert element at end of array
    void insertAtEnd(float val);

    //insert multiple elements at index
    void insertMultiple(FloatArray *vals, size_t index);

    //set element at index to given value
    float set(float val, size_t index);

    //clear Array
    void clear();

    //remove object at given index and return that object
    float remove(size_t index);

    //return element at given index and error if out-of-bounds
    float getElementAt(size_t index);

    //return size of Array
    size_t getSize();

    //first index of that element and -1 if doesn't exist
    int indexOf(float val);
};

// type strict array that stores ints
class IntArray : public Object
{
public:
    //constructor
    IntArray();

    //destructor
    ~IntArray();

    //insert element at given index and push back rest of elements
    void insert(int val, size_t index);

    //insert element at end of array
    void insertAtEnd(int val);

    //insert multiple elements at index
    void insertMultiple(IntArray *vals, size_t index);

    //set element at index to given value
    int set(int val, size_t index);

    //clear Array
    void clear();

    //remove object at given index and return that object
    int remove(size_t index);

    //return element at given index and error if out-of-bounds
    int getElementAt(size_t index);

    //return size of Array
    size_t getSize();

    //first index of that element and -1 if doesn't exist
    int indexOf(int val);
};

// type strict array that stores booleans
class BoolArray : public Object
{
public:
    //constructor
    BoolArray();

    //destructor
    ~BoolArray();

    //insert element at given index and push back rest of elements
    void insert(bool val, size_t index);

    //insert element at end of array
    void insertAtEnd(bool val);

    //insert multiple elements at index
    void insertMultiple(BoolArray *vals, size_t index);

    //set element at index to given value
    bool set(bool val, size_t index);

    //clear Array
    void clear();

    //remove object at given index and return that object
    bool remove(size_t index);

    //return element at given index and error if out-of-bounds
    bool getElementAt(size_t index);

    //return size of Array
    size_t getSize();

    //first index of that element and -1 if doesn't exist
    int indexOf(bool val);
};