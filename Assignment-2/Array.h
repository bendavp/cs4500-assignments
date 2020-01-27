#pragma once

#include "Object.h"

class Array : public Object
{
public:
    const static size_t MIN_MEMORY_SIZE = 16;

    void **arr_;
    size_t size_;
    size_t memory_size_;

    //constructor
    Array()
    {
        memory_size_ = MIN_MEMORY_SIZE;
        size_ = 0;
        arr_ = new void *[memory_size_];
    }

    //destructor
    ~Array()
    {
        delete[] arr_;
    }

    //insert element at given index and push back rest of elements
    void insert(void *val, size_t index);

    //insert element at end of array
    void insertAtEnd(void *val)
    {
    }

    //insert multiple elements at index
    void insertMultiple(Array *vals, size_t index);

    //set element at index to given value
    void *set(void *val, size_t index);

    //clear Array
    void clear()
    {
    }

    //remove object at given index and return that object
    void *remove(size_t index);

    //return element at given index and error if out-of-bounds
    void *getElementAt(size_t index)
    {
    }

    //return size of Array
    size_t getSize();

    //first index of that element and -1 if doesn't exist
    int indexOf(void *val);

    /**
     * @brief helper function for determining if the given index is within bounds of the array
     * 
     * @param index 
     * @return true if the index is within the bounds (# of elements)
     * @return false if the index is without the bounds
     */
    bool isOutOfBounds(size_t index)
    {
        if (index > size_ - 1)
        {
            return true;
        }
        return false;
    }

    /**
     * @brief doubles the memory allocated for the array
     * 
     */
    void doubleMemSize()
    {
        size_t newMem = memory_size_ * 2;
        void **temp = new void *[newMem];
        for (size_t i = 0; i < size_; i++)
        {
            temp[i] = arr_[i];
        }
        memory_size_ = newMem;
        delete[] arr_;
        arr_ = temp;
    }

    /**
     * @brief halves the memory allocated for the array
     * 
     */
    void halfMemSize()
    {
        size_t newMem = memory_size_ / 2;
        if (newMem > MIN_MEMORY_SIZE)
        {
            void **temp = new void *[newMem];
            for (size_t i = 0; i < size_; i++)
            {
                temp[i] = arr_[i];
            }
            memory_size_ = newMem;
            delete[] arr_;
            arr_ = temp;
        }
    }
};