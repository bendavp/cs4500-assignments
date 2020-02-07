//lang::CwC

#include "column.h"
#include "array.h"

#pragma once

/**
 * @brief Dataframe object which is comprised of Columns.
 * 
 * @author Amy Tang - tang.amy@husky.neu.edu
 * @author Benjamin Kosiborod - kosiborod.b@husky.neu.edu
 * 
 */
class Dataframe : public Object
{
public:
    /**
     * @brief Construct a new Dataframe object
     * 
     */
    Dataframe() : Object() {}

    /**
     * @brief Construct a new Dataframe object
     * 
     * @param n number of arguments including this one
     * @param ... Columns that will be taken in
     */
    Dataframe(size_t n, ...) : Object() {}

    /**
     * @brief Construct a new Dataframe object. Copy construcor
     * 
     * @param df - the dataframe to be copied
     */
    Dataframe(Dataframe *df) : Object() {}

    /**
     * @brief Destroy the Dataframe object
     * 
     */
    ~Dataframe() {}

    /**
     * @brief gets an int from a specific cell in the dataframe
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - row index given as a size_t
     * @return int or aborts execution if the column pulled from is not an IntColumn
     */
    int *getInt(size_t ridx, size_t cidx) {}

    /**
     * @brief gets an int from a specific cell in the dataframe
     * 
     * @param ridx - row index given as the name of the row (could be an int)
     * @param cidx - col index given as the name of the col (could be an int)
     * @return int or aborts execution if the column pulled from is not an IntColumn
     */
    int *getInt(String *ridx, String *cidx) {}

    /**
     * @brief gets an float from a specific cell in the dataframe
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @return float or aborts execution if the column pulled from is not a FloatColumn
     */
    float *getFloat(size_t ridx, size_t cidx) {}

    /**
     * @brief gets an float from a specific cell in the dataframe
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @return float or aborts execution if the column pulled from is not a FloatColumn
     */
    float *getFloat(String *ridx, String *cidx) {}

    /**
     * @brief gets a bool from a specific cell in the dataframe
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @return true if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     * @return false if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     */
    bool *getBool(size_t ridx, size_t cidx) {}

    /**
     * @brief gets a bool from a specific cell in the dataframe
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @return true if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     * @return false if bool value pulled is true; aborts execution if the column pulled from is not a BoolColumn
     */
    bool *getBool(String *ridx, String *cidx) {}

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
    String *getString(String *ridx, String *cidx) {}

    /**
     * @brief Sets the specified cell in the dataframe to be an int. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - row index given as a size_t
     * @param i - the int that the specified cell will be set to
     */
    void setInt(size_t ridx, size_t cidx, int *i) {}

    /**
     * @brief Sets the specified cell in the dataframe to be an int. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as the name of the row (could be an int)
     * @param cidx - col index given as the name of the col (could be an int)
     * @param i - the int that the specified cell will be set to
     */
    void setInt(String *ridx, String *cidx, int *i) {}

    /**
     * @brief Sets the specified cell in the dataframe to be an float. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @param f - the float that the specified cell will be set to
     */
    void setFloat(size_t ridx, size_t cidx, float *f) {}

    /**
     * @brief Sets the specified cell in the dataframe to be an float. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @param f - the float that the specified cell will be set to
     */
    void setFloat(String *ridx, String *cidx, float *f) {}

    /**
     * @brief Sets the specified cell in the dataframe to be a bool. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @param b - the bool that the specified cell will be set to
     */
    void setBool(size_t ridx, size_t cidx, bool *b) {}

    /**
     * @brief Sets the specified cell in the dataframe to be a bool. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @param b - the bool that the specified cell will be set to
     */
    void setBool(String *ridx, String *cidx, bool *b) {}

    /**
     * @brief Sets the specified cell in the dataframe to be a String. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as a size_t
     * @param cidx - col index given as a size_t
     * @param s - the String that the specified cell will be set to
     */
    void setString(size_t ridx, size_t cidx, String *s) {}

