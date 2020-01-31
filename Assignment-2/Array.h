#pragma once

#include "object.h"
#include "helper.h"
#include "string.h"

// general purpose array that stores Objects
class Array : public Object
{
public:
    Object **arr_;
    size_t size_;
    size_t memory_size_;

    //constructor
    Array()
    {
        memory_size_ = 16;
        arr_ = new Object *[memory_size_];
        size_ = 0;
    }

    //destructor
    ~Array()
    {
        delete arr_;
    }

    void incrementSize()
    {
        memory_size_ *= 2;
        Object **temp = new Object *[memory_size_];

        for (int i = 0; i < size_; i++)
        {
            temp[i] = arr_[i];
        }

        delete arr_;
        arr_ = temp;
    }

    //insert element at given index and push back rest of elements
    void insert(Object *val, size_t index)
    {
        assert(index <= size_);

        if (size_ == memory_size_)
        {
            incrementSize();
        }

        for (int i = size_; i > index; i--)
        {
            arr_[i] = arr_[i - 1];
        }

        arr_[index] = val;

        size_++;
    }

    //insert element at end of array
    void insertAtEnd(Object *val)
    {
        if (size_ == memory_size_)
        {
            incrementSize();
        }

        arr_[size_] = val;

        size_++;
    }

    //insert multiple elements at index
    void insertMultiple(Array *vals, size_t index)
    {
        assert(index <= size_);

        while (size_ + vals->getSize() > memory_size_)
        {
            incrementSize();
        }

        for (int i = size_ - 1; i >= index; i--)
        {
            arr_[i + vals->getSize()] = arr_[i];
        }

        for (int i = 0; i < vals->getSize(); i++)
        {
            arr_[i + index] = vals->getElementAt(i);
        }

        size_ += vals->getSize();
    }

    //set element at index to given value
    Object *set(Object *val, size_t index)
    {
        assert(index < size_);

        Object *temp = arr_[index];
        arr_[index] = val;
        return temp;
    }

    //clear Array
    void clear()
    {
        delete arr_;
        memory_size_ = 16;
        arr_ = new Object *[memory_size_];
        size_ = 0;
    }

    //remove object at given index and return that object
    Object *remove(size_t index)
    {
        assert(index < size_);

        Object *temp = arr_[index];

        for (int i = index; i < size_ - 1; i++)
        {
            arr_[index] = arr_[index + 1];
        }

        delete arr_[size_ - 1];

        size_--;

        return temp;
    }

    //return element at given index and error if out-of-bounds
    Object *getElementAt(size_t index)
    {
        assert(index < size_);

        return arr_[index];
    }

    //return size of Array
    size_t getSize()
    {
        return size_;
    }

    //first index of that element and -1 if doesn't exist
    int indexOf(Object *val)
    {
        for (int i = 0; i < size_; i++)
        {
            if (val->equals(arr_[i]))
            {
                return i;
            }
        }

        return -1;
    }
};

// type strict array that stores Strings
class StringArray : public Object
{
public:
    String **arr_;
    size_t size_;
    size_t memory_size_;

    //constructor
    StringArray()
    {
        memory_size_ = 16;
        arr_ = new String *[memory_size_];
        size_ = 0;
    }

    //destructor
    ~StringArray()
    {
        delete arr_;
    }

    void incrementSize()
    {
        memory_size_ *= 2;
        String **temp = new String *[memory_size_];

        for (int i = 0; i < size_; i++)
        {
            temp[i] = arr_[i];
        }

        delete arr_;
        arr_ = temp;
    }

    //insert element at given index and push back rest of elements
    void insert(String *val, size_t index)
    {
        assert(index <= size_);

        if (size_ == memory_size_)
        {
            incrementSize();
        }

        for (int i = size_; i > index; i--)
        {
            arr_[i] = arr_[i - 1];
        }

        arr_[index] = val;

        size_++;
    }

    //insert element at end of array
    void insertAtEnd(String *val)
    {
        if (size_ == memory_size_)
        {
            incrementSize();
        }

        arr_[size_] = val;

        size_++;
    }

    //insert multiple elements at index
    void insertMultiple(StringArray *vals, size_t index)
    {
        assert(index <= size_);

        while (size_ + vals->getSize() > memory_size_)
        {
            incrementSize();
        }

        for (int i = size_ - 1; i >= index; i--)
        {
            arr_[i + vals->getSize()] = arr_[i];
        }

        for (int i = 0; i < vals->getSize(); i++)
        {
            arr_[i + index] = vals->getElementAt(i);
        }

        size_ += vals->getSize();
    }

