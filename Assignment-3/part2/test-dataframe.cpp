#include "dataframe.h"

void testGet()
{
    // nonempty dataframe with all types
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));
    Dataframe *df = new Dataframe(4, n, s, b, f);

    String *s1 = new String("s");
    String *s2 = new String("gg");
    String *s3 = new String("ez");
    // test pulling from different cells
    assert(*df->getInt(0, 0) == 2);
    assert(*df->getInt(0, 1) == 3);
    assert(*df->getInt(0, 2) == 4);
    assert(df->getString(1, 0)->equals(s1);
    assert(df->getString(1, 1)->equals(s2));
    assert(df->getString(1, 2)->equals(s3));
    assert(*df->getBool(2, 0) == true);
    assert(*df->getBool(2, 1) == false);
    assert(*df->getBool(2, 2) == true);
    assert(abs(*df->getFloat(0, 3) - 1.2) < 0.01);
    assert(abs(*df->getFloat(1, 3) - 42.4) < 0.01);
    assert(abs(*df->getFloat(2, 3) - 666.6) < 0.01);

    // rename rows and columns
    df->rename_row(0, new String("row1"));
    df->rename_row(1, new String("row2"));
    df->rename_row(2, new String("row3"));
    df->rename_col(0, new String("col1"));
    df->rename_col(1, new String("col2"));
    df->rename_col(2, new String("col3"));
    df->rename_col(3, new String("col4"));
    // tests pulling out these same values again with column/row names
    assert(df->getInt(new String("row1"), new String("col1")) == 2);
    assert(df->getInt(new String("row2"),new String("col1")) == 3);
    assert(df->getInt(new String("row3"),new String("col1")) == 4);
    assert(df->getString(new String("row1"), new String("col2"))->equals(s1);
    assert(df->getString(new String("row2"), new String("col2"))->equals(s2));
    assert(df->getString(new String("row3"), new String("col2"))->equals(s3));
    assert(df->getBool(new String("row1"), new String("col3")) == true);
    assert(df->getBool(new String("row2"), new String("col3")) == false);
    assert(df->getBool(new String("row3"), new String("col3")) == true);
    assert(df->getFloat(new String("row1"), new String("col4")) == 1.2);
    assert(df->getFloat(new String("row2"), new String("col4")) == 42.4);
    assert(df->getFloat(new String("row3"), new String("col4")) == 666.6);

    delete df;
    delete s1;
    delete s2;
    delete s3;
}

void testSet()
{
    // nonempty dataframe with all types
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));
    Dataframe *df = new Dataframe(4, n, s, b, f);

    String *s1 = new String("hello");
    String *s2 = new String("hello");

    String *s3 = new String("helloo");
    String *s4 = new String("helloo");

    // checking these are in the df
    assert(*df->getInt(0, 1) == 3);
    assert(*df->getInt(0, 2) == 4);
    assert(df->getString(1, 2)->equals(s3));
    assert(*df->getBool(2, 0) == true);
    assert(abs(*df->getFloat(3, 0)) == 1.2);

    // set the cells to new values via positional indicies
    df->setInt(0, 0, new int(111));
    df->setInt(2, 0, new int(4));
    df->setString(1, 1, s1);
    df->setBool(2, 2, new bool(false));
    df->setFloat(2, 3, new float(1.45));
    // check that these cells changed as expected
    assert(*df->getInt(0, 0) == 111);
    assert(*df->getInt(2, 0) == 4);
    assert(df->getString(1, 1)->equals(s2));
    assert(*df->getBool(2, 2) == false);
    assert(abs(*df->getFloat(2, 3) - 1.45) < 0.01);

    // rename rows and columns
    df->rename_row(0, new String("row1"));
    df->rename_row(1, new String("row2"));
    df->rename_row(2, new String("row3"));
    df->rename_row(3, 'row4');
    df->rename_col(0, new String("col1"));
    df->rename_col(1, new String("col2"));
    df->rename_col(2, new String("col3"));

    // set the cells to new values via referrable indicies
    df->setInt(new String("row1"), new String("col1"), new int(1111));
    df->setInt(new String("row2"), new String("col1"), new int(44));
    df->setString(new String("row3"), new String("col2"), s3);
    df->setBool(new String("row2"), new String("col3"), new bool(true));
    df->setFloat(new String("row3"), new String("col4"), new float(1.85));
    // check that the cells changed as expected
    assert(*df->get(new String("row1"), new String("col1")) == 1111);
    assert(*df->get(new String("row2"), new String("col1")) == 44);
    assert(df->get(new String("row3"), new String("col2"))->equals(s4));
    assert(*df->get(new String("row2"), new String("col3")) == true);
    assert(abs(*df->get(new String("row3"), new String("col4")) - 1.85) < 0.01);

    delete df;
    delete s2;
    delete s4;
}

