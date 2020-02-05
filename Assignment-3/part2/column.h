//lang::CwC

#pragma once

#include <stdarg.h>
#include "string.h"

/**
 * @brief Column class. Represents a unified type for the 4 column subclasses
 * 
 * @author Benjamin Kosiborod - kosiborod.b@husky.neu.edu
 * @author Amy Tang - tang.amy@husky.neu.edu
 * 
 */
class Column : public Object
{
public:
    /**
     * @brief Construct a new Column object
     * 
     */
    Column() : Object() {}

    /**
     * @brief Copy construct a new Column object
     * 
     * @param c The Column object to copy
     */
    Column(Column *c) : Object() {}

    /**
     * @brief Destroy the Column object
     * 
     */
    virtual ~Column() {}

    /**
     * @brief hashes this Column
     * 
     * @
     * 
     * @return size_t the hashcode of this Column
     */
    virtual size_t hash() {}

    virtual bool equals() {}

    virtual String *getType() {}

    virtual const char *print() {}
};

class BoolColumn : public Column
{
public:
    BoolColumn() : Column() {}

    BoolColumn(BoolColumn *b) : Column() {}

    ~BoolColumn() {}

    // get function
    size_t hash() {}

    bool equals() {}

    String *getType() {}

    const char *print() {}

    // subset function
    BoolColumn *subset(size_t idx1, size_t idx2) {}
};

class IntColumn : public Column
{
public:
    IntColumn() : Column() {}

    IntColumn(IntColumn *i) : Column() {}

    ~IntColumn() {}

    size_t hash() {}

    bool equals() {}

    String *getType() {}

    const char *print() {}

    IntColumn *subset(size_t idx1, size_t idx2) {}
};

class FloatColumn : public Column
{
public:
    FloatColumn() : Column() {}

    FloatColumn(FloatColumn *f) : Column() {}

    ~FloatColumn() {}

    size_t hash() {}

    bool equals() {}

    String *getType() {}

    const char *print() {}

    FloatColumn *subset(size_t idx1, size_t idx2) {}
};

class StringColumn : public Column
{
public:
    StringColumn() : Column() {}

    StringColumn(StringColumn *s) {}

    ~StringColumn() {}

    size_t hash() {}

    bool equals() {}

    String *getType() {}

    const char *print() {}

    StringColumn *subset(size_t idx1, size_t idx2) {}
};