    /**
     * @brief Sets the specified cell in the dataframe to be a String. The column type that the cell is in must already by an int or
     * the execution wil be aborted.
     * 
     * @param ridx - row index given as the name of the row
     * @param cidx - col index given as the name of the col
     * @param s - the String that the specified cell will be set to
     */
    void setString(String *ridx, String *cidx, String *s) {}

    /**
     * @brief returns the total number of rows (not including headers) of the dataframe
     * 
     * @return size_t - num of rows
     */
    size_t nrow() {}

    /**
     * @brief returns the total number of columns (not including headers) of the dataframe
     * 
     * @return size_t - num of cols
     */
    size_t ncol() {}

    /**
     * @brief Appends a row of columns to the end of the dataframe (most bottom). If the columns being added to an
     * non-empty dataframe are not of the same type as the existing or there is number, then the execution will be aborted. 
     * 
     * @param n number of arguments (i.e. columns that will be appended)
     * @param ... - va_list of columns to be appended
     */
    void append(size_t n, ...) {}

    /**
     * @brief Appends a row of columns at the row of the specified index, ridx. The rows under the specified index will be pushed
     * downwards. If the columns being added to an non-empty dataframe are not of the same type as the existing or there is 
     * number, then the execution will be aborted. 
     * 
     * @param ridx - the row index that the columns will be appended to. 
     * @param n - number of columns to be appended/arguments of the va_list + 1 (includes this argument)
     * @param ... - va_list of columns to be appended
     */
    void appendAt(size_t ridx, int n, ...) {}

    /**
     * @brief adds a Column to the end (most right side) of the dataframe. Aborts execution if column does not fit the shape
     * of the existing dataframe and the dataframe is not empty. 
     * 
     * @param col - Column to be inserted
     */
    void insertCol(Column *col) {}

    /**
     * @brief adds a Column at the index specified by cidx. Aborts execution if column does not fit the shape
     * of the existing dataframe and the dataframe is not empty. 
     * 
     * @param cidx - the index to insert at
     * @param col - the Column to be inserted
     */
    void insertColAt(size_t cidx, Column *col) {}

    /**
     * @brief prints out the dataframe in the shape of the dataframe; separating columns via tab-delimited format to keep
     * the dataframe readable
     * 
     * @return const char* - prints out the dataframe
     */
    const char *print() {}

    /**
     * @brief returns bool signifying if the dataframe is equivalent to the object passed in.
     * 
     * @return true - if this dataframe is the same shape and has all of the same values/headers 
     * as the objective passed in assuming the objective is a dataframe
     * @return false - if objective passed in is not a dataframe or if this dataframe is not the same shape or 
     * contains different values/headers compared to the dataframe passed in
     */
    bool equals(Object *o) {}

    /**
     * @brief calculates and returns a hash of the dataframe
     * 
     * @return size_t - hash value of this dataframe
     */
    size_t hash() {}

    /**
     * @brief gets the names of the indices which the rows can be referred to as and returns them to the user as an String array. 
     * If the user has not entered any specific indicies such as ('Mazda RX4', 'Datsun 710') to be the row names, the automatic indexing
     * names will be returned ('0', '1', etc.) or a mix of these ('0', 'Mazda RX4', '2', etc.)
     * 
     * @return StringArray * - a String array of the names of the row names
     */
    StringArray *getRowNames() {}

    /**
     * @brief gets the names of the indices which the rows can be referred to as and returns them to the user as an String array. 
     * If the user has not entered any specific indicies such as ('mpg', 'hp') to be the row names, the automatic indexing
     * names will be returned ('0', '1', etc.) or a mix of these ('0', 'mpg', '2', etc.)
     * 
     * @return String** - a String array of the names of the col names
     */
    StringArray *getColNames() {}

    /**
     * @brief returns in String array, written in plain english, that specifies the type (Int, Bool, etc) of the columns
     * 
     * @return StringArray* - a String array, specifying in english (Int, Bool, etc), the type of the col types
     */
    StringArray *dTypes() {}