void testEquals()
{
    // creating nonempty data frame
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Dataframe *df = new Dataframe(2, n, s);
    // creating same onempty data frame
    Dataframe *df1 = new Dataframe(2, n, s);
    // creating different nonempty data frame
    Column *n1 = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s1 = new StringColumn(3, new String("s"), new String("gg"), new String("ee"));
    Dataframe *df2 = new Dataframe(2, n1, s1);
    // creating empty dataframes
    Dataframe *df3 = new Dataframe();
    Dataframe *df4 = new Dataframe();

    assert(df->equals(df1));   // same not empty == same not empty
    assert(!df->equals(df2));  // diff not empty != diff not empty
    assert(!df3->equals(df2)); // empty != not empty
    assert(!df->equals(df3));  // not empty != empty
    assert(df3->equals(df4));  // empty == empty

    delete df;
    delete df1;
    delete df2;
    delete df3;
    delete df4;
}

void testSizesandShapes()
{
    // nonempty dataframe with all types
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));
    Dataframe *df = new Dataframe(4, n, s, b, f);

    IntArray *a = new IntArray();
    a->insertAtEnd(3);
    a->insertAtEnd(4);
    assert(df->size() == 12);
    assert(df->shape()->equals(a));

    // check empty array
    Dataframe df1 = new Dataframe();
    assert(df->size() == 0);
    IntArray *a1 = new IntArray();
    a1->insertAtEnd(0);
    a1->insertAtEnd(0);
    assert(df->shape()->equals(a1));

    delete df;
    delete a;
    delete a1;
    delete df1;
}

