//lang::CwC

#include "string.h"
#include <stdarg.h>
#include <cassert>
#pragma once

// authors:

/**
 * @brief A class that represents an array of pointers to arrays of integers. This allows us to grow the array 
 * more efficiently and without copying the entire payload. Instead, we copy pointers to the arrays containing the payload 
 * to grow which is more efficient. Additionally, this still allows for O(1) time accessing of the elements.
 * 
 * Solution/Implementation credit: Jan Vitek
 * 
 */
class IntFastArray : public Object
{
public:
    int **arr_;       // array of array
    size_t memory_;   // memory for new arrays
    size_t arr_size_; // size of each int array pointer is pointing tp
    size_t size_;     // total number of ints stored
    size_t arr_fill_; // current number of pointers stored

    // constructor for empty
    IntFastArray()
    {
        arr_size_ = 16;
        memory_ = 16;
        arr_fill_ = 0;
        size_ = 0;
        // intialize everything with nullptrs
        arr_ = new int *[memory_];
        for (size_t i = 0; i < memory_; i++)
        {
            arr_[i] = nullptr;
        }
    }

    // constructor taking in variable number of arguments
    IntFastArray(int n, ...)
    {
        arr_size_ = 16;
        memory_ = 16;
        size_ = n;
        // doubles memory as necessary to ensure all elements will fit with space to grow
        while (n / arr_size_ > memory_)
        {
            memory_ = memory_ * 2;
        }
        arr_ = new int *[memory_]; // initializing int**
        arr_fill_ = 0;             // initialize as 0, will iterate through later
        // adding var arg ints
        va_list v1;
        for (size_t i = 0; i < n; i++)
        {
            // create new int array/int array pointer as necessary
            if (i % arr_size_ == 0)
            {
                arr_[i / arr_size_] = new int[arr_size_];
                arr_fill_ = arr_fill_ + 1; // we are using up +1 array so increment this count
            }
            // filling appropriate location with the value
            arr_[i / arr_size_][i % arr_size_] = va_arg(v1, int);
        }
        va_end(v1);
        // fill the rest of the array with nullptr
        for (size_t i = arr_fill_; i < memory_; i++)
        {
            arr_[i] = nullptr;
        }
    }

    /**
     * @brief Returns the integer from a certain location. The math works out as if this is a linear array 
     * rather than an array of arrays. 
     * 
     * @param idx the index as if this is a linear array (out of size_)
     * @return int the value at that index
     */
    int get(size_t idx)
    {
        assert(!outOfBounds(idx));
        size_t adj_idx = idx - 1; // adjust given index to account for 0-indexing when searching for that specific index
        return arr_[idx / arr_size_][idx % arr_size_];
    }

    /**
     * @brief Sets the integer at a certain location. The math works out as if this is a linear array 
     * rather than an array of arrays. 
     * 
     * @param idx the index as if this is a linear array (out of size_) at which the value is changed
     * @param i the new value to be used at idx
     */
    void set(size_t idx, int i)
    {
        assert(!outOfBounds(idx));
        arr_[idx / arr_size_][idx % arr_size_] = i;
    }

    /**
     * @brief Adds an integer at the end of the "array" (as if it is a linear array).
     * 
     * @param i the integer to be added
     */
    void pushback(int i)
    {
        // checking to see if when we add an element, we will run out of space
        if (size_ + 1 > arr_fill_ * arr_size_)
        {
            grow(); // expands appropriately
        }
        size_t new_idx = size_; // this is the idx of the value to be added
        arr_[new_idx / arr_size_][new_idx % arr_size_] = i;
        size_ = size_ + 1;
    }

    /**
     * @brief Returns the number of elements/values that the array holds. 
     * 
     * @return size_t the total number of values that the array holds
     */
    size_t size()
    {
        return size_;
    }

    /**
     * @brief Helper function to grow the size of the array. If there is still room for a new pointer, then it will create an int*
     * for the next available "slot". If there is not room, then the array of arrays will double (effectively doubling number
     * of pointers that are available). 
     * 
     */
    void grow()
    {
        // we have filled up all of the int arrays in the memory space we have allocated completely
        // need to expand the memory of the "outer" array
        if (arr_fill_ == memory_)
        {

            memory_ = memory_ * 2;                // double the memory
            int **temp_arr_ = new int *[memory_]; // initalize new int** with the new mem size
            // copy over pointers from filled array
            for (size_t i = 0; i < arr_fill_; i++)
            {
                temp_arr_[i] = arr_[i];
            }
            // fill in the rest of new array with nullptr
            for (size_t i = arr_fill_; i < memory_; i++)
            {
                temp_arr_[i] = nullptr;
            }
            temp_arr_[arr_fill_] = new int[arr_size_]; // initialize new int* pointer in temp_arr_ in the new space
            arr_fill_ = arr_fill_ + 1;                 // increase this count
            delete[] arr_;                             // delete the old arr_ and its pointers
            arr_ = temp_arr_;                          // set arr_ to the new expanded array
            delete temp_arr_;
        }
        // we only need to create a new int array in place of the nullptr
        else
        {
            arr_[arr_fill_] = new int[arr_size_];
            arr_fill_ = arr_fill_ + 1;
        }
    }

    /**
     * @brief Helper function to determine if a given index is out of bounds. 
     * 
     * @return true if the given idx is out of bounds (>= total num of elements)
     * @return false if the given idx is not out of bounds (< total num of elements)
     */
    bool outOfBounds(size_t idx)
    {
        return idx < size_;
    }
};