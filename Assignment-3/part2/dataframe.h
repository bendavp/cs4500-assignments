//lang::CwC

#include "string.h"
#include "column.h"
#include <stdarg.h>

#pragma once

/**
 * @brief gg
 * 
 * @author Amy Tang - tang.amy@husky.neu.edu
 * @author Benjamin Kosiborod - kosiborod.b@husky.neu.edu
 * 
 */
class Dataframe : public Object {
public:
    // constructors
    Dataframe() : Object() {}
    Dataframe(Dataframe *df) : Object() {}
    ~Dataframe() {}
    
    /**
     * @brief gets an int from a specific cell in the dataframe
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - row index given as a size_t
     * @return int or aborts execution if the column pulled from is not an IntColumn
     */
    int getInt(size_t ridx, size_t cidx) {} 

    /**
     * @brief gets an int from a specific cell in the dataframe
     * 
     * @param ridx - row index given as the name of the row (could be an int)
     * @param cidx - col index given as the name of the col (could be an int)
     * @return int or aborts execution if the column pulled from is not an IntColumn
     */
    int getInt(const char* ridx, const char* cidx) {}

    /**
     * @brief gets an float from a specific cell in the dataframe
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @return float or aborts execution if the column pulled from is not a FloatColumn
     */
    float getFloat(size_t ridx, size_t cidx) {} 

    /**
     * @brief gets an float from a specific cell in the dataframe
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @return float or aborts execution if the column pulled from is not a FloatColumn
     */
    float getFloat(const char* ridx, const char* cidx) {}

    /**
     * @brief gets a bool from a specific cell in the dataframe
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @return true if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     * @return false if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     */
    bool getBool(size_t ridx, size_t cidx) {} 

    /**
     * @brief gets a bool from a specific cell in the dataframe
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @return true if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     * @return false if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     */
    bool getBool(const char* ridx, const char* cidx) {}

    /**
     * @brief gets a String from a specific cell in the dataframe
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @return String* or aborts execution if the column pulled from is not a StringColumn
     */
    String *getString(size_t ridx, size_t cidx) {}

    /**
     * @brief gets a String from a specific cell in the dataframe
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @return String* or aborts execution if the column pulled from is not a StringColumn
     */
    String *getString(const char* ridx, const char* cidx) {}

    /**
     * @brief returns the total number of rows (not including headers) of the dataframe
     * 
     * @return size_t - num of rows
     */
    size_t nrow(){}

    /**
     * @brief returns the total number of columns (not including headers) of the dataframe
     * 
     * @return size_t - num of cols
     */
    size_t ncol(){}

    void append(void*){}

    /**
     * @brief adds a IntColumn to the end (most right side) of the dataframe. Aborts execution if column does not fit the shape
     * of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertIntCol(IntColumn *icol){}

    /**
     * @brief adds a IntColumn at the index specified by cidx. Aborts execution if column does not fit the shape
     * of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertIntCol(IntColumn *icol, size_t cidx){}

    /**
     * @brief adds a FloatColumn to the end (most right side) of the dataframe. Aborts execution if column does not fit the shape
     * of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertFloatCol(FloatColumn *fcol){}

    /**
     * @brief adds a FloatColumn at the index specified by cidx (other columns will be pushed to the right). Aborts execution 
     * if column does not fit the shape of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertFloatCol(FloatColumn *fcol, size_t cidx){}

    /**
     * @brief adds a BoolColumn to the end (most right side) of the dataframe. Aborts execution if column does not fit the shape
     * of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertBoolCol(BoolColumn *bcol){}

    /**
     * @brief adds a BoolColumn at the index specified by cidx (other columns will be pushed to the right). Aborts execution 
     * if column does not fit the shape of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertBoolCol(BoolColumn *bcol, size_t cidx){}

    /**
     * @brief adds a StringColumn to the end (most right side) of the dataframe. Aborts execution if column does not fit the shape
     * of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertStringCol(StringColumn *scol){}

    /**
     * @brief adds a StringColumn at the index specified by cidx (other columns will be pushed to the right). Aborts execution 
     * if column does not fit the shape of the existing dataframe and the dataframe is not empty. 
     * 
     */
    void insertStringCol(StringColumn *scol, size_t cidx){}