void testRowColInfo()
{
    String *s_int = new String("int");
    String *s_str = new String("String");
    String *s_f = new String("float");
    String *s_bool = new String("bool");

    // nonempty dataframe with all types
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));
    Dataframe *df = new Dataframe(4, n, s, b, f);

    // get col types by positonal index
    assert(df->getColType(0)->equals(s_int));
    assert(df->getColType(1)->equals(s_str));
    assert(df->getColType(2)->equals(s_f);
    assert(df->getColType(3)->equals(s_bool));

    // get names of rows
    StringArray *cols = new StringArray();
    cols->insertAtEnd(new String('0'));
    cols->insertAtEnd(new String('1'));
    cols->insertAtEnd(new String('2'));
    cols->insertAtEnd(new String('3'));
    StringArray *rows = new StringArray();
    rows->insertAtEnd(new String('0'));
    rows->insertAtEnd(new String('1'));
    rows->insertAtEnd(new String('2'));
    assert(df->getRowNames()->equals(rows));
    assert(df->getColsNames()->equals(cols));

    // rename rows and columns
    df->rename_row(0, new String("row1"));
    df->rename_row(1, new String("row2"));
    df->rename_row(2, new String("row3"));
    df->rename_col(0, new String("col1"));
    df->rename_col(1, new String("col2"));
    df->rename_col(2, new String("col3"));
    df->rename_col(3, new String('col4'));
    StringArray *cols1 = new StringArray();
    cols1->insertAtEnd(new String(new String("col1")));
    cols1->insertAtEnd(new String(new String("col2")));
    cols1->insertAtEnd(new String(new String("col3")));
    cols1->insertAtEnd(new String(new String("col4")));
    StringArray *rows1 = new StringArray();
    rows->insertAtEnd(new String(new String("row1")));
    rows->insertAtEnd(new String(new String("row2")));
    rows->insertAtEnd(new String(new String("row3")));
    assert(df->getRowNames()->equals(rows1));
    assert(df->getColsNames()->equals(cols1));

    // get col types by referrable index
    assert(df->getColType(new String("col1"))->equals(s_int));
    assert(df->getColType(new String("col2"))->equals(s_str));
    assert(df->getColType(new String("col3"))->equals(s_f);
    assert(df->getColType(new String("col4"))->equals(s_bool));

    // check col types after changing them
    df->delete_col(2);
    assert(df->getColType(0)->equals(s_int));
    assert(df->getColType(1)->equals(s_str));
    assert(df->getColType(2)->equals(s_bool));

    delete df;
    delete s_int;
    delete s_str;
    delete s_f;
    delete s_bool;
    delete cols;
    delete cols1;
    delete rows;
    delete rows1;
}

void testAppend()
{
    // appending to an empty data frame
    Dataframe *df = new Dataframe();
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));
    assert(df->size == 0);
    df->append(4, n, s, b, f);
    Dataframe *df1 = new Dataframe(4, n, s, b, f);
    assert(df->equals(df1));

    // appending to a nonempty dataframe
    Column *n1 = new IntColumn(1, new int(5));
    Column *s1 = new StringColumn(1, new String("hello"));
    Column *b1 = new BoolColumn(1, new bool(false));
    Column *f1 = new FloatColumn(1, new float(888.8));
    df->append(4, n, s, b, f);
    Column *n2 = new IntColumn(4, new int(2), new int(3), new int(4), new int(5));
    Column *s2 = new StringColumn(4, new String("s"), new String("gg"), new String("ez"), new String("hello"));
    Column *b2 = new BoolColumn(4, new bool(true), new bool(false), new bool(true), new bool(false));
    Column *f2 = new FloatColumn(4, new float(1.2), new float(42.4), new float(666.6), new float(888.8));
    Dataframe *df2 = new Dataframe(4, n2, s2, b2, f2);
    assert(df->equals(df2));

    // appending at a certain row
    Column *n3 = new IntColumn(1, new int(2));
    Column *s3 = new StringColumn(1, new String("hill"));
    Column *b3 = new BoolColumn(1, new bool(true));
    Column *f3 = new FloatColumn(1, new float(9.9));
    df->appendAt(3, 4, n3, s3, b3, f3);
    Column *n4 = new IntColumn(5, new int(2), new int(3), new int(4), new int(2), new int(5));
    Column *s4 = new StringColumn(5, new String("s"), new String("gg"), new String("ez"), new String("hill"), new String("hello"));
    Column *b4 = new BoolColumn(5, new bool(true), new bool(false), new bool(true), new bool(true), new bool(false));
    Column *f4 = new FloatColumn(5, new float(1.2), new float(42.4), new float(666.6), new float(9.9), new float(888.8));
    Dataframe *df3 = new Dataframe(4, n4, s4, b4, f4);

    delete df;
    delete df1;
    delete df2;
    delete df3;
}

void testInsert()
{
    // empty df
    Dataframe *df = new Dataframe();
    StringArray *a = new StringArray();

    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));

    // df is now empty, checking inserting for ints
    // check inserting columns now at end
    df->insertIntCol(n);
    a->insertAtEnd(new String("int"));
    assert(df->dTypes()->equals(a));
    // check inserting column at end via index
    df->insertIntColAt(1, n);
    a->insertAtEnd(new String("int"));
    assert(df->dTypes()->equals(a));
    // check inserting columns in middle
    df->insertIntColAt(1, n);
    a->insertAtEnd(new String("int"));
    assert(df->dTypes()->equals(a));
    // clear df
    df->clear();
    a->clear();

    // df is now empty, checking inserting for strings
    // check inserting columns now at end
    df->insertStringCol(s);
    a->insertAtEnd(new String("String"));
    assert(df->dTypes()->equals(a));
    // check inserting column at end via index
    df->insertStringColAt(1, s);
    a->insertAtEnd(new String("String"));
    assert(df->dTypes()->equals(a));
    // check inserting columns in middle
    df->insertStringColAt(1, s);
    a->insertAtEnd(new String("String"));
    assert(df->dTypes()->equals(a));
    // clear df
    df->clear();
    a->clear();

    // df is now empty, checking inserting for floats
    // check inserting columns now at end
    df->insertFloatCol(f);
    a->insertAtEnd(new String("float"));
    assert(df->dTypes()->equals(a));
    // check inserting column at end via index
    df->insertFloatColAt(1, f);
    a->insertAtEnd(new String("float"));
    assert(df->dTypes()->equals(a));
    // check inserting columns in middle
    df->insertFloatColAt(1, f);
    a->insertAtEnd(new String("float"));
    assert(df->dTypes()->equals(a));
    // clear df
    df->clear();
    a->clear();

    // df is now empty, checking inserting for bools
    // check inserting columns now at end
    df->insertBoolCol(b);
    a->insertAtEnd(new String("bool"));
    assert(df->dTypes()->equals(a));
    // check inserting column at end via index
    df->insertBoolColAt(1, b);
    a->insertAtEnd(new String("bool"));
    assert(df->dTypes()->equals(a));
    // check inserting columns in middle
    df->insertIntBoolAt(1, b);
    a->insertAtEnd(new String("bool"));
    assert(df->dTypes()->equals(a));
    // clear df
    df->clear();
    a->clear();

    delete df;
    delete a;
}

