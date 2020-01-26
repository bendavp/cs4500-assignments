//lang::Cpp

#pragma once

#include "string.h"
#include "types.h"
#include <vector>

class Column : public Object
{
public:
    size_t size_;
    std::vector<Object *> arr;
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

    Object *get(size_t idx)
    {
        return arr.at(idx);
    }

    virtual void add(Object *other)
    {
        arr.push_back(other);
        size_++;
    }

    const char *print()
    {
        String *res = new String("[");
        for (int i = 0; i < Column::size_; i++)
        {
            res->concat(new String(arr.at(i)->print()));
            if (i != Column::size_ - 1)
            {
                res->concat(new String(", "));
            }
        }
        return res->concat(new String("]"))->str_;
    }

    virtual const char *getType()
    {
        return NULL;
    }
};

class BoolColumn : public Column
{
public:
    BoolColumn() : Column()
    {
    }
    ~BoolColumn()
    {
    }

    void add(Object *other)
    {
        if (other == nullptr)
        {
            Column::add(other);
        }
        else
        {
            Boolean *other1 = dynamic_cast<Boolean *>(other);
            if (other1 != nullptr)
            {
                Column::add(other);
            }
            else
            {
                println("Cannot add non-bool to BoolColumn!");
                exit(1);
            }
        }
    }

    const char *getType()
    {
        return "BOOL";
    }
};

class IntColumn : public Column
{
public:
    IntColumn() : Column()
    {
    }
    ~IntColumn()
    {
    }

    void add(Object *other)
    {
        if (other == nullptr)
        {
            Column::add(other);
        }
        else
        {
            Integer *other1 = dynamic_cast<Integer *>(other);
            if (other1 != nullptr)
                Column::add(other);
            else
            {
                println("Cannot add non-int to IntColumn!");
                exit(1);
            }
        }
    }

    const char *getType()
    {
        return "INT";
    }
};

class FloatColumn : public Column
{
public:
    FloatColumn() : Column()
    {
    }
    ~FloatColumn()
    {
    }

    void add(Object *other)
    {
        if (other == nullptr)
        {
            Column::add(other);
        }
        else
        {
            Float *other1 = dynamic_cast<Float *>(other);
            if (other1 != nullptr)
                Column::add(other);
            else
            {
                println("Cannot add non-float to FloatColumn!");
                exit(1);
            }
        }
    }

    const char *getType()
    {
        return "FLOAT";
    }
};

class StringColumn : public Column
{
public:
    StringColumn() : Column()
    {
    }
    ~StringColumn()
    {
    }

    void add(Object *other)
    {
        if (other == nullptr)
        {
            Column::add(other);
        }
        else
        {
            String *other1 = dynamic_cast<String *>(other);
            if (other1 != nullptr)
                Column::add(other);
            else
            {
                println("Cannot add non-String to StringColumn!");
                exit(1);
            }
        }
    }

    const char *getType()
    {
        return "STRING";
    }
};