    /**
     * @brief prints out the dataframe in the shape of the dataframe; separating columns via tab-delimited format to keep
     * the dataframe readable
     * 
     * @return const char* - prints out the dataframe
     */
    const char *print(){}

    /**
     * @brief returns bool signifying if the dataframe is equivalent to the object passed in.
     * 
     * @return true - if this dataframe is the same shape and has all of the same values/headers 
     * as the objective passed in assuming the objective is a dataframe
     * @return false - if objective passed in is not a dataframe or if this dataframe is not the same shape or 
     * contains different values/headers compared to the dataframe passed in
     */
    bool equals(Object* o){}

    /**
     * @brief calculates and returns a hash of the dataframe
     * 
     * @return size_t - hash value of this dataframe
     */
    size_t hash(){}

    /**
     * @brief gets the names of the indices which the rows can be referred to as and returns them to the user as an String array. 
     * If the user has not entered any specific indicies such as ('Mazda RX4', 'Datsun 710') to be the row names, the automatic indexing
     * names will be returned ('0', '1', etc.) or a mix of these ('0', 'Mazda RX4', '2', etc.)
     * 
     * @return String** - a String array of the names of the row names
     */
    String **getRowNames(){}

    /**
     * @brief gets the names of the indices which the rows can be referred to as and returns them to the user as an String array. 
     * If the user has not entered any specific indicies such as ('mpg', 'hp') to be the row names, the automatic indexing
     * names will be returned ('0', '1', etc.) or a mix of these ('0', 'mpg', '2', etc.)
     * 
     * @return String** - a String array of the names of the col names
     */
    String **getColNames(){}

    /**
     * @brief returns in String array, written in plain english, that specifies the type (Int, Bool, etc) of the columns
     * 
     * @return String** - a String array, specifying in english (Int, Bool, etc), the type of the col types
     */
    String **dTypes(){}

    /**
     * @brief returns, in plain english via a String, the type of the specified column (specified by cidx, which represents 
     * the numerical index of the column)
     * 
     * @param cidx 
     * @return String* 
     */
    String *getColType(size_t cidx){}

    /**
     * @brief returns, in plain english via a String, the type of the specified column (specified by cidx, which represents 
     * the name of the column i.e. 'mpg' or '1')
     * 
     * @param cidx 
     * @return String* 
     */
    String *getColType(const char* cidx){}
    
    /**
     * @brief Returns the shape of the dataframe. For example, if the dataframe has 3 rows and 2 columns, this will return 
     * an 2-length array [3,2] where the array is of the format [num_row, num_cols]. 
     * 
     * @return size_t* - returns shape of the dataframe in the format of a size_t array
     */
    size_t *shape(){}

    /**
     * @brief Returns the total number of cells of the dataframe has which can be calculated by num_row X num-col
     * 
     * @return size_t - returns the cells in the dataframe
     */
    size_t size(){}

    /**
     * @brief checks if the dataframe is empty (i.e. no columns (so also effectively no rows))
     * 
     * @return true - if the dataframe is empty (no columns/rows)
     * @return false - if the dataframe is not empty (has at least one column/row)
     */
    bool empty(){}

    /**
     * @brief clears the dataframe of all col/rows and deletes the objects inside
     * 
     */
    void clear(){}

    /**
     * @brief prints out the first 6 rows of the dataframe in the shape of the dataframe; separating columns via tab-delimited format to keep
     * the dataframe readable
     * 
     * @return const char* - prints out the first 6 rows of the dataframe
     */
    const char *head(){}

