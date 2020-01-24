#pragma once

#include "object.h"
#include "helper.h"
#include <stdlib.h>

class Boolean : public Object
{
public:
    bool boolean_;

    Boolean(bool boolean) : Object()
    {
        boolean_ = boolean;
    }

    ~Boolean()
    {
    }

    bool equals(Object *other)
    {
        Boolean *other1 = dynamic_cast<Boolean *>(other);
        if (other1 == nullptr)
            return false;
        return other1->boolean_ == boolean_;
    }

    const char *print()
    {
        return (char *)boolean_;
    }
};

class Integer : public Object
{
public:
    int integer_;

    Integer(int integer) : Object()
    {
        integer_ = integer;
    }

    ~Integer() {}

    bool equals(Object *other)
    {
        Integer *other1 = dynamic_cast<Integer *>(other);
        if (other1 == nullptr)
            return false;
        return other1->integer_ == integer_;
    }

    const char *print()
    {
        std::string s = std::to_string(integer_);
        char const *res = s.c_str();
        return res;
    }
};

class Float : public Object
{
public:
    float float_;

    Float(float flt) : Object()
    {
        float_ = flt;
    }

    ~Float() {}

    bool equals(Object *other)
    {
        Float *other1 = dynamic_cast<Float *>(other);
        if (other1 == nullptr)
            return false;
        return other1->float_ == float_;
    }

    // I learned how to convert floats to char* using C++ strings here:
    // https://stackoverflow.com/questions/10847237/how-to-convert-from-int-to-char
    const char *print()
    {
        std::string s = std::to_string(float_);
        char const *res = s.c_str();
        return res;
    }
};