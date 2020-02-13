#include <gtest/gtest.h>
#include "column.h"
#include <math.h>

#define GT_TRUE(a) ASSERT_EQ((a), true)
#define GT_FALSE(a) ASSERT_EQ((a), false)
#define GT_EQUALS(a, b) ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

/**
 * @brief Tests if we can actually pass va_list into a constructor as the literal va_list.
 * This is because all Columns take a va_list and pass it into the FastArray constructors
 * 
 * Jan wasn't sure if this would actually work so we decided to test it out!
 */
void doesVaListActuallyWork()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    IntColumn *ic = new IntColumn(5, 1, 2, 3, 4, 5);
    BoolColumn *bc = new BoolColumn(2, true, false);
    FloatColumn *fc = new FloatColumn(4, 4.20, 4.20, 4.20, 4.20);
    StringColumn *sc = new StringColumn(2, new String("hello"), new String("world"));

    GT_TRUE(i->equals(ic->arr_));
    GT_TRUE(b->equals(bc->arr_));
    GT_TRUE(f->equals(fc->arr_));
    GT_TRUE(s->equals(sc->arr_));

    delete i;
    delete b;
    delete f;
    delete s;
    delete ic;
    delete bc;
    delete fc;
    delete sc;
    exit(0);
}

TEST(a4, p1) { ASSERT_EXIT_ZERO(doesVaListActuallyWork); }

/**
 * @brief Tests the get() function in all FastArrays
 * 
 */
void testGet()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    GT_EQUALS(i->get(0), 1);
    GT_EQUALS(i->get(4), 5);
    GT_EQUALS(b->get(0), true);
    GT_EQUALS(b->get(1), false);
    GT_TRUE(f->get(0) - 4.20 < 0.001 || f->get(0) - 4.20 > -.001);
    GT_TRUE(f->get(3) - 4.20 < 0.001 || f->get(3) - 4.20 > -.001);
    GT_TRUE(s->get(0)->equals(new String("hello")));
    GT_TRUE(s->get(1)->equals(new String("world")));

    exit(0);
}

TEST(a4, p2) { ASSERT_EXIT_ZERO(testGet); }

/**
 * @brief Tests the set() function in all FastArrays
 * 
 */
void testSet()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    i->set(0, 420);
    i->set(4, 69);
    GT_EQUALS(i->get(0), 420);
    GT_EQUALS(i->get(4), 69);

    b->set(0, true);
    b->set(1, false);
    GT_EQUALS(b->get(0), true);
    GT_EQUALS(b->get(1), false);

    f->set(0, 4.20);
    f->set(3, 6.9);
    GT_TRUE(f->get(0) - 4.20 < 0.001 || f->get(0) - 4.20 > -.001);
    GT_TRUE(f->get(3) - 6.9 < 0.001 || f->get(3) - 6.9 > -.001);

    String *h = new String("Heeellloooooo"); // no need to delete these as FastArrays own their contents
    String *w = new String("wooooorllddddd");
    s->set(0, h);
    s->set(1, w);
    GT_TRUE(s->get(0)->equals(h));
    GT_TRUE(s->get(1)->equals(w));

    exit(0);
}

TEST(a4, p3) { ASSERT_EXIT_ZERO(testSet); }

/**
 * @brief Tests the grow() function in all FastArrays by
 * adding 512 elements to each, which would grow
 * the outer array twice and the inner array(s) multiple
 * times
 * 
 * Also tests push_back() because we have to use that
 * function to test grow()
 * 
 */
void testGrowAndPushBack()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    for (int j = 0; j < 512; j++)
    {
        i->push_back(j);
        GT_EQUALS(i->get(j + 5), j);
    }

    for (int j = 0; j < 512; j++)
    {
        b->push_back(0);
        GT_EQUALS(b->get(j + 2), 0);
    }

    for (int j = 0; j < 512; j++)
    {
        f->push_back(4.20);
        GT_TRUE(f->get(j + 4) - 4.20 < 0.001 || f->get(j + 4) - 4.20 > -.001);
    }

    String *str = new String("hello world"); // FastArrays own their contents, so no need to delete this at the end
    for (int j = 0; j < 512; j++)
    {
        s->push_back(str);
        GT_TRUE(s->get(j + 2)->equals(str));
    }

    exit(0);
}

TEST(a4, p4) { ASSERT_EXIT_ZERO(testGrowAndPushBack); }

/**
 * @brief Runs all Google Tests in this file
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}