    //set element at index to given value
    String *set(String *val, size_t index)
    {
        assert(index < size_);

        String *temp = arr_[index];
        arr_[index] = val;
        return temp;
    }

    //clear Array
    void clear()
    {
        delete arr_;
        memory_size_ = 16;
        arr_ = new String *[memory_size_];
        size_ = 0;
    }

    //remove object at given index and return that object
    String *remove(size_t index)
    {
        assert(index < size_);

        String *temp = arr_[index];

        for (int i = index; i < size_ - 1; i++)
        {
            arr_[index] = arr_[index + 1];
        }

        delete arr_[size_ - 1];

        size_--;

        return temp;
    }

    //return element at given index and error if out-of-bounds
    String *getElementAt(size_t index)
    {
        assert(index < size_);

        return arr_[index];
    }

    //return size of Array
    size_t getSize()
    {
        return size_;
    }

    //first index of that element and -1 if doesn't exist
    int indexOf(String *val)
    {
        for (int i = 0; i < size_; i++)
        {
            if (val->equals(arr_[i]))
            {
                return i;
            }
        }

        return -1;
    }
};

// type strict array that stores floats
class FloatArray : public Object
{
public:
    float *arr_;
    size_t size_;
    size_t memory_size_;

    //constructor
    FloatArray()
    {
        memory_size_ = 16;
        arr_ = new float[memory_size_];
        size_ = 0;
    }

    //destructor
    ~FloatArray()
    {
        delete arr_;
    }

    void incrementSize()
    {
        memory_size_ *= 2;
        float *temp = new float[memory_size_];

        for (int i = 0; i < size_; i++)
        {
            temp[i] = arr_[i];
        }

        delete arr_;
        arr_ = temp;
    }

    //insert element at given index and push back rest of elements
    void insert(float val, size_t index)
    {
        assert(index <= size_);

        if (size_ == memory_size_)
        {
            incrementSize();
        }

        for (int i = size_; i > index; i--)
        {
            arr_[i] = arr_[i - 1];
        }

        arr_[index] = val;

        size_++;
    }

    //insert element at end of array
    void insertAtEnd(float val)
    {
        if (size_ == memory_size_)
        {
            incrementSize();
        }

        arr_[size_] = val;

        size_++;
    }

    //insert multiple elements at index
    void insertMultiple(FloatArray *vals, size_t index)
    {
        assert(index <= size_);

        while (size_ + vals->getSize() > memory_size_)
        {
            incrementSize();
        }

        for (int i = size_ - 1; i >= index; i--)
        {
            arr_[i + vals->getSize()] = arr_[i];
        }

        for (int i = 0; i < vals->getSize(); i++)
        {
            arr_[i + index] = vals->getElementAt(i);
        }

        size_ += vals->getSize();
    }

    //set element at index to given value
    float set(float val, size_t index)
    {
        assert(index < size_);

        float temp = arr_[index];
        arr_[index] = val;
        return temp;
    }

    //clear Array
    void clear()
    {
        delete arr_;
        memory_size_ = 16;
        arr_ = new float[memory_size_];
        size_ = 0;
    }

    //remove object at given index and return that object
    float remove(size_t index)
    {
        assert(index < size_);

        float temp = arr_[index];

        for (int i = index; i < size_ - 1; i++)
        {
            arr_[index] = arr_[index + 1];
        }

        size_--;

        return temp;
    }

    //return element at given index and error if out-of-bounds
    float getElementAt(size_t index)
    {
        assert(index < size_);

        return arr_[index];
    }

    //return size of Array
    size_t getSize()
    {
        return size_;
    }

    //first index of that element and -1 if doesn't exist
    int indexOf(float val)
    {
        for (int i = 0; i < size_; i++)
        {
            if (val == arr_[i])
            {
                return i;
            }
        }

        return -1;
    }
};

// type strict array that stores Ints
class IntArray : public Object
{
public:
    int *arr_;
    size_t size_;
    size_t memory_size_;

    //constructor
    IntArray()
    {
        memory_size_ = 16;
        arr_ = new int[memory_size_];
        size_ = 0;
    }

    //destructor
    ~IntArray()
    {
        delete arr_;
    }

    void incrementSize()
    {
        memory_size_ *= 2;
        int *temp = new int[memory_size_];

        for (int i = 0; i < size_; i++)
        {
            temp[i] = arr_[i];
        }

        delete arr_;
        arr_ = temp;
    }

    //insert element at given index and push back rest of elements
    void insert(int val, size_t index)
    {
        assert(index <= size_);

        if (size_ == memory_size_)
        {
            incrementSize();
        }

        for (int i = size_; i > index; i--)
        {
            arr_[i] = arr_[i - 1];
        }

        arr_[index] = val;

        size_++;
    }

