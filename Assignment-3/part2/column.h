//lang::CwC

#pragma once

#include <stdarg.h>
#include <assert.h>
#include "string.h"
#include <math.h>

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
     * @note Column class is not meant to be a standalone class, thus this function
     * should always terminate
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
     * @note Column class is not meant to be a standalone class, thus this function
     * should always terminate
     */
    virtual size_t hash() {}

    /**
     * @brief Checks whether a given Object is equal to this Column
     * 
     * @note Column class is not meant to be a standalone class, thus this function
     * should always terminate
     * 
     * @param other The Object to be compared to this Column
     */
    virtual bool equals(Object *other) {}

    /**
     * @brief gets a (printable) char* that contains information about this Column
     * 
     * @note Column class is not meant to be a standalone class, thus this function
     * should always terminate
     */
    virtual const char *print() {}
};

/**
 * @brief BoolColumn class. Represents a column in a @class DataFrame that holds bool values
 * 
 * @author Benjamin Kosiborod - kosiborod.b@husky.neu.edu
 * @author Amy Tang - tang.amy@husky.neu.edu
 */
class BoolColumn : public Column
{
public:
    /**
     * @brief Construct a new Bool Column object
     * 
     * @note takes a variable number of bools
     */
    BoolColumn() : Column() {}

    /**
     * @brief Construct a new Bool Column object using information from the given BoolColumn
     * 
     * @param b The BoolColumn whose information is to be copied to this BoolObject
     */
    BoolColumn(BoolColumn *b) : Column() {}

    /**
     * @brief Destroy the Bool Column object
     * 
     */
    ~BoolColumn() {}

    /**
     * @brief hashes this BoolColumn
     * 
     * @return size_t the hashcode of this BoolColumn
     */
    size_t hash() {}

    /**
     * @brief Checks whether a given Object is equal to this BoolColumn
     * 
     * @param other The Object to be compared to this BoolColumn
     * @return true if the given Object is a BoolColumn, and the given BoolColumn has the same bools in the same order as this BoolColumn
     * @return false if  any of the above conditions are not satisfied
     */
    bool equals(Object *other) {}

    /**
     * @brief Get the BoolColumn type
     * 
     * @return String* always returns "BOOL" as this is a BoolColumn
     */
    String *getType() {}

    /**
     * @brief gets a (printable) char* that contains information about this BoolColumn
     * 
     * @return char* A char* representation of all the bools in this BoolColumn
     */
    const char *print() {}

    /**
     * @brief gets a subset of this BoolColumn 
     * 
     * @param idx1 the index of this BoolColumn to start taking the subset (inclusive)
     * @param idx2 the index of this BoolColumn to stop taking the subset (exclusive)
     * @return BoolColumn* the subset of this BoolColumn
     */
    BoolColumn *subset(size_t idx1, size_t idx2) {}

    /**
     * @brief gets the bool at the given index in this BoolColumn
     * 
     * @param idx the index at which to get the bool
     * @return bool the bool at the given index
     */
    bool get(size_t idx) {}

    /**
     * @brief checks if the element at the given index in this BoolColumn is missing
     * 
     * @param idx the index at which to check for a missing element
     * @return true if the element at the given index is NULL
     * @return false if the element at the given index is NOT NULL
     */
    bool isMissing(size_t idx) {}

    /**
     * @brief removes an element from the BoolColumn
     *  
     */
    void remove() {}

    /**
     * @brief checks if the current BoolColumn has no elements in it 
     * (missing elements are still elements, therefore a BoolColumn with only missing elements is NOT empty)
     * 
     * @return true if there are no elements
     * @return false if there is at least one element
     */
    bool isEmpty() {}
};

/**
 * @brief IntColumn class. Represents a column in a @class DataFrame that holds int values
 * 
 * @author Benjamin Kosiborod - kosiborod.b@husky.neu.edu
 * @author Amy Tang - tang.amy@husky.neu.edu
 */