    /**
     * @brief returns, in plain english via a String, the type of the specified column (specified by cidx, which represents 
     * the numerical index of the column)
     * 
     * @param cidx - the column via its referrable index
     * @return String* - String denoting the column type
     */
    String *getColType(size_t cidx) {}

    /**
     * @brief returns, in plain english via a String, the type of the specified column (specified by cidx, which represents 
     * the name of the column i.e. 'mpg' or '1')
     * 
     * @param cidx - the column via its referrable index
     * @return String* - String denoting the column type
     */
    String *getColType(String *cidx) {}

    /**
     * @brief Returns the shape of the dataframe. For example, if the dataframe has 3 rows and 2 columns, this will return 
     * an 2-length array [3,2] where the array is of the format [num_row, num_cols]. 
     * 
     * @return IntArray * - returns shape of the dataframe in the format of a IntArray
     */
    IntArray *shape() {}

    /**
     * @brief Returns the total number of cells of the dataframe has which can be calculated by num_row X num-col
     * 
     * @return size_t - returns the cells in the dataframe
     */
    size_t size() {}

    /**
     * @brief checks if the dataframe is empty (i.e. no columns (so also effectively no rows))
     * 
     * @return true - if the dataframe is empty (no columns/rows)
     * @return false - if the dataframe is not empty (has at least one column/row)
     */
    bool empty() {}

    /**
     * @brief clears the dataframe of all col/rows and deletes the objects inside
     * 
     */
    void clear() {}

    /**
     * @brief prints out the first 6 rows of the dataframe in the shape of the dataframe; separating columns via tab-delimited format to keep
     * the dataframe readable
     * 
     * @return const char* - prints out the first 6 rows of the dataframe
     */
    const char *head() {}

    /**
     * @brief Get a subset of the Dataframe by the specified start and end row and col indicies
     * 
     * @param ridx1 - beginning row index, inclusive
     * @param ridx2 - end row index, non-inclusive
     * @param cidx1 - beginning col index, inclusive
     * @param cidx2 - end col index, non-inclusive
     *
     * @return Dataframe* that is a subset of this dataframe with the specifications
     */
    Dataframe *subset(size_t ridx1, size_t ridx2, size_t cidx1, size_t cidx2) {}

    /**
     * @brief Deletes a row at the specificied index, ridx. All rows under the deleted row will effectively move upwards.
     * 
     * @param ridx - ridx, the row that will deleted (this is the actual index, i.e. 0, 1, etc.)
     */
    void delete_row(size_t ridx) {}

    /**
     * @brief Deletes a column at the specified index, cidx. All columns to the right of it will move leftwards. 
     * 
     * @param cidx - cidx, the column that will be deleted (this is the actual index, i.e. 0, 1, etc.)
     */
    void delete_col(size_t cidx) {}

    /**
     * @brief Deletes a row at the specificied index, ridx. All rows under the deleted row will effectively move upwards.
     * 
     * @param ridx - index of the row that will be deleted. This index is by the string name (i.e. 'Mazda RX4')
     */
    void delete_row(String *ridx) {}

    /**
     * @brief Deletes a column at the specified index, cidx. All columns to the right of it will move leftwards. 
     * 
     * @param cidx - index of the column that will be deleted. This index is by the string name (i.e. 'mpg')
     */
    void delete_col(String *cidx) {}

    /**
     * @brief Renames referrable index of the given row, specified by ridx (the positional index), to the new unique referrable index. 
     * If the given new index, new_ridx, is not unique, the execution will be aborted. 
     * 
     * @param ridx - the positional index (i.e. 0, 1, etc.) of the row to be renamed
     * @param new_ridx - the new referrable index for the row specified by ridx
     */
    void rename_row(size_t ridx, String *new_ridx) {}

    /**
     * @brief Renames referrable index of the given column, specified by cidx (the positional index), to the new unique referrable index. 
     * If the given new index, new_cidx, is not unique, the execution will be aborted. 
     * 
     * @param cidx - the positional index (i.e. 0, 1, etc.) of the column to be renamed
     * @param new_cidx - the new referrable index for the col specified by cidx
     */
    void rename_col(size_t cidx, String *new_cidx) {}
};