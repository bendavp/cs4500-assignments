#include "column.h"
#include "assert.h"
#include "helper.h"

// tests the hash() function in all columns
void testHash()
{
    BoolColumn *b1 = new BoolColumn(true, false);
    BoolColumn *b2 = new BoolColumn(true, false);
    BoolColumn *b3 = new BoolColumn(false, true);

    IntColumn *i1 = new IntColumn(1, 2);
    IntColumn *i2 = new IntColumn(1, 2);
    IntColumn *i3 = new IntColumn(1, 1);

    FloatColumn *f1 = new FloatColumn(1.0, 2.0);
    FloatColumn *f2 = new FloatColumn(1.0, 2.0);
    FloatColumn *f3 = new FloatColumn(1.0, 1.0);

    StringColumn *s1 = new StringColumn("hello", "world");
    StringColumn *s2 = new StringColumn("hello", "world");
    StringColumn *s3 = new StringColumn("hello", "hello");

    assert(b1->hash() == b2->hash());
    assert(b1->hash() != b3->hash());

    assert(i1->hash() == i2->hash());
    assert(i1->hash() != i3->hash());

    assert(f1->hash() == f2->hash());
    assert(f1->hash() != f3->hash());

    assert(s1->hash() == s2->hash());
    assert(s1->hash() != s3->hash());
}

// tests the equals() function in all columns
void testEquals()
{
}

// tests the getType() function in all columns
void testGetType()
{
}

// tests the print() function in all columns
void testPrint()
{
}

// tests the subset() function in all columns
void testSubset()
{
}

// tests the get() function in all columns
void testGet()
{
}

// tests the isMissing() function in all columns
void testIsMissing()
{
}

int main()
{
    testHash();
    testEquals();
    testGetType();
    testPrint();
    testSubset();
    testGet();
    testIsMissing();
    println("All tests passed!");
}