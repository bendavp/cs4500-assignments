#include "column.h"
#include "helper.h"

// tests the hash() function in all columns
void testHash()
{
    Column *b1 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b2 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b3 = new BoolColumn(2, new bool(false), new bool(true));

    Column *i1 = new IntColumn(2, new int(1), new int(2));
    Column *i2 = new IntColumn(2, new int(1), new int(2));
    Column *i3 = new IntColumn(2, new int(1), new int(1));

    Column *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f2 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f3 = new FloatColumn(2, new float(1.0), new float(1.0));

    Column *s1 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s2 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s3 = new StringColumn(2, new String("world"), new String("hello"));

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
    Column *b1 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b2 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b3 = new BoolColumn(2, new bool(false), new bool(true));
    Column *b4 = b1;

    Column *i1 = new IntColumn(2, new int(1), new int(2));
    Column *i2 = new IntColumn(2, new int(1), new int(2));
    Column *i3 = new IntColumn(2, new int(1), new int(1));
    Column *i4 = i1;

    Column *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f2 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f3 = new FloatColumn(2, new float(1.0), new float(1.0));
    Column *f4 = f1;

    Column *s1 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s2 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s3 = new StringColumn(2, new String("hello"), new String("hello"));
    Column *s4 = s1;

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
    Column *b1 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b2 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b3 = b1;
    String *b = new String("BOOL");

    Column *i1 = new IntColumn(2, new int(1), new int(2));
    Column *i2 = new IntColumn(2, new int(1), new int(2));
    Column *i3 = i1;
    String *i = new String("INT");

    Column *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f2 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f3 = f1;
    String *f = new String("FLOAT");

    Column *s1 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s2 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s3 = s1;
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
    Column *b1 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b2 = new BoolColumn(2, new bool(true), nullptr);
    const char *bool1 = " 1 \n 0 \n\0";
    const char *bool2 = " 1 \n - \n\0";

    Column *i1 = new IntColumn(2, new int(1), new int(-2));
    Column *i2 = new IntColumn(2, new int(1), nullptr);
    const char *int1 = " +1 \n -2 \n\0";
    const char *int2 = " +1 \n - \n\0";

    Column *f1 = new FloatColumn(2, new float(1.0), new float(-2.0));
    Column *f2 = new FloatColumn(2, new float(1.0), nullptr);
    const char *float1 = " +1.0 \n -2.0 \n\0";
    const char *float2 = " +1.0 \n - \n\0";

    Column *s1 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s2 = new StringColumn(2, new String("hello"), nullptr);
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
    Column *b1 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b2 = new BoolColumn(1, new bool(false));
    Column *b3 = b1;
    Column *subsetb1 = b1->subset(1, 2);
    Column *subsetb2 = b1->subset(0, 2);

    Column *i1 = new IntColumn(2, new int(1), new int(2));
    Column *i2 = new IntColumn(1, new int(1));
    Column *i3 = i1;
    Column *subseti1 = i1->subset(0, 1);
    Column *subseti2 = i1->subset(0, 2);

    Column *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f2 = new FloatColumn(1, new float(1.0));
    Column *f3 = f1;
    Column *subsetf1 = f1->subset(0, 1);
    Column *subsetf2 = f1->subset(0, 2);

    Column *s1 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s2 = new StringColumn(1, new String("world"));
    Column *s3 = s1;
    Column *subsets1 = s1->subset(1, 2);
    Column *subsets2 = s1->subset(0, 2);

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
    Column *b1 = new BoolColumn(2, new bool(true), new bool(false));
    Column *b2 = new BoolColumn(1, new bool(false));
    bool bool1 = true;
    bool bool2 = false;

    Column *i1 = new IntColumn(2, new int(1), new int(2));
    Column *i2 = new IntColumn(1, new int(1));
    int int1 = 1;
    int int2 = 2;

    Column *f1 = new FloatColumn(2, new float(1.0), new float(2.0));
    Column *f2 = new FloatColumn(1, new float(1.0));
    float float1 = 1.0;
    float float2 = 2.0;

    Column *s1 = new StringColumn(2, new String("hello"), new String("world"));
    Column *s2 = new StringColumn(1, new String("world"));
    String *string1 = new String("hello");
    String *string2 = new String("world");

    assert(*b1->getBool(0) == bool1);
    assert(*b1->getBool(1) == bool2);
    assert(*b2->getBool(0) == bool2);
    assert(*i1->getInt(0) == int1);
    assert(*i1->getInt(1) == int2);
    assert(*i2->getInt(0) == int1);
    assert(*f1->getFloat(0) - float1 < 0.001);
    assert(*f1->getFloat(1) - float2 < 0.001);
    assert(*f2->getFloat(0) - float1 < 0.001);
    assert(s1->getString(0)->equals(string1));
    assert(s1->getString(1)->equals(string2));
    assert(s2->getString(0)->equals(string2));

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
    Column *b1 = new BoolColumn(3, new bool(true), nullptr, new bool(true));
    Column *b2 = new BoolColumn(2, nullptr, new bool(false));
    Column *b3 = new BoolColumn(2, new bool(false), nullptr);
    Column *b4 = new BoolColumn(1, nullptr);

    Column *i1 = new IntColumn(3, new int(1), nullptr, new int(2));
    Column *i2 = new IntColumn(2, nullptr, new int(1));
    Column *i3 = new IntColumn(2, new int(1), nullptr);
    Column *i4 = new IntColumn(1, nullptr);

    Column *f1 = new FloatColumn(3, new float(1.0), nullptr, new float(2.0));
    Column *f2 = new FloatColumn(2, nullptr, new float(1.0));
    Column *f3 = new FloatColumn(2, new float(1.0), nullptr);
    Column *f4 = new FloatColumn(1, nullptr);

    Column *s1 = new StringColumn(3, new String("hello"), nullptr, new String("world"));
    Column *s2 = new StringColumn(2, nullptr, new String("world"));
    Column *s3 = new StringColumn(2, new String("hello"), nullptr);
    Column *s4 = new StringColumn(1, nullptr);

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
    Column *b1 = new BoolColumn(3, new bool(true), new bool(true), new bool(false));
    Column *b1_after = new BoolColumn(2, new bool(true), new bool(false));
    b1->remove(0);
    assert(b1->size() == 2);
    assert(b1->equals(b1_after));

    Column *b2 = new BoolColumn(3, new bool(true), new bool(true), new bool(false));
    Column *b2_after = new BoolColumn(2, new bool(true), new bool(false));
    b2->remove(1);
    assert(b2->size() == 2);
    assert(b2->equals(b2_after));

    Column *b3 = new BoolColumn(3, new bool(true), new bool(true), new bool(false));
    Column *b3_after = new BoolColumn(2, new bool(true), new bool(true));
    b3->remove(2);
    assert(b3->size() == 2);
    assert(b3->equals(b3_after));

    Column *b4 = new BoolColumn(3, nullptr, new bool(true), new bool(false));
    Column *b4_after = new BoolColumn(2, new bool(true), new bool(false));
    b4->remove(0);
    assert(b4->size() == 2);
    assert(b4->equals(b4_after));

    Column *b5 = new BoolColumn(3, new bool(true), nullptr, new bool(false));
    Column *b5_after = new BoolColumn(3, new bool(true), new bool(false));
    b5->remove(1);
    assert(b5->size() == 2);
    assert(b5->equals(b5_after));

    Column *b6 = new BoolColumn(3, new bool(true), new bool(true), nullptr);
    Column *b6_after = new BoolColumn(3, new bool(true), nullptr, new bool(true));
    b6->remove(2);
    assert(b1->size() == 2);
    assert(b1->equals(b6_after));

    Column *b7 = new BoolColumn(1, new bool(false));
    Column *b7_after = new BoolColumn(0);
    b7->remove(0);
    assert(b7->size() == 0);
    assert(b7->equals(b7_after));

    Column *b8 = new BoolColumn(1, nullptr);
    Column *b8_after = new BoolColumn(0);
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

    Column *i1 = new IntColumn(3, new int(1), new int(2), new int(3));
    Column *i1_after = new IntColumn(2, new int(2), new int(3));
    i1->remove(0);
    assert(i1->size() == 2);
    assert(i1->equals(i1_after));

    Column *i2 = new IntColumn(3, new int(1), new int(2), new int(3));
    Column *i2_after = new IntColumn(2, new int(1), new int(3));
    i2->remove(1);
    assert(i2->size() == 2);
    assert(i2->equals(i2_after));

    Column *i3 = new IntColumn(3, new int(1), new int(2), new int(3));
    Column *i3_after = new IntColumn(2, new int(1), new int(2));
    i3->remove(2);
    assert(i3->size() == 2);
    assert(i3->equals(i3_after));

    Column *i4 = new IntColumn(3, nullptr, new int(2), new int(3));
    Column *i4_after = new IntColumn(2, new int(2), new int(3));
    i4->remove(0);
    assert(i4->size() == 2);
    assert(i4->equals(i4_after));

    Column *i5 = new IntColumn(3, new int(1), nullptr, new int(3));
    Column *i5_after = new IntColumn(2, new int(1), new int(3));
    i5->remove(1);
    assert(i5->size() == 2);
    assert(i5->equals(i5_after));

    Column *i6 = new IntColumn(3, new int(1), new int(2), nullptr);
    Column *i6_after = new IntColumn(2, new int(1), new int(2));
    i6->remove(2);
    assert(i1->size() == 2);
    assert(i1->equals(i6_after));

    Column *i7 = new IntColumn(1, new int(1));
    Column *i7_after = new IntColumn(0);
    i7->remove(0);
    assert(i7->size() == 0);
    assert(i7->equals(i7_after));

    Column *i8 = new IntColumn(1, nullptr);
    Column *i8_after = new IntColumn(0);
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

    Column *f1 = new FloatColumn(3, new float(1.0), new float(2.0), new float(3.0));
    Column *f1_after = new FloatColumn(2, new float(2.0), new float(3.0));
    f1->remove(0);
    assert(f1->size() == 2);
    assert(f1->equals(f1_after));

    Column *f2 = new FloatColumn(3, new float(1.0), new float(2.0), new float(3.0));
    Column *f2_after = new FloatColumn(2, new float(1.0), new float(3.0));
    f2->remove(1);
    assert(f2->size() == 2);
    assert(f2->equals(f2_after));

    Column *f3 = new FloatColumn(3, new float(1.0), new float(2.0), new float(3.0));
    Column *f3_after = new FloatColumn(2, new float(1.0), new float(2.0));
    f3->remove(2);
    assert(f3->size() == 2);
    assert(f3->equals(f3_after));

    Column *f4 = new FloatColumn(3, nullptr, new float(2.0), new float(3.0));
    Column *f4_after = new FloatColumn(2, new float(2.0), new float(3.0));
    f4->remove(0);
    assert(f4->size() == 2);
    assert(f4->equals(f4_after));

    Column *f5 = new FloatColumn(3, new float(1.0), nullptr, new float(3.0));
    Column *f5_after = new FloatColumn(2, new float(1.0), new float(3.0));
    f5->remove(1);
    assert(f5->size() == 2);
    assert(f5->equals(f5_after));

    Column *f6 = new FloatColumn(3, new float(1.0), new float(2.0), nullptr);
    Column *f6_after = new FloatColumn(2, new float(1.0), new float(2.0));
    f6->remove(2);
    assert(f1->size() == 2);
    assert(f1->equals(f6_after));

    Column *f7 = new FloatColumn(1, new float(1.0));
    Column *f7_after = new FloatColumn(0);
    f7->remove(0);
    assert(f7->size() == 0);
    assert(f7->equals(i7_after));

    Column *f8 = new FloatColumn(1, nullptr);
    Column *f8_after = new FloatColumn(0);
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

    Column *s1 = new StringColumn(3, new String("hello"), new String("world"), new String("!"));
    Column *s1_after = new StringColumn(2, new String("world"), new String("!"));
    s1->remove(0);
    assert(s1->size() == 2);
    assert(s1->equals(s1_after));

    Column *s2 = new StringColumn(3, new String("hello"), new String("world"), new String("!"));
    Column *s2_after = new StringColumn(2, new String("hello"), new String("!"));
    s2->remove(1);
    assert(s2->size() == 2);
    assert(s2->equals(s2_after));

    Column *s3 = new StringColumn(3, new String("hello"), new String("world"), new String("!"));
    Column *s3_after = new StringColumn(2, new String("hello"), new String("world"));
    s3->remove(2);
    assert(s3->size() == 2);
    assert(s3->equals(s3_after));

    Column *s4 = new StringColumn(3, nullptr, new String("world"), new String("!"));
    Column *s4_after = new StringColumn(2, new String("world"), new String("!"));
    s4->remove(0);
    assert(s4->size() == 2);
    assert(s4->equals(s4_after));

    Column *s5 = new StringColumn(3, new String("hello"), nullptr, new String("!"));
    Column *s5_after = new StringColumn(2, new String("hello"), new String("!"));
    s5->remove(1);
    assert(s5->size() == 2);
    assert(s5->equals(s5_after));

    Column *s6 = new StringColumn(3, new String("hello"), new String("world"), nullptr);
    Column *s6_after = new StringColumn(2, new String("hello"), new String("world"));
    s6->remove(2);
    assert(s1->size() == 2);
    assert(s1->equals(s6_after));

    Column *s7 = new StringColumn(1, new String("hello"));
    Column *s7_after = new StringColumn(0);
    s7->remove(0);
    assert(s7->size() == 0);
    assert(s7->equals(s7_after));

    Column *s8 = new StringColumn(1, nullptr);
    Column *s8_after = new StringColumn(0);
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
    Column *b = new BoolColumn(0);
    Column *b1 = new BoolColumn(1, new bool(true));
    b1->remove(0);
    assert(b->isEmpty());
    assert(b1->isEmpty());

    Column *i = new IntColumn(0);
    Column *i1 = new IntColumn(1, new int(1));
    i1->remove(0);
    assert(i->isEmpty());
    assert(i1->isEmpty());

    Column *f = new FloatColumn(0);
    Column *f1 = new FloatColumn(1, new float(1.0));
    f1->remove(0);
    assert(f->isEmpty());
    assert(f1->isEmpty());

    Column *s = new StringColumn(0);
    Column *s1 = new StringColumn(1, new String("hello"));
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
    Column *b = new BoolColumn(0);
    bool *bp = new bool(true);
    Column *b1 = new BoolColumn(1, bp);
    b->insert(bp);
    assert(b->equals(b1));

    Column *i = new IntColumn(0);
    int *ip = new int(1);
    Column *i1 = new IntColumn(1, ip);
    i->insert(ip);
    assert(i->equals(i1));

    Column *f = new FloatColumn(0);
    float *fp = new float(1.0);
    Column *f1 = new FloatColumn(1, fp);
    f->insert(fp);
    assert(f->equals(f1));

    Column *s = new StringColumn(0);
    String *sp = new String("hello");
    Column *s1 = new StringColumn(1, sp);
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

    Column *b = new BoolColumn(0);
    Column *b1 = new BoolColumn(1, nullptr);
    b->insert(nullptr);
    assert(b->equals(b1));

    Column *i = new IntColumn(0);
    Column *i1 = new IntColumn(1, nullptr);
    i->insert(nullptr);
    assert(i->equals(i1));

    Column *f = new FloatColumn(0);
    Column *f1 = new FloatColumn(1, nullptr);
    f->insert(nullptr);
    assert(f->equals(f1));

    Column *s = new StringColumn(0);
    Column *s1 = new StringColumn(1, nullptr);
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
    Column *b = new BoolColumn(0);
    bool *bp = new bool(true);

    Column *b1 = new BoolColumn(1, bp);
    b->insertAt(0, bp);
    assert(b->size() == 1);
    assert(b->equals(b1));

    Column *b2 = new BoolColumn(2, bp, bp);
    b1->insertAt(1, bp);
    assert(b1->size() == 2);
    assert(b1->equals(b2));

    Column *b3 = new BoolColumn(3, bp, nullptr, bp);
    b2->insertAt(1, nullptr);
    assert(b2->size() == 3);
    assert(b2->equals(b3));

    Column *i = new IntColumn(0);
    int *ip = new int(1);

    Column *i1 = new IntColumn(1, ip);
    i->insertAt(0, ip);
    assert(i->size() == 1);
    assert(i->equals(i1));

    Column *i2 = new IntColumn(2, ip, ip);
    i1->insertAt(1, ip);
    assert(i1->size() == 2);
    assert(i1->equals(i2));

    Column *i3 = new IntColumn(3, ip, nullptr, ip);
    i2->insertAt(1, nullptr);
    assert(i2->size() == 3);
    assert(i2->equals(i3));

    Column *f = new FloatColumn(0);
    float *fp = new float(1.0);

    Column *f1 = new FloatColumn(1, fp);
    f->insertAt(0, fp);
    assert(f->size() == 1);
    assert(f->equals(f1));

    Column *f2 = new FloatColumn(2, bp, bp);
    f1->insertAt(1, fp);
    assert(f1->size() == 2);
    assert(f1->equals(f2));

    Column *f3 = new FloatColumn(3, fp, nullptr, fp);
    f2->insertAt(1, nullptr);
    assert(f2->size() == 3);
    assert(f2->equals(f3));

    Column *s = new StringColumn(0);
    String *sp = new String("hello");

    Column *s1 = new StringColumn(1, sp);
    s->insertAt(0, sp);
    assert(s->size() == 1);
    assert(s->equals(s1));

    Column *s2 = new StringColumn(2, sp, sp);
    s1->insertAt(1, sp);
    assert(s1->size() == 2);
    assert(s1->equals(s2));

    Column *s3 = new StringColumn(3, sp, nullptr, sp);
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