class IntColumn : public Column
{
public:
    /**
     * @brief Construct a new IntColumn object
     * 
     * @note takes a variable number of ints
     */
    IntColumn() : Column() {}

    /**
     * @brief Construct a new IntColumn object using information from the given BoolColumn
     * 
     * @param i The BoolColumn whose information is to be copied to this BoolObject
     */
    IntColumn(IntColumn *i) : Column() {}

    /**
     * @brief Destroy the IntColumn object
     * 
     */
    ~IntColumn() {}

    /**
     * @brief hashes this IntColumn
     * 
     * @return size_t the hashcode of this IntColumn
     */
    size_t hash() {}

    /**
     * @brief Checks whether a given Object is equal to this IntColumn
     * 
     * @param other The Object to be compared to this IntColumn
     * @return true if the given Object is a IntColumn, and the given IntColumn has the same ints in the same order as this IntColumn
     * @return false if any of the above conditions are not satisfied
     */
    bool equals(Object *other) {}

    /**
     * @brief Get the IntColumn type
     * 
     * @return String* always returns "INT" as this is a IntColumn
     */
    String *getType() {}

    /**
     * @brief gets a (printable) char* that contains information about this IntColumn
     * 
     * @return char* A char* representation of all the ints in this IntColumn
     */
    const char *print() {}

    /**
     * @brief gets a subset of this IntColumn 
     * 
     * @param idx1 the index of this IntColumn to start taking the subset (inclusive)
     * @param idx2 the index of this IntColumn to stop taking the subset (exclusive)
     * @return IntColumn* the subset of this IntColumn
     */
    IntColumn *subset(size_t idx1, size_t idx2) {}

    /**
     * @brief gets the int at the given index in this IntColumn
     * 
     * @param idx the index at which to get the int
     * @return int the int at the given index
     */
    int get(size_t idx) {}

    /**
     * @brief checks if the element at the given index in this IntColumn is missing
     * 
     * @param idx the index at which to check for a missing element
     * @return true if the element at the given index is NULL
     * @return false if the element at the given index is NOT NULL
     */
    bool isMissing(size_t idx) {}

    /**
     * @brief removes an element from the IntColumn
     *  
     */
    void remove() {}

    /**
     * @brief checks if the current IntColumn has no elements in it 
     * (missing elements are still elements, therefore an IntColumns with only missing elements is NOT empty)
     * 
     * @return true if there are no elements
     * @return false if there is at least one element
     */
    bool isEmpty() {}
};

/**
 * @brief FloatColumn class. Represents a column in a @class DataFrame that holds float values
 * 
 * @author Benjamin Kosiborod - kosiborod.b@husky.neu.edu
 * @author Amy Tang - tang.amy@husky.neu.edu
 */
class FloatColumn : public Column
{
public:
    /**
     * @brief Construct a new FloatColumn object
     * 
     * @note takes a variable number of floats
     */
    FloatColumn() : Column() {}

    /**
     * @brief Construct a new FloatColumn object using information from the given FloatColumn
     * 
     * @param f The FloatColumn whose information is to be copied to this FloatObject
     */
    FloatColumn(FloatColumn *f) : Column() {}

    /**
     * @brief Destroy the FloatColumn object
     * 
     */
    ~FloatColumn() {}

    /**
     * @brief hashes this FloatColumn
     * 
     * @return size_t the hashcode of this FloatColumn
     */
    size_t hash() {}

    /**
     * @brief Checks whether a given Object is equal to this FloatColumn
     * 
     * @param other The Object to be compared to this FloatColumn
     * @return true if the given Object is a FloatColumn, and the given FloatColumn has the same ints in the same order as this FloatColumn
     * @return false if  any of the above conditions are not satisfied
     */
    bool equals(Object *other) {}

    /**
     * @brief Get the FloatColumn type
     * 
     * @return String* always returns "FLOAT" as this is a FloatColumn
     */
    String *getType() {}

    /**
     * @brief gets a (printable) char* that contains information about this FloatColumn
     * 
     * @return char* A char* representation of all the floats in this FloatColumn
     */
    const char *print() {}