    /**
     * @brief Get a subset of the Dataframe by the specified start and end row and col indicies
     * 
     * @param size_t ridx1 - beginning row index, inclusive
     * @param size_t ridx2 - end row index, non-inclusive
     * @param size_t cidx1 - beginning col index, inclusive
     * @param size_t cidx2 - end col index, non-inclusive
     *
     * @return Dataframe* that is a subset of this dataframe with the specifications
     */
    Dataframe *subset(size_t ridx1, size_t ridx2, size_t cidx1, size_t cidx2){}

    /**
     * @brief Get a subset of the Dataframe by the specified start and end row and col indicies
     * 
     * @param ridx1 - beginning row index, inclusive
     * @param ridx2 - end row index, non-inclusive
     * @param cidx1 - beginning col index, inclusive
     * @param cidx2 - end col index, non-inclusive
     * @return Dataframe* 
     */
    Dataframe *subset(const char *ridx1, const char *ridx2, const char *cidx1, const char *cidx2){}

    /**
     * @brief Deletes a row at the specificied index, ridx. All rows under the deleted row will effectively move upwards.
     * 
     * @param size_t - ridx, the row that will deleted (this is the actual index, i.e. 0, 1, etc.)
     */
    void delete_row(size_t ridx){}

    /**
     * @brief Deletes a column at the specified index, cidx. All columns to the right of it will move leftwards. 
     * 
     * @param size_t - cidx, the column that will be deleted (this is the actual index, i.e. 0, 1, etc.)
     */
    void delete_col(size_t cidx){} 

    /**
     * @brief Deletes a row at the specificied index, ridx. All rows under the deleted row will effectively move upwards.
     * 
     * @param ridx - index of the row that will be deleted. This index is by the string name (i.e. 'Mazda RX4')
     */
    void delete_row(const char* ridx){}

    /**
     * @brief Deletes a column at the specified index, cidx. All columns to the right of it will move leftwards. 
     * 
     * @param cidx - index of the column that will be deleted. This index is by the string name (i.e. 'mpg')
     */
    void delete_col(const char* cidx){} 

    /**
     * @brief Renames referrable index of the given row, specified by ridx (the positional index), to the new unique referrable index. 
     * If the given new index, new_ridx, is not unique, the execution will be aborted. 
     * 
     * @param ridx - the positional index (i.e. 0, 1, etc.) of the row to be renamed
     * @param new_ridx - the new referrable index for the row specified by ridx
     */
    void rename_row(size_t ridx, const char* new_ridx){}

    /**
     * @brief Renames referrable index of the given column, specified by cidx (the positional index), to the new unique referrable index. 
     * If the given new index, new_cidx, is not unique, the execution will be aborted. 
     * 
     * @param cidx - the positional index (i.e. 0, 1, etc.) of the column to be renamed
     * @param new_cidx - the new referrable index for the col specified by cidx
     */
    void rename_col(size_t cidx, const char* new_cidx){}

    /**
     * @brief Renames referrable index of the given column, specified by ridx (the referrable index), to the new unique referrable index. 
     * If the given new index, new_ridx, is not unique, the execution will be aborted. 
     * 
     * @param ridx - the referrable index (i.e. 'Mazda RX4') of the row to be renamed
     * @param new_ridx - the new referrable index for the row specified by ridx
     */
    void rename_row(const char* ridx, const char* new_ridx){}

    /**
     * @brief Renames referrable index of the given column, specified by cidx (the referrable index), to the new unique referrable index. 
     * If the given new index, new_cidx, is not unique, the execution will be aborted. 
     * 
     * @param cidx - the referrable index (i.e. 'mpg','hp', etc.) of the column to be renamed
     * @param new_cidx - the new referrable index for the column specified by cidx
     */
    void rename_col(const char* cidx, const char* new_cidx){}

    /**
     * @brief Renames the index column to what is specified by idx_name. If there is overlap between the idx_name and the column names/indexes, 
     * then the executation will be aborted. 
     * 
     * @param idx_name - the new name for the row index
     */
    void rename_idx(const char* idx_name){}
};