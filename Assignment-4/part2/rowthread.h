#pragma once
// lang::Cpp

#include "thread.h"
#include "modified_dataframe.h"

/** A Thread wraps the thread operations in the standard library.
 *  author: vitekj@me.com */
class RowThread : public Thread
{
public:
    DataFrame *df_;
    Rower *rower_;
    size_t start_;
    size_t end_;

    RowThread(DataFrame *df, Rower *r, size_t start, size_t end) : Thread()
    {
        df_ = df;
        rower_ = r;
        start_ = start;
        end_ = end;
    }

    /** Subclass responsibility, the body of the run method */
    virtual void run()
    {
    }
};