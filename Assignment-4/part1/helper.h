//lang::Cpp

#pragma once

#include <iostream>
#include <assert.h>
#include "object.h"

void println(size_t i)
{
    std::cout << i << "\n";
}

void println(const char *m)
{
    std::cout << m << "\n";
}

/*** Object has no print function; this is obsolete right now
void println(Object *o)
{
    std::cout << o->print() << "\n";
}
*/

/* Object has no print function; this is obsolete right now
void println(Object *o, size_t num)
{
    std::cout << o->print() << " " << num << "\n";
}
*/

void print_(const char *m)
{
    std::cout << m;
}

void print_(float f)
{
    std::cout << f;
}

void print_(bool b)
{
    std::cout << b;
}

void print_(int i)
{
    std::cout << i;
}

void print_(size_t i)
{
    std::cout << i;
}
