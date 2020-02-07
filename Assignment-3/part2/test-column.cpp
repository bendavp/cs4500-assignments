#include "column.h"
#include "assert.h"
#include "helper.h"

// tests the hash() function in all columns
void testHash()
{
    BoolColumn *b1 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b2 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b3 = new BoolColumn(2, new bool(false), new bool(true));

    IntColumn *i1 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i2 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i3 = new IntColumn(2, new int(1), new int(1));

    FloatColumn *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f2 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f3 = new FloatColumn(2, new float(1.0), new float(1.0));

    StringColumn *s1 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s2 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s3 = new StringColumn(2, new String("world"), new String("hello"));

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
    BoolColumn *b1 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b2 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b3 = new BoolColumn(2, new bool(false), new bool(true));
    BoolColumn *b4 = b1;

    IntColumn *i1 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i2 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i3 = new IntColumn(2, new int(1), new int(1));
    IntColumn *i4 = i1;

    FloatColumn *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f2 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f3 = new FloatColumn(2, new float(1.0), new float(1.0));
    FloatColumn *f4 = f1;

    StringColumn *s1 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s2 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s3 = new StringColumn(2, new String("hello"), new String("hello"));
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
    BoolColumn *b1 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b2 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b3 = b1;
    String *b = new String("BOOL");

    IntColumn *i1 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i2 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i3 = i1;
    String *i = new String("INT");

    FloatColumn *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f2 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f3 = f1;
    String *f = new String("FLOAT");

    StringColumn *s1 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s2 = new StringColumn(2, new String("hello"), new String("world"));
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
    BoolColumn *b1 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b2 = new BoolColumn(2, new bool(true), nullptr);
    const char *bool1 = " 1 \n 0 \n\0";
    const char *bool2 = " 1 \n - \n\0";

    IntColumn *i1 = new IntColumn(2, new int(1), new int(-2));
    IntColumn *i2 = new IntColumn(2, new int(1), nullptr);
    const char *int1 = " +1 \n -2 \n\0";
    const char *int2 = " +1 \n - \n\0";

    FloatColumn *f1 = new FloatColumn(2, new float(1.0), new float(-2.0));
    FloatColumn *f2 = new FloatColumn(2, new float(1.0), nullptr);
    const char *float1 = " +1.0 \n -2.0 \n\0";
    const char *float2 = " +1.0 \n - \n\0";

    StringColumn *s1 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s2 = new StringColumn(2, new String("hello"), nullptr);
    const char *string1 = " hello \n world \n\0";
    const char *string2 = " hello \n - \n\0";

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
    delete bool1;
    delete bool2;
    delete i1;
    delete i2;
    delete int1;
    delete int2;
    delete f1;
    delete f2;
    delete float1;
    delete float2;
    delete s1;
    delete s2;
    delete string1;
    delete string2;
}