    //insert element at end of array
    void insertAtEnd(int val)
    {
        if (size_ == memory_size_)
        {
            incrementSize();
        }

        arr_[size_] = val;

        size_++;
    }

    //insert multiple elements at index
    void insertMultiple(IntArray *vals, size_t index)
    {
        assert(index <= size_);

        while (size_ + vals->getSize() > memory_size_)
        {
            incrementSize();
        }

        for (int i = size_ - 1; i >= index; i--)
        {
            arr_[i + vals->getSize()] = arr_[i];
        }

        for (int i = 0; i < vals->getSize(); i++)
        {
            arr_[i + index] = vals->getElementAt(i);
        }

        size_ += vals->getSize();
    }

    //set element at index to given value
    float set(int val, size_t index)
    {
        assert(index < size_);

        int temp = arr_[index];
        arr_[index] = val;
        return temp;
    }

    //clear Array
    void clear()
    {
        delete arr_;
        memory_size_ = 16;
        arr_ = new int[memory_size_];
        size_ = 0;
    }

    //remove object at given index and return that object
    int remove(size_t index)
    {
        assert(index < size_);

        int temp = arr_[index];

        for (int i = index; i < size_ - 1; i++)
        {
            arr_[index] = arr_[index + 1];
        }

        size_--;

        return temp;
    }

    //return element at given index and error if out-of-bounds
    int getElementAt(size_t index)
    {
        assert(index < size_);

        return arr_[index];
    }

    //return size of Array
    size_t getSize()
    {
        return size_;
    }

    //first index of that element and -1 if doesn't exist
    int indexOf(int val)
    {
        for (int i = 0; i < size_; i++)
        {
            if (val == arr_[i])
            {
                return i;
            }
        }

        return -1;
    }
};

// type strict array that stores booleans
class BoolArray : public Object
{
public:
    bool *arr_;
    size_t size_;
    size_t memory_size_;

    //constructor
    BoolArray()
    {
        memory_size_ = 16;
        arr_ = new bool[memory_size_];
        size_ = 0;
    }

    //destructor
    ~BoolArray()
    {
        delete arr_;
    }

    void incrementSize()
    {
        memory_size_ *= 2;
        bool *temp = new bool[memory_size_];

        for (int i = 0; i < size_; i++)
        {
            temp[i] = arr_[i];
        }

        delete arr_;
        arr_ = temp;
    }

    //insert element at given index and push back rest of elements
    void insert(bool val, size_t index)
    {
        assert(index <= size_);

        if (size_ == memory_size_)
        {
            incrementSize();
        }

        for (int i = size_; i > index; i--)
        {
            arr_[i] = arr_[i - 1];
        }

        arr_[index] = val;

        size_++;
    }

    //insert element at end of array
    void insertAtEnd(bool val)
    {
        if (size_ == memory_size_)
        {
            incrementSize();
        }

        arr_[size_] = val;

        size_++;
    }

    //insert multiple elements at index
    void insertMultiple(BoolArray *vals, size_t index)
    {
        assert(index <= size_);

        while (size_ + vals->getSize() > memory_size_)
        {
            incrementSize();
        }

        for (int i = size_ - 1; i >= index; i--)
        {
            arr_[i + vals->getSize()] = arr_[i];
        }

        for (int i = 0; i < vals->getSize(); i++)
        {
            arr_[i + index] = vals->getElementAt(i);
        }

        size_ += vals->getSize();
    }

    //set element at index to given value
    bool set(bool val, size_t index)
    {
        assert(index < size_);

        bool temp = arr_[index];
        arr_[index] = val;
        return temp;
    }

    //clear Array
    void clear()
    {
        delete arr_;
        memory_size_ = 16;
        arr_ = new bool[memory_size_];
        size_ = 0;
    }

    //remove object at given index and return that object
    bool remove(size_t index)
    {
        assert(index < size_);

        bool temp = arr_[index];

        for (int i = index; i < size_ - 1; i++)
        {
            arr_[index] = arr_[index + 1];
        }

        size_--;

        return temp;
    }

    //return element at given index and error if out-of-bounds
    bool getElementAt(size_t index)
    {
        assert(index < size_);

        return arr_[index];
    }

    //return size of Array
    size_t getSize()
    {
        return size_;
    }

    //first index of that element and -1 if doesn't exist
    int indexOf(bool val)
    {
        for (int i = 0; i < size_; i++)
        {
            if (val == arr_[i])
            {
                return i;
            }
        }

        return -1;
    }

    bool equals(Object *other) = 0;
};