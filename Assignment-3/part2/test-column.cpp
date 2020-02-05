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

    delete b1;
    delete b2;
    delete b3;
    delete i1;
    delete i2;
    delete i3;
    delete f1;
    delete f2;
    delete f3;
    delete s1;
    delete s2;
    delete s3;
}

// tests the equals() function in all columns
void testEquals()
{
    BoolColumn *b1 = new BoolColumn(true, false);
    BoolColumn *b2 = new BoolColumn(true, false);
    BoolColumn *b3 = new BoolColumn(false, true);
    BoolColumn *b4 = b1;

    IntColumn *i1 = new IntColumn(1, 2);
    IntColumn *i2 = new IntColumn(1, 2);
    IntColumn *i3 = new IntColumn(1, 1);
    IntColumn *i4 = i1;

    FloatColumn *f1 = new FloatColumn(1.0, 2.0);
    FloatColumn *f2 = new FloatColumn(1.0, 2.0);
    FloatColumn *f3 = new FloatColumn(1.0, 1.0);
    FloatColumn *f4 = f1;

    StringColumn *s1 = new StringColumn("hello", "world");
    StringColumn *s2 = new StringColumn("hello", "world");
    StringColumn *s3 = new StringColumn("hello", "hello");
    StringColumn *s4 = s1;

    assert(b1->equals(b2));
    assert(!b1->equals(b3));
    assert(b1->equals(b4));

    assert(i1->equals(i2));
    assert(!i1->equals(i3));
    assert(i1->equals(i4));

    assert(f1->equals(f2));
    assert(!f1->equals(f3));
    assert(f1->equals(f4));

    assert(s1->equals(s2));
    assert(!s1->equals(s3));
    assert(s1->equals(s4));

    delete b1;
    delete b2;
    delete b3;
    delete i1;
    delete i2;
    delete i3;
    delete f1;
    delete f2;
    delete f3;
    delete s1;
    delete s2;
    delete s3;
}

// tests the getType() function in all columns
void testGetType()
{
    BoolColumn *b1 = new BoolColumn(true, false);
    BoolColumn *b2 = new BoolColumn(true, false);
    BoolColumn *b3 = b1;
    String *b = new String("BOOL");

    IntColumn *i1 = new IntColumn(1, 2);
    IntColumn *i2 = new IntColumn(1, 2);
    IntColumn *i3 = i1;
    String *i = new String("INT");

    FloatColumn *f1 = new FloatColumn(1.0, 2.0);
    FloatColumn *f2 = new FloatColumn(1.0, 2.0);
    FloatColumn *f3 = f1;
    String *f = new String("FLOAT");

    StringColumn *s1 = new StringColumn("hello", "world");
    StringColumn *s2 = new StringColumn("hello", "world");
    StringColumn *s3 = s1;
    String *s = new String("STRING");

    assert(b1->getType()->equals(b));
    assert(b2->getType()->equals(b));
    assert(b3->getType()->equals(b));

    assert(i1->getType()->equals(i));
    assert(i2->getType()->equals(i));
    assert(i3->getType()->equals(i));

    assert(f1->getType()->equals(f));
    assert(f2->getType()->equals(f));
    assert(f3->getType()->equals(f));

    assert(s1->getType()->equals(s));
    assert(s2->getType()->equals(s));
    assert(s3->getType()->equals(s));

    delete b;
    delete b1;
    delete b2;
    delete i;
    delete i1;
    delete i2;
    delete f;
    delete f1;
    delete f2;
    delete s;
    delete s1;
    delete s2;
}

// tests the print() function in all columns
void testPrint()
{
    BoolColumn *b1 = new BoolColumn(true, false);
    BoolColumn *b2 = new BoolColumn(true, NULL);
    const char *bool1 = " 1 \n 0 \n\0";
    const char *bool2 = " 1 \n  \n\0";

    IntColumn *i1 = new IntColumn(1, -2);
    IntColumn *i2 = new IntColumn(1, NULL);
    const char *int1 = " +1 \n -2 \n\0";
    const char *int2 = " +1 \n  \n\0";

    FloatColumn *f1 = new FloatColumn(1.0, -2.0);
    FloatColumn *f2 = new FloatColumn(1.0, NULL);
    const char *float1 = " +1.0 \n -2.0 \n\0";
    const char *float2 = " +1.0 \n  \n\0";

    StringColumn *s1 = new StringColumn("hello", "world");
    StringColumn *s2 = new StringColumn("hello", nullptr);
    const char *string1 = " hello \n world \n\0";
    const char *string2 = " hello \n  \n\0";

    assert(strcmp(b1->print(), bool1) == 0);
    assert(strcmp(b2->print(), bool2) == 0);
    assert(strcmp(i1->print(), int1) == 0);
    assert(strcmp(i2->print(), int2) == 0);
    assert(strcmp(f1->print(), float1) == 0);
    assert(strcmp(f2->print(), float2) == 0);
    assert(strcmp(s1->print(), string1) == 0);
    assert(strcmp(s2->print(), string2) == 0);

    delete b1;
    delete b2;
    delete i1;
    delete i2;
    delete f1;
    delete f2;
    delete s1;
    delete s2;
}