    /**
     * @brief gets a subset of this FloatColumn 
     * 
     * @param idx1 the index of this FloatColumn to start taking the subset (inclusive)
     * @param idx2 the index of this FloatColumn to stop taking the subset (exclusive)
     * @return FloatColumn* the subset of this FloatColumn
     */
    FloatColumn *subset(size_t idx1, size_t idx2) {}

    /**
     * @brief gets the float at the given index in this FloatColumn
     * 
     * @param idx the index at which to get the float
     * @return float the float at the given index
     */
    float get(size_t idx) {}

    /**
     * @brief checks if the element at the given index in this FloatColumn is missing
     * 
     * @param idx the index at which to check for a missing element
     * @return true if the element at the given index is NaN
     * @return false if the element at the given index is NOT NaN
     */
    bool isMissing(size_t idx) {}

    /**
     * @brief removes an element from the FloatColumn
     *  
     */
    void remove() {}

    /**
     * @brief checks if the current FloatColumn has no elements in it
     * (missing elements are still elements, therefore an FloatColumns with only missing elements is NOT empty)
     * 
     * @return true if there are no elements
     * @return false if there is at least one element
     */
    bool isEmpty() {}
};

/**
 * @brief StringColumn class. Represents a column in a @class DataFrame that holds String values
 * 
 * @author Benjamin Kosiborod - kosiborod.b@husky.neu.edu
 * @author Amy Tang - tang.amy@husky.neu.edu
 */
class StringColumn : public Column
{
public:
    /**
     * @brief Construct a new StringColumn object
     * 
     * @note takes a variable number of Strings
     */
    StringColumn() : Column() {}

    /**
     * @brief Construct a new StringColumn object using information from the given StringColumn
     * 
     * @param s The StringColumn whose information is to be copied to this StringObject
     */
    StringColumn(StringColumn *s) : Column() {}

    /**
     * @brief Destroy the StringColumn object
     * 
     */
    ~StringColumn() {}

    /**
     * @brief hashes this StringColumn
     * 
     * @return size_t the hashcode of this StringColumn
     */
    size_t hash() {}

    /**
     * @brief Checks whether a given Object is equal to this StringColumn
     * 
     * @param other The Object to be compared to this StringColumn
     * @return true if the given Object is a StringColumn, and the given StringColumn has the same Strings in the same order as this StringColumn
     * @return false if any of the above conditions are not satisfied
     */
    bool equals(Object *other) {}

    /**
     * @brief Get the StringColumn type
     * 
     * @return String* always returns "STRING" as this is a StringColumn
     */
    String *getType() {}

    /**
     * @brief gets a (printable) char* that contains information about this StringColumn
     * 
     * @return char* A char* representation of all the Strings in this StringColumn
     */
    const char *print() {}

    /**
     * @brief gets a subset of this StringColumn 
     * 
     * @param idx1 the index of this StringColumn to start taking the subset (inclusive)
     * @param idx2 the index of this StringColumn to stop taking the subset (exclusive)
     * @return StringColumn* the subset of this StringColumn
     */
    StringColumn *subset(size_t idx1, size_t idx2) {}

    /**
     * @brief gets the String at the given index in this StringColumn
     * 
     * @param idx the index at which to get the String
     * @return String* the String at the given index
     */
    String *get(size_t idx) {}

    /**
     * @brief checks if the element at the given index in this StringColumn is missing
     * 
     * @param idx the index at which to check for a missing element
     * @return true if the element at the given index is nullptr
     * @return false if the element at the given index is NOT nullptr
     */
    bool isMissing(size_t idx) {}

    /**
     * @brief removes an element from the StringColumn
     *  
     */
    void remove() {}

    /**
     * @brief checks if the current StringColumn has no elements in it
     * (missing elements are still elements, therefore an StringColumns with only missing elements is NOT empty)
     * 
     * @return true if there are no elements
     * @return false if there is at least one element
     */
    bool isEmpty() {}
};