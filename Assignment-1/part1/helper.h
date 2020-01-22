//lang::Cpp

#pragma once

#include <iostream>
#include "object.h"

void println(size_t i)
{
    std::cout << i << "\n";
}

void println(const char *m)
{
    std::cout << m << "\n";
}

void println(Object *o)
{
    std::cout << o->print() << "\n";
}

void println(Object *o, size_t num)
{
    std::cout << o->print() << " " << num << "\n";
}

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