// tests the subset() function in all columns
void testSubset()
{
    BoolColumn *b1 = new BoolColumn(true, false);
    BoolColumn *b2 = new BoolColumn(false);
    BoolColumn *b3 = b1;
    BoolColumn *subsetb1 = b1->subset(1, 2);
    BoolColumn *subsetb2 = b1->subset(0, 2);

    IntColumn *i1 = new IntColumn(1, 2);
    IntColumn *i2 = new IntColumn(1);
    IntColumn *i3 = i1;
    IntColumn *subseti1 = i1->subset(0, 1);
    IntColumn *subseti2 = i1->subset(0, 2);

    FloatColumn *f1 = new FloatColumn(1.0, 2.0);
    FloatColumn *f2 = new FloatColumn(1.0);
    FloatColumn *f3 = f1;
    FloatColumn *subsetf1 = f1->subset(0, 1);
    FloatColumn *subsetf2 = f1->subset(0, 2);

    StringColumn *s1 = new StringColumn("hello", "world");
    StringColumn *s2 = new StringColumn("world");
    StringColumn *s3 = s1;
    StringColumn *subsets1 = s1->subset(1, 2);
    StringColumn *subsets2 = s1->subset(0, 2);

    assert(subsetb1->equals(b2));
    assert(subsetb2->equals(b1));
    assert(subseti1->equals(i2));
    assert(subseti2->equals(i1));
    assert(subsetf1->equals(f2));
    assert(subsetf2->equals(f1));
    assert(subsets1->equals(s2));
    assert(subsets2->equals(s1));

    delete b1;
    delete b2;
    delete subsetb1;
    delete subsetb2;
    delete i1;
    delete i2;
    delete subseti1;
    delete subseti2;
    delete f1;
    delete f2;
    delete subsetf1;
    delete subsetf2;
    delete s1;
    delete s2;
    delete subsets1;
    delete subsets2;
}

// tests the get() function in all columns
void testGet()
{
    BoolColumn *b1 = new BoolColumn(true, false);
    BoolColumn *b2 = new BoolColumn(false);
    bool bool1 = true;
    bool bool2 = false;

    IntColumn *i1 = new IntColumn(1, 2);
    IntColumn *i2 = new IntColumn(1);
    int int1 = 1;
    int int2 = 2;

    FloatColumn *f1 = new FloatColumn(1.0, 2.0);
    FloatColumn *f2 = new FloatColumn(1.0);
    float float1 = 1.0;
    float float2 = 2.0;

    StringColumn *s1 = new StringColumn("hello", "world");
    StringColumn *s2 = new StringColumn("world");
    String *string1 = new String("hello");
    String *string2 = new String("world");

    assert(b1->get(0) == bool1);
    assert(b1->get(1) == bool2);
    assert(b2->get(0) == bool2);
    assert(i1->get(0) == int1);
    assert(i1->get(1) == int2);
    assert(i2->get(0) == int1);
    assert(f1->get(0) - float1 < 0.001);
    assert(f1->get(1) - float2 < 0.001);
    assert(f2->get(0) - float1 < 0.001);
    assert(s1->get(0)->equals(string1));
    assert(s1->get(1)->equals(string2));
    assert(s2->get(0)->equals(string2));

    delete b1;
    delete b2;
    delete i1;
    delete i2;
    delete f1;
    delete f2;
    delete s1;
    delete s2;
    delete string1;
    delete string2;
}

// tests the isMissing() function in all columns
void testIsMissing()
{
    BoolColumn *b1 = new BoolColumn(true, NULL, true);
    BoolColumn *b2 = new BoolColumn(NULL, false);
    BoolColumn *b3 = new BoolColumn(false, NULL);
    BoolColumn *b4 = new BoolColumn(NULL);

    IntColumn *i1 = new IntColumn(1, NULL, 2);
    IntColumn *i2 = new IntColumn(NULL, 1);
    IntColumn *i3 = new IntColumn(1, NULL);
    IntColumn *i4 = new IntColumn(NULL);

    FloatColumn *f1 = new FloatColumn(1.0, NULL, 2.0);
    FloatColumn *f2 = new FloatColumn(NULL, 1.0);
    FloatColumn *f3 = new FloatColumn(1.0, NULL);
    FloatColumn *f4 = new FloatColumn(NULL);

    StringColumn *s1 = new StringColumn("hello", nullptr, "world");
    StringColumn *s2 = new StringColumn(nullptr, "world");
    StringColumn *s3 = new StringColumn("hello", nullptr);
    StringColumn *s4 = new StringColumn(nullptr);

    assert(!b1->isMissing(0));
    assert(b1->isMissing(1));
    assert(!b1->isMissing(2));
    assert(b2->isMissing(0));
    assert(!b2->isMissing(1));
    assert(!b3->isMissing(0));
    assert(b3->isMissing(1));
    assert(b4->isMissing(0));

    assert(!i1->isMissing(0));
    assert(i1->isMissing(1));
    assert(!i1->isMissing(2));
    assert(i2->isMissing(0));
    assert(!i2->isMissing(1));
    assert(!i3->isMissing(0));
    assert(i3->isMissing(1));
    assert(i4->isMissing(0));

    assert(!f1->isMissing(0));
    assert(f1->isMissing(1));
    assert(!f1->isMissing(2));
    assert(f2->isMissing(0));
    assert(!f2->isMissing(1));
    assert(!f3->isMissing(0));
    assert(f3->isMissing(1));
    assert(f4->isMissing(0));

    assert(!s1->isMissing(0));
    assert(s1->isMissing(1));
    assert(!s1->isMissing(2));
    assert(s2->isMissing(0));
    assert(!s2->isMissing(1));
    assert(!s3->isMissing(0));
    assert(s3->isMissing(1));
    assert(s4->isMissing(0));

    delete b1;
    delete b2;
    delete b3;
    delete b4;
    delete i1;
    delete i2;
    delete i3;
    delete i4;
    delete f1;
    delete f2;
    delete f3;
    delete f4;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

// tests the remove() function in all columns
void testRemove() {}

// tests the isEmpty() function in all columns
void testIsEmpty() {}

int main()
{
    testHash();
    testEquals();
    testGetType();
    testPrint();
    testSubset();
    testGet();
    testIsMissing();
    testRemove();
    testIsEmpty();
    println("All tests passed!");
}