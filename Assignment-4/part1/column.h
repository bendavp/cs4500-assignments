//lang:CwC

#pragma once
#include "fastarray.h"

/**************************************************************************
 * Column ::
 * Represents one column of a data frame which holds values of a single type.
 * This abstract class defines methods overriden in subclasses. There is
 * one subclass per element type. Columns are mutable, equality is pointer
 * equality. */
class Column : public Object
{
public:
    /** Type converters: Return same column under its actual type, or
   *  nullptr if of the wrong type.  */
    virtual IntColumn *as_int() { return nullptr; }
    virtual BoolColumn *as_bool() { return nullptr; }
    virtual FloatColumn *as_float() { return nullptr; }
    virtual StringColumn *as_string() { return nullptr; }

    /** Type appropriate push_back methods. Calling the wrong method is
    * undefined behavior. **/
    virtual void push_back(int val) {}
    virtual void push_back(bool val) {}
    virtual void push_back(float val) {}
    virtual void push_back(String *val) {}

    /** Returns the number of elements in the column. */
    virtual size_t size() {}

    /** Return the type of this column as a char: 'S', 'B', 'I' and 'F'. */
    char get_type()
    {
        if (this->as_int() != nullptr)
        {
            return 'I';
        }
        else if (this->as_bool() != nullptr)
        {
            return 'B';
        }
        else if (this->as_float() != nullptr)
        {
            return 'F';
        }
        else if (this->as_string() != nullptr)
        {
            return 'S';
        }
        else
        {
            exit(1);
        }
    }
};

/*************************************************************************/
/**
 * BoolColumn::
 * Holds int values.
 */
class BoolColumn : public Column
{
public:
    BoolFastArray *arr_;

    BoolColumn()
    {
        arr_ = new BoolFastArray();
    }

    BoolColumn(int n, ...)
    {
        va_list = v1;
        arr_ = new BoolFastArray(n, v1);
    }

    bool get(size_t idx)
    {
        return arr_->get(idx);
    }

    BoolColumn *as_bool()
    {
        return this;
    }

    /** Set value at idx. An out of bound idx is undefined.  */
    void set(size_t idx, bool val)
    {
        arr_->set(idx, val);
    }

    size_t size()
    {
        return arr_->size();
    }

    void push_back(bool val)
    {
        arr_->push_back(val);
    }
};

/*************************************************************************
 * IntColumn::
 * Holds int values.
 */
class IntColumn : public Column
{
public:
    IntFastArray *arr_;

    IntColumn()
    {
        arr_ = new IntFastArray();
    }

    IntColumn(int n, ...)
    {
        va_list = v1;
        arr_ = new IntFastArray(n, v1);
    }

    int get(size_t idx)
    {
        return arr_->get(idx);
    }

    IntColumn *as_int()
    {
        return this;
    }
    /** Set value at idx. An out of bound idx is undefined.  */
    void set(size_t idx, int val) {}

    size_t size()
    {
        return arr_->size();
    }

    void push_back(int val)
    {
        arr_->push_back(val);
    }
};

/*************************************************************************
 * FloatColumn::
 * Holds float values.
 */
class FloatColumn : public Column
{
public:
    FloatFastArray *arr_;

    FloatColumn()
    {
        arr_ = new FloatFastArray();
    }

    FloatColumn(int n, ...)
    {
        va_list = v1;
        arr_ = new FloatFastArray(n, v1);
    }

    float get(size_t idx)
    {
        return arr_->get(idx);
    }

    FloatColumn *as_float()
    {
        return this;
    }

    /** Set value at idx. An out of bound idx is undefined.  */
    void set(size_t idx, float val)
    {
        arr_->set(idx, val);
    }

    size_t size()
    {
        return arr_->size();
    }

    void push_back(float val)
    {
        arr_->push_back(val);
    }
};

/*************************************************************************
 * StringColumn::
 * Holds string pointers. The strings are external.  Nullptr is a valid
 * value.
 */
class StringColumn : public Column
{
public:
    StringFastArray *arr_;

    StringColumn()
    {
        arr_ = new StringFastArray();
    }

    StringColumn(int n, ...)
    {
        va_list = v1;
        arr_ = new StringFastArray(n, v1);
    }

    StringColumn *as_string()
    {
        return this;
    }

    /** Returns the string at idx; undefined on invalid idx.*/
    String *get(size_t idx)
    {
        return arr_->get(idx);
    }
    /** Out of bound idx is undefined. */
    void set(size_t idx, String *val)
    {
        arr_->set(idx, val);
    }
    size_t size()
    {
        return arr_->size();
    }

    void push_back(String *val)
    {
        arr_->push_back(val);
    }
};