//lang::CwC

#pragma once // indicates that this file is to be included only once

#include <stdio.h>

/**
 * @brief Object class. _Some of_ this code was produced by following along with Prof. Vesely in class on Friday, January 10th, 2019.
 * The rest is original -- including print()
 */
class Object
{
public:
    size_t hash_; // hash cache

    Object() { hash_ = 0; }

    // destructor
    virtual ~Object() {}

    virtual bool equals(Object *other)
    {
        return this == other;
    }

    // returns the hash code value for this object
    size_t hash()
    {
        if (hash_ == 0)
        {
            hash_ = hash_me();
        }

        return hash_;
    }

    // virtual is to indicate that this method may be overridden
    virtual size_t hash_me()
    {
        return reinterpret_cast<size_t>(this);
    }

    // returns what to print
    virtual const char *print()
    {
        return (char *)hash_;
    }
};