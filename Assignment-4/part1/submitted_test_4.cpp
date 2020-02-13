// column

#include "dataframe.h"
#include <iostream>

/**
 * @brief Tests the get() function in all FastArrays
 * 
 */
void testGet()
{
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);

    assert(f->get(0) - 4.20 < 0.001 && f->get(0) - 4.20 > -0.001);
    assert(f->get(1) - 4.20 < 0.001 && f->get(1) - 4.20 > -0.001);
    assert(f->get(2) - 4.20 < 0.001 && f->get(2) - 4.20 > -0.001);
    assert(f->get(3) - 4.20 < 0.001 && f->get(3) - 4.20 > -0.001);
}

int main()
{
    testGet();
    return 0;
}