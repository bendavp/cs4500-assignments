//lang::Cpp

#pragma once

#include "string.h"
#include <vector>

class Column : public Object
{
public:
    size_t size_;
    Column() : Object()
    {
        size_ = 0;
    }

    virtual ~Column()
    {
    }

    size_t getSize()
    {
        return Column::size_;
    }
};

class BoolColumn : public Column
{
public:
    std::vector<bool> *arr;
    BoolColumn() : Column()
    {
    }
    ~BoolColumn()
    {
        delete arr;
    }

    bool get(size_t idx)
    {
        return arr->at(idx);
    }

    void add(bool other)
    {
        arr->push_back(other);
        Column::size_++;
    }
};

class IntColumn : public Column
{
public:
    std::vector<int> *arr;
    IntColumn() : Column()
    {
    }
    ~IntColumn()
    {
        delete arr;
    }

    int get(size_t idx)
    {
        return arr->at(idx);
    }

    void add(int other)
    {
        arr->push_back(other);
        Column::size_++;
    }
};

class FloatColumn : public Column
{
public:
    std::vector<float> *arr;
    FloatColumn() : Column()
    {
    }
    ~FloatColumn()
    {
        delete arr;
    }

    float get(size_t idx)
    {
        return arr->at(idx);
    }

    void add(float other)
    {
        arr->push_back(other);
        Column::size_++;
    }
};

class StringColumn : public Column
{
public:
    std::vector<String *> *arr;
    StringColumn() : Column()
    {
    }
    ~StringColumn()
    {
        delete arr;
    }

    String *get(size_t idx)
    {
        return arr->at(idx);
    }

    void add(String *other)
    {
        arr->push_back(other);
        Column::size_++;
    }
};