// tests the subset() function in all columns
void testSubset()
{
    BoolColumn *b1 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b2 = new BoolColumn(1, new bool(false));
    BoolColumn *b3 = b1;
    BoolColumn *subsetb1 = b1->subset(1, 2);
    BoolColumn *subsetb2 = b1->subset(0, 2);

    IntColumn *i1 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i2 = new IntColumn(1, new int(1));
    IntColumn *i3 = i1;
    IntColumn *subseti1 = i1->subset(0, 1);
    IntColumn *subseti2 = i1->subset(0, 2);

    FloatColumn *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f2 = new FloatColumn(1, new float(1.0));
    FloatColumn *f3 = f1;
    FloatColumn *subsetf1 = f1->subset(0, 1);
    FloatColumn *subsetf2 = f1->subset(0, 2);

    StringColumn *s1 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s2 = new StringColumn(1, new String("world"));
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
    BoolColumn *b1 = new BoolColumn(2, new bool(true), new bool(false));
    BoolColumn *b2 = new BoolColumn(1, new bool(false));
    bool bool1 = true;
    bool bool2 = false;

    IntColumn *i1 = new IntColumn(2, new int(1), new int(2));
    IntColumn *i2 = new IntColumn(1, new int(1));
    int int1 = 1;
    int int2 = 2;

    FloatColumn *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    FloatColumn *f2 = new FloatColumn(1, new float(1.0));
    float float1 = 1.0;
    float float2 = 2.0;

    StringColumn *s1 = new StringColumn(2, new String("hello"), new String("world"));
    StringColumn *s2 = new StringColumn(1, new String("world"));
    String *string1 = new String("hello");
    String *string2 = new String("world");

    assert(*b1->get(0) == bool1);
    assert(*b1->get(1) == bool2);
    assert(*b2->get(0) == bool2);
    assert(*i1->get(0) == int1);
    assert(*i1->get(1) == int2);
    assert(*i2->get(0) == int1);
    assert(*f1->get(0) - float1 < 0.001);
    assert(*f1->get(1) - float2 < 0.001);
    assert(*f2->get(0) - float1 < 0.001);
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
    BoolColumn *b1 = new BoolColumn(3, new bool(true), nullptr, new bool(true));
    BoolColumn *b2 = new BoolColumn(2, nullptr, new bool(false));
    BoolColumn *b3 = new BoolColumn(2, new bool(false), nullptr);
    BoolColumn *b4 = new BoolColumn(1, nullptr);

    IntColumn *i1 = new IntColumn(3, new int(1), nullptr, new int(2));
    IntColumn *i2 = new IntColumn(2, nullptr, new int(1));
    IntColumn *i3 = new IntColumn(2, new int(1), nullptr);
    IntColumn *i4 = new IntColumn(1, nullptr);

    FloatColumn *f1 = new FloatColumn(3, new float(1.0), nullptr, new float(2.0));
    FloatColumn *f2 = new FloatColumn(2, nullptr, new float(1.0));
    FloatColumn *f3 = new FloatColumn(2, new float(1.0), nullptr);
    FloatColumn *f4 = new FloatColumn(1, nullptr);

    StringColumn *s1 = new StringColumn(3, new String("hello"), nullptr, new String("world"));
    StringColumn *s2 = new StringColumn(2, nullptr, new String("world"));
    StringColumn *s3 = new StringColumn(2, new String("hello"), nullptr);
    StringColumn *s4 = new StringColumn(1, nullptr);

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
void testRemove()
{
    BoolColumn *b1 = new BoolColumn(3, new bool(true), new bool(true), new bool(false));
    BoolColumn *b1_after = new BoolColumn(2, new bool(true), new bool(false));
    b1->remove(0);
    assert(b1->size() == 2);
    assert(b1->equals(b1_after));

    BoolColumn *b2 = new BoolColumn(3, new bool(true), new bool(true), new bool(false));
    BoolColumn *b2_after = new BoolColumn(2, new bool(true), new bool(false));
    b2->remove(1);
    assert(b2->size() == 2);
    assert(b2->equals(b2_after));

    BoolColumn *b3 = new BoolColumn(3, new bool(true), new bool(true), new bool(false));
    BoolColumn *b3_after = new BoolColumn(2, new bool(true), new bool(true));
    b3->remove(2);
    assert(b3->size() == 2);
    assert(b3->equals(b3_after));

    BoolColumn *b4 = new BoolColumn(3, nullptr, new bool(true), new bool(false));
    BoolColumn *b4_after = new BoolColumn(2, new bool(true), new bool(false));
    b4->remove(0);
    assert(b4->size() == 2);
    assert(b4->equals(b4_after));

    BoolColumn *b5 = new BoolColumn(3, new bool(true), nullptr, new bool(false));
    BoolColumn *b5_after = new BoolColumn(3, new bool(true), new bool(false));
    b5->remove(1);
    assert(b5->size() == 2);
    assert(b5->equals(b5_after));

    BoolColumn *b6 = new BoolColumn(3, new bool(true), new bool(true), nullptr);
    BoolColumn *b6_after = new BoolColumn(3, new bool(true), nullptr, new bool(true));
    b6->remove(2);
    assert(b1->size() == 2);
    assert(b1->equals(b6_after));

    BoolColumn *b7 = new BoolColumn(1, new bool(false));
    BoolColumn *b7_after = new BoolColumn(0);
    b7->remove(0);
    assert(b7->size() == 0);
    assert(b7->equals(b7_after));

    BoolColumn *b8 = new BoolColumn(1, nullptr);
    BoolColumn *b8_after = new BoolColumn(0);
    b8->remove(0);
    assert(b8->size() == 0);
    assert(b8->equals(b8_after));

    delete b1;
    delete b1_after;
    delete b2;
    delete b2_after;
    delete b3;
    delete b3_after;
    delete b4;
    delete b4_after;
    delete b5;
    delete b5_after;
    delete b6;
    delete b6_after;
    delete b7;
    delete b7_after;
    delete b8;
    delete b8_after;

    IntColumn *i1 = new IntColumn(3, new int(1), new int(2), new int(3));
    IntColumn *i1_after = new IntColumn(2, new int(2), new int(3));
    i1->remove(0);
    assert(i1->size() == 2);
    assert(i1->equals(i1_after));

    IntColumn *i2 = new IntColumn(3, new int(1), new int(2), new int(3));
    IntColumn *i2_after = new IntColumn(2, new int(1), new int(3));
    i2->remove(1);
    assert(i2->size() == 2);
    assert(i2->equals(i2_after));

    IntColumn *i3 = new IntColumn(3, new int(1), new int(2), new int(3));
    IntColumn *i3_after = new IntColumn(2, new int(1), new int(2));
    i3->remove(2);
    assert(i3->size() == 2);
    assert(i3->equals(i3_after));

    IntColumn *i4 = new IntColumn(3, nullptr, new int(2), new int(3));
    IntColumn *i4_after = new IntColumn(2, new int(2), new int(3));
    i4->remove(0);
    assert(i4->size() == 2);
    assert(i4->equals(i4_after));

    IntColumn *i5 = new IntColumn(3, new int(1), nullptr, new int(3));
    IntColumn *i5_after = new IntColumn(2, new int(1), new int(3));
    i5->remove(1);
    assert(i5->size() == 2);
    assert(i5->equals(i5_after));

    IntColumn *i6 = new IntColumn(3, new int(1), new int(2), nullptr);
    IntColumn *i6_after = new IntColumn(2, new int(1), new int(2));
    i6->remove(2);
    assert(i1->size() == 2);
    assert(i1->equals(i6_after));

    IntColumn *i7 = new IntColumn(1, new int(1));
    IntColumn *i7_after = new IntColumn(0);
    i7->remove(0);
    assert(i7->size() == 0);
    assert(i7->equals(i7_after));

    IntColumn *i8 = new IntColumn(1, nullptr);
    IntColumn *i8_after = new IntColumn(0);
    i8->remove(0);
    assert(i8->size() == 0);
    assert(i8->equals(i8_after));

    delete i1;
    delete i1_after;
    delete i2;
    delete i2_after;
    delete i3;
    delete i3_after;
    delete i4;
    delete i4_after;
    delete i5;
    delete i5_after;
    delete i6;
    delete i6_after;
    delete i7;
    delete i7_after;
    delete i8;
    delete i8_after;

    FloatColumn *f1 = new FloatColumn(3, new float(1.0), new float(2.0), new float(3.0));
    FloatColumn *f1_after = new FloatColumn(2, new float(2.0), new float(3.0));
    f1->remove(0);
    assert(f1->size() == 2);
    assert(f1->equals(f1_after));

    FloatColumn *f2 = new FloatColumn(3, new float(1.0), new float(2.0), new float(3.0));
    IntColumn *f2_after = new IntColumn(2, new float(1.0), new float(3.0));
    f2->remove(1);
    assert(f2->size() == 2);
    assert(f2->equals(f2_after));

    FloatColumn *f3 = new FloatColumn(3, new float(1.0), new float(2.0), new float(3.0));
    FloatColumn *f3_after = new FloatColumn(2, new float(1.0), new float(2.0));
    f3->remove(2);
    assert(f3->size() == 2);
    assert(f3->equals(f3_after));

    FloatColumn *f4 = new FloatColumn(3, nullptr, new float(2.0), new float(3.0));
    FloatColumn *f4_after = new FloatColumn(2, new float(2.0), new float(3.0));
    f4->remove(0);
    assert(f4->size() == 2);
    assert(f4->equals(f4_after));

    FloatColumn *f5 = new FloatColumn(3, new float(1.0), nullptr, new float(3.0));
    IntColumn *f5_after = new IntColumn(2, new float(1.0), new float(3.0));
    f5->remove(1);
    assert(f5->size() == 2);
    assert(f5->equals(f5_after));

    FloatColumn *f6 = new FloatColumn(3, new float(1.0), new float(2.0), nullptr);
    FloatColumn *f6_after = new FloatColumn(2, new float(1.0), new float(2.0));
    f6->remove(2);
    assert(f1->size() == 2);
    assert(f1->equals(f6_after));

    FloatColumn *f7 = new FloatColumn(1, new float(1.0));
    FloatColumn *f7_after = new FloatColumn(0);
    f7->remove(0);
    assert(f7->size() == 0);
    assert(f7->equals(i7_after));

    FloatColumn *f8 = new FloatColumn(1, nullptr);
    FloatColumn *f8_after = new FloatColumn(0);
    f8->remove(0);
    assert(f8->size() == 0);
    assert(f8->equals(f8_after));

    delete f1;
    delete f1_after;
    delete f2;
    delete f2_after;
    delete f3;
    delete f3_after;
    delete f4;
    delete f4_after;
    delete f5;
    delete f5_after;
    delete f6;
    delete f6_after;
    delete f7;
    delete f7_after;
    delete f8;
    delete f8_after;

    StringColumn *s1 = new StringColumn(3, new String("hello"), new String("world"), new String("!"));
    StringColumn *s1_after = new StringColumn(2, new String("world"), new String("!"));
    s1->remove(0);
    assert(s1->size() == 2);
    assert(s1->equals(s1_after));

    StringColumn *s2 = new StringColumn(3, new String("hello"), new String("world"), new String("!"));
    StringColumn *s2_after = new StringColumn(2, new String("hello"), new String("!"));
    s2->remove(1);
    assert(s2->size() == 2);
    assert(s2->equals(s2_after));

    StringColumn *s3 = new StringColumn(3, new String("hello"), new String("world"), new String("!"));
    StringColumn *s3_after = new StringColumn(2, new String("hello"), new String("world"));
    s3->remove(2);
    assert(s3->size() == 2);
    assert(s3->equals(s3_after));

    StringColumn *s4 = new StringColumn(3, nullptr, new String("world"), new String("!"));
    StringColumn *s4_after = new StringColumn(2, new String("world"), new String("!"));
    s4->remove(0);
    assert(s4->size() == 2);
    assert(s4->equals(s4_after));

    StringColumn *s5 = new StringColumn(3, new String("hello"), nullptr, new String("!"));
    StringColumn *s5_after = new StringColumn(2, new String("hello"), new String("!"));
    s5->remove(1);
    assert(s5->size() == 2);
    assert(s5->equals(s5_after));

    StringColumn *s6 = new StringColumn(3, new String("hello"), new String("world"), nullptr);
    StringColumn *s6_after = new StringColumn(2, new String("hello"), new String("world"));
    s6->remove(2);
    assert(s1->size() == 2);
    assert(s1->equals(s6_after));

    StringColumn *s7 = new StringColumn(1, new String("hello"));
    StringColumn *s7_after = new StringColumn(0);
    s7->remove(0);
    assert(s7->size() == 0);
    assert(s7->equals(s7_after));

    StringColumn *s8 = new StringColumn(1, nullptr);
    StringColumn *s8_after = new StringColumn(0);
    s8->remove(0);
    assert(s8->size() == 0);
    assert(s8->equals(s8_after));

    delete s1;
    delete s1_after;
    delete s2;
    delete s2_after;
    delete s3;
    delete s3_after;
    delete s4;
    delete s4_after;
    delete s5;
    delete s5_after;
    delete s6;
    delete s6_after;
    delete s7;
    delete s7_after;
    delete s8;
    delete s8_after;
}

// tests the isEmpty() function in all columns
void testIsEmpty()
{
    BoolColumn *b = new BoolColumn(0);
    BoolColumn *b1 = new BoolColumn(1, new bool(true));
    b1->remove(0);
    assert(b->isEmpty());
    assert(b1->isEmpty());

    IntColumn *i = new IntColumn(0);
    IntColumn *i1 = new IntColumn(1, new int(1));
    i1->remove(0);
    assert(i->isEmpty());
    assert(i1->isEmpty());

    FloatColumn *f = new FloatColumn(0);
    FloatColumn *f1 = new FloatColumn(1, new float(1.0));
    f1->remove(0);
    assert(f->isEmpty());
    assert(f1->isEmpty());

    StringColumn *s = new StringColumn(0);
    StringColumn *s1 = new StringColumn(1, new String("hello"));
    s1->remove(0);
    assert(s->isEmpty());
    assert(s1->isEmpty());

    delete b;
    delete b1;
    delete i;
    delete i1;
    delete f;
    delete f1;
    delete s;
    delete s1;
}

// tests the insert() function in all columns
void testInsert()
{
    BoolColumn *b = new BoolColumn(0);
    bool *bp = new bool(true);
    BoolColumn *b1 = new BoolColumn(1, bp);
    b->insert(bp);
    assert(b->equals(b1));

    IntColumn *i = new IntColumn(0);
    int *ip = new int(1);
    IntColumn *i1 = new IntColumn(1, ip);
    i->insert(ip);
    assert(i->equals(i1));

    FloatColumn *f = new FloatColumn(0);
    float *fp = new float(1.0);
    FloatColumn *f1 = new FloatColumn(1, fp);
    f->insert(fp);
    assert(f->equals(f1));

    StringColumn *s = new StringColumn(0);
    String *sp = new String("hello");
    StringColumn *s1 = new StringColumn(1, sp);
    s->insert(sp);
    assert(s->equals(s1));

    delete b;
    delete b1;
    delete i;
    delete i1;
    delete f;
    delete f1;
    delete s;
    delete s1;

    BoolColumn *b = new BoolColumn(0);
    BoolColumn *b1 = new BoolColumn(1, nullptr);
    b->insert(nullptr);
    assert(b->equals(b1));

    IntColumn *i = new IntColumn(0);
    IntColumn *i1 = new IntColumn(1, nullptr);
    i->insert(nullptr);
    assert(i->equals(i1));

    FloatColumn *f = new FloatColumn(0);
    FloatColumn *f1 = new FloatColumn(1, nullptr);
    f->insert(nullptr);
    assert(f->equals(f1));

    StringColumn *s = new StringColumn(0);
    StringColumn *s1 = new StringColumn(1, nullptr);
    s->insert(nullptr);
    assert(s->equals(s1));

    delete b;
    delete b1;
    delete i;
    delete i1;
    delete f;
    delete f1;
    delete s;
    delete s1;
}

// tests the insertAt() function in all columns
void testInsertAt()
{
    BoolColumn *b = new BoolColumn(0);
    bool *bp = new bool(true);

    BoolColumn *b1 = new BoolColumn(1, bp);
    b->insertAt(0, bp);
    assert(b->size() == 1);
    assert(b->equals(b1));

    BoolColumn *b2 = new BoolColumn(2, bp, bp);
    b1->insertAt(1, bp);
    assert(b1->size() == 2);
    assert(b1->equals(b2));

    BoolColumn *b3 = new BoolColumn(3, bp, nullptr, bp);
    b2->insertAt(1, nullptr);
    assert(b2->size() == 3);
    assert(b2->equals(b3));

    IntColumn *i = new IntColumn(0);
    int *ip = new int(1);

    IntColumn *i1 = new IntColumn(1, ip);
    i->insertAt(0, ip);
    assert(i->size() == 1);
    assert(i->equals(i1));

    IntColumn *i2 = new IntColumn(2, ip, ip);
    i1->insertAt(1, ip);
    assert(i1->size() == 2);
    assert(i1->equals(i2));

    IntColumn *i3 = new IntColumn(3, ip, nullptr, ip);
    i2->insertAt(1, nullptr);
    assert(i2->size() == 3);
    assert(i2->equals(i3));

    FloatColumn *f = new FloatColumn(0);
    float *fp = new float(1.0);

    FloatColumn *f1 = new FloatColumn(1, fp);
    f->insertAt(0, fp);
    assert(f->size() == 1);
    assert(f->equals(f1));

    FloatColumn *f2 = new FloatColumn(2, bp, bp);
    f1->insertAt(1, fp);
    assert(f1->size() == 2);
    assert(f1->equals(f2));

    FloatColumn *f3 = new FloatColumn(3, fp, nullptr, fp);
    f2->insertAt(1, nullptr);
    assert(f2->size() == 3);
    assert(f2->equals(f3));

    StringColumn *s = new StringColumn(0);
    String *sp = new String("hello");

    StringColumn *s1 = new StringColumn(1, sp);
    s->insertAt(0, sp);
    assert(s->size() == 1);
    assert(s->equals(s1));

    StringColumn *s2 = new StringColumn(2, sp, sp);
    s1->insertAt(1, sp);
    assert(s1->size() == 2);
    assert(s1->equals(s2));

    StringColumn *s3 = new StringColumn(3, sp, nullptr, sp);
    s2->insertAt(1, nullptr);
    assert(s2->size() == 3);
    assert(s2->equals(s3));

    delete b;
    delete b1;
    delete b2;
    delete b3;
    delete i;
    delete i1;
    delete i2;
    delete i3;
    delete f;
    delete f1;
    delete f2;
    delete f3;
    delete s;
    delete s1;
    delete s2;
    delete s3;
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
    testRemove();
    testIsEmpty();
    testInsert();
    testInsertAt();
    println("All tests passed!");
    return 0;
}