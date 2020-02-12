//lang:Cwc

#include "column.h"

#pragma once
/*************************************************************************
 * Schema::
 * A schema is a description of the contents of a data frame, the schema
 * knows the number of columns and number of rows, the type of each column,
 * optionally columns and rows can be named by strings.
 * The valid types are represented by the chars 'S', 'B', 'I' and 'F'.
 */
class Schema : public Object
{
public:
    StrBuff *coltypes_;
    StringFastArray *row_names_;
    StringFastArray *col_names_;

    /** Copying constructor */
    Schema(Schema &from)
    {
        coltypes_ = from.coltypes_;
        row_names_ = from.row_names_;
        col_names_ = from.col_names_;
    }

    /** Create an empty schema **/
    Schema()
    {
        coltypes_ = new StrBuff();
        row_names_ = new StringFastArray();
        col_names_ = new StringFastArray();
    }

    ~Schema()
    {
        delete row_names_;
        delete col_names_;
    }

    /** Create a schema from a string of types. A string that contains
    * characters other than those identifying the four type results in
    * undefined behavior. The argument is external, a nullptr argument is
    * undefined. **/
    Schema(const char *types)
    {
        coltypes_ = new StrBuff();
        coltypes_->c(types);
        row_names_ = new StringFastArray();
        col_names_ = new StringFastArray();
        for (int i = 0; i < strlen(types); i++)
        {
            col_names_->push_back(nullptr);
        }
    }

    /** Add a column of the given type and name (can be nullptr), name
    * is external. Names are expectd to be unique, duplicates result
    * in undefined behavior. */
    void add_column(char typ, String *name)
    {
        coltypes_->c(typ);
        col_names_->push_back(name);
    }

    /** Add a row with a name (possibly nullptr), name is external.  Names are
   *  expectd to be unique, duplicates result in undefined behavior. */
    void add_row(String *name)
    {
        row_names_->push_back(name);
    }

    /** Return name of row at idx; nullptr indicates no name. An idx >= width
    * is undefined. */
    String *row_name(size_t idx)
    {
        row_names_->get(idx);
    }

    /** Return name of column at idx; nullptr indicates no name given.
    *  An idx >= width is undefined.*/
    String *col_name(size_t idx)
    {
        col_names_->get(idx);
    }

    /** Return type of column at idx. An idx >= width is undefined. */
    char col_type(size_t idx)
    {
        String *types_str = coltypes_->get();
        char res = types_str->at(idx);
        coltypes_->c(types_str->steal());
        delete types_str;
        return res;
    }

    /** Given a column name return its index, or -1. */
    int col_idx(const char *name)
    {
        assert(name != nullptr);
        String *name_str = new String(name);
        for (int i = 0; i < col_names_->size(); i++)
        {
            if (col_names_->get(i) != nullptr && col_names_->get(i)->equals(name_str))
            {
                delete name_str;
                return i;
            }
        }
        delete name_str;
        return -1;
    }

    /** Given a row name return its index, or -1. */
    int row_idx(const char *name)
    {
        assert(name != nullptr);
        String *name_str = new String(name);
        for (int i = 0; i < row_names_->size(); i++)
        {
            if (row_names_->get(i) != nullptr && row_names_->get(i)->equals(name_str))
            {
                delete name_str;
                return i;
            }
        }
        delete name_str;
        return -1;
    }

    /** The number of columns */
    size_t width()
    {
        col_names_->size();
    }

    /** The number of rows */
    size_t length()
    {
        row_names_->size();
    }
};