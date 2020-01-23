#pragma once

#include "object.h"
#include "helper.h"

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
        return (char *)integer_;
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

    // I learned how to convert floats to char* with the asprintf function here:
    // https://stackoverflow.com/questions/2988791/converting-float-to-char and here:
    // http://crasseux.com/books/ctutorial/asprintf.html
    const char *print()
    {
        char *res = NULL;
        int len = asprintf(&res, "%g", float_);
        if (len == -1)
        {
            print_("Error converting float: ");
            print_(float_);
            exit(1);
        }
        return res;
    }
};