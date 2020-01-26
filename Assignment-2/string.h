//lang::CwC

#pragma once

#include "object.h"
#include <string.h>

/**
 * @brief String class. _Some of_ this code was produced by following along with Prof. Vesely in class on Friday, January 10th, 2019.
 * The rest is original -- including concat(), print(), and compareTo(). 
 */
class String : public Object
{
public:
    char *str_;
    size_t size_;

    /**
     * @brief Construct a new String object
     * 
     * @param str 
     */
    String(const char *str) : Object()
    {
        size_ = strlen(str);

        str_ = new char[size_ + 1];

        strcpy(str_, str);
    }

    ~String()
    {
        delete[] str_;
    }

    size_t length()
    {
        return size_;
    }

    size_t hash_me()
    {
        size_t res = 0;
        for (int i = 0; i < size_; i++)
        {
            res += str_[i];
        }
        return res;
    }

    bool equals(Object *other)
    {
        // String *other1 = static_cast<String *>(other);
        // use dynamic cast b/c if it cannot cast to string, then it will return a nullptr
        String *other1 = dynamic_cast<String *>(other);
        if (other1 == nullptr)
            return false;
        return !strcmp(this->str_, other1->str_);
    }

    String *concat(String *other)
    {
        size_t new_size_ = size_ + other->size_;
        char *new_str_ = new char[new_size_ + 1];
        for (int i = 0; i < size_ + 1; i++)
        {
            new_str_[i] = str_[i];
        }
        for (int i = size_; i < new_size_ + 1; i++)
        {
            new_str_[i] = other->str_[i - size_];
        }
        return new String(const_cast<char *>(new_str_));
    }

    // returns what to print
    const char *print()
    {
        return str_;
    }

    /**
     * @brief Compares this string to the given string alphabetically.
     * 
     * @param other the given string to compare to this
     * @return int -1 if the given string is earlier alphabetically, 0 if the strings are the same, 1 if the given string is later alphabetically than this string.
     */
    int compareTo(String *other)
    {
        size_t minSize = size_;
        if (other->size_ < size_)
        {
            minSize = other->size_;
        }

        if (other == nullptr)
        {
            return -1;
        }

        if (this->equals(other))
        {
            return 0;
        }

        for (int i = 0; i < minSize; i++)
        {
            if (str_[i] == other->str_[i])
            {
                continue;
            }
            else
            {
                if (str_[i] < other->str_[i])
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
        }

        if (size_ < other->size_)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    // appends ONE character to the String
    void append(char other)
    {
        // store the current contents in another array
        char *new_str = new char[size_ + 2];
        strcpy(new_str, str_);
        new_str[size_] = other;
        new_str[size_ + 1] = '\0';

        delete[] str_;
        str_ = new_str;

        // update the size of the current string
        size_++;
    }

    size_t size()
    {
        return size_;
    }
};