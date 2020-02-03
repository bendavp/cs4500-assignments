#include "object.h"
#include "string.h"

#pragma once

class Dataframe : public Object {
public:
// absolutely need to include
    void* get(size_t ridx, size_t cidx) {} // return type??? abstraction for returning multiple types?
    void* get(const char* ridx, const char* cidx) {} // return type??? abstraction for returning multiple types?
    size_t nrow(){}
    size_t ncol(){}
    bool append(void*){} // return type??? bool (true/false for success/unsuccess) or void; how to enter a row
    bool insert(void*){} // return type??? bool (true/false for success/unsuccess) or void; how to enter a col
    const char *print(){}
    bool equals(){}
    size_t hash(){}
    String** col_names(){}
    String** row_names(){}
    // need to include copy constructor
    
    // bonus 
    size_t *shape(){}
    size_t size(){}
    void empty(){}
    void clear(){}
    const char *head(){}
    Dataframe *subset(void* what){} // need to chose signature
    const char *dtypes(){} // return type??? -> how do we want to output different data types?
    void delete_col(size_t cidx){} // return type??? bool (true/false for success/unsuccess) or void; should we duplicate to delete via String/size_t idx
    void delete_row(size_t ridx){} // return type??? bool (true/false for success/unsuccess) or void; should we duplicate to delete via String/size_t idx
    Dataframe *filter(void* what){}  // need to chose signature
    void rename_row(size_t ridx){}
    void rename_col(size_t cidx){}
    void rename_row(const char* ridx){}
    void rename_col(const char* cidx){}
};