void testDelete()
{
    Column *n4 = new IntColumn(5, new int(2), new int(3), new int(4), new int(2), new int(5));
    Column *s4 = new StringColumn(5, new String("s"), new String("gg"), new String("ez"), new String("hill"), new String("hello"));
    Column *b4 = new BoolColumn(5, new bool(true), new bool(false), new bool(true), new bool(true), new bool(false));
    Column *f4 = new FloatColumn(5, new float(1.2), new float(42.4), new float(666.6), new float(9.9), new float(888.8));
    Dataframe *df = new Dataframe(4, n4, s4, b4, f4);

    // get names of rows
    StringArray *cols = new StringArray();
    cols->insertAtEnd(new String('0'));
    cols->insertAtEnd(new String('1'));
    cols->insertAtEnd(new String('2'));
    cols->insertAtEnd(new String('3'));
    StringArray *rows = new StringArray();
    rows->insertAtEnd(new String('0'));
    rows->insertAtEnd(new String('1'));
    rows->insertAtEnd(new String('2'));
    rows->insertAtEnd(new String('3'));
    rows->insertAtEnd(new String('4'));

    StringArray *cols1 = new StringArray();
    cols1->insertAtEnd(new String(new String("col1")));
    cols1->insertAtEnd(new String(new String("col2")));
    cols1->insertAtEnd(new String(new String("col3")));
    StringArray *rows1 = new StringArray();
    rows->insertAtEnd(new String(new String("row1")));
    rows->insertAtEnd(new String(new String("row2")));
    rows->insertAtEnd(new String(new String("row3")));
    rows->insertAtEnd(new String(new String("row4")));

    // check row and col names
    assert(df->getRowNames()->equals(rows));
    assert(df->getColsNames()->equals(cols));

    // delete a row by index
    df->delete_row(0);
    rows->remove(0);
    assert(df->getRowNames()->equals(rows));
    assert(df->getColsNames()->equals(cols));

    // delete a row by referrable index
    // rename rows and columns
    df->rename_row(0, new String("row1"));
    df->rename_row(1, new String("row2"));
    df->rename_row(2, new String("row3"));
    df->rename_row(3, new String("row4"));

    df->delete_row('row2');
    rows1->remove(1);
    assert(df->getRowNames()->equals(rows));
    assert(df->getColsNames()->equals(cols));

    // delete col by index
    df->delete_col(2);
    cols->remove(2);
    assert(df->getRowNames()->equals(rows1));
    assert(df->getColsNames()->equals(cols));

    // delete a col by  referrable index
    df->rename_col(0, new String("col1"));
    df->rename_col(1, new String("col2"));
    df->rename_col(2, new String("col3"));
    df->delete_col('col2');
    cols->remove(1);
    assert(df->getRowNames()->equals(rows1));
    assert(df->getColsNames()->equals(cols1));

    delete df;
    delete cols;
    delete rows;
    delete cols1;
    delete rows1;
}

void testClear()
{
    // creating nonempty data frame
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Dataframe *df = new Dataframe(2, n, s);
    // check df is not empty
    assert(!df->empty());
    // clear and check that the df is now empty
    df->clear();
    assert(df->empty());

    delete df;
}

void testEmpty()
{
    // empty dataframe
    Dataframe *df = new Dataframe();
    // creating nonempty data frame
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Dataframe *df2 = new Dataframe(2, n, s);

    assert(df->empty());
    assert(!df2->empty());

    delete df;
    delete df2;
}

void testSubset()
{
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));
    Datarame *df = new Dataframe(4, n, s, b, f);

    Column *n2 = new IntColumn(4, new int(2), new int(3), new int(4), new int(5));
    Column *s2 = new StringColumn(4, new String("s"), new String("gg"), new String("ez"), new String("hello"));
    Column *b2 = new BoolColumn(4, new bool(true), new bool(false), new bool(true), new bool(false));
    Column *f2 = new FloatColumn(4, new float(1.2), new float(42.4), new float(666.6), new float(888.8));
    Dataframe *df2 = new Dataframe(4, n2, s2, b2, f2);

    Dataframe *df3 = df2->subset(0, 3, 0, 5);
    assert(df->equals(df3));

    Dataframe *df4 = new Dataframe();
    Dataframe *df5 = df->subset(0, 0, 1, 1);
    assert(df4->equals(df5));
}

void testPrinting()
{
    Column *n = new IntColumn(4, new int(2), nullptr, new int(3), new int(4));
    Column *s = new StringColumn(4, new String("s"), new String("gg"), new String("ez"), nullptr);
    Column *b = new BoolColumn(4, new bool(true), new bool(false), nullptr, new bool(true));
    Column *f = new FloatColumn(4, nullptr, new float(1.2), new float(42.4), new float(666.6));
    Dataframe *df = new Dataframe(4, n, s, b, f);
    df->rename_row(0, new String("row1"));
    df->rename_row(1, new String("row2"));
    df->rename_row(2, new String("row3"));
    df->rename_col(0, new String("col1"));
    df->rename_col(1, new String("col2"));
    df->rename_col(2, new String("col3"));

    const char *output = 'index\tcol1\tcol2\tcol3\t3\nrow1\t2\ts\ttrue\t-\nrow2\t-\tgg\tfalse\t1.2\n\trow3\t3\tez\t-\t42.2\n\t3\t4\t-\ttrue\t666.6'

        assert(strcmp(df->print(), output) == 0);
}

void testDTypes()
{
    // nonempty dataframe with all types
    Column *n = new IntColumn(3, new int(2), new int(3), new int(4));
    Column *s = new StringColumn(3, new String("s"), new String("gg"), new String("ez"));
    Column *b = new BoolColumn(3, new bool(true), new bool(false), new bool(true));
    Column *f = new FloatColumn(3, new float(1.2), new float(42.4), new float(666.6));
    Dataframe *df = new Dataframe(4, n, s, b, f);

    String *s_int = new String("int");
    String *s_str = new String("String");
    String *s_f = new String("float");
    String *s_bool = new String("bool");

    StringArray a = new StringArray();
    a->insertAtEnd(s_int);
    a->insertAtEnd(s_str);
    a->indertAtEnd(s_bool);
    a->insertAtEnd(s_f);
    assert(df->dTypes()->equals(a));

    // remove a column and check
    df->delete_col(2);
    StringArray a1 = new StringArray();
    a1->insertAtEnd(s_int);
    a1->insertAtEnd(s_str);
    a1->insertAtEnd(s_f);
    assert(df->dTypes()->equals(a1));

    // insert a column and check
    df->insert(f);
    StringArray a2 = new StringArray();
    a2->insertAtEnd(s_int);
    a2->insertAtEnd(s_str);
    a2->insertAtEnd(s_f);
    a2->insertAtEnd(s_f);
    assert(df->dTypes()->equals(a2));

    delete df;
    delete a;
    delete a1;
    delete a2;
    delete s_int;
    delete s_str;
    delete s_f;
    delete s_bool;
}

int main()
{
    testEquals();
    testEmpty();
    testGet();
    testInsert();
    testSet();
    testAppend();
    testDelete();
    testRename();
    testSubset();
    testDTypes();
    testClear();
    testEmpty();
    testPrinting();
    testRowColInfo();
    return 0;
}
