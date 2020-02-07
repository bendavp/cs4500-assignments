#include "dataframe.h"
#include "column.h"
#include "array.h"

void testGet(){  
    // nonempty dataframe with all types
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Column *b = new BoolColumn(true, false, true);
    Column *f = new FloatColumn(1.2, 42.4, 666.6)
    Dataframe *df = new Dataframe(5, n, s, b, f);

    String *s1 = new String("s");
    String *s2 = new String("gg");
    String *s3 = new String("ez");
    // test pulling from different cells
    assert(df->getInt(0, 0) == 2);
    assert(df->getInt(0, 1) == 3);
    assert(df->getInt(0, 2) == 4);
    assert(df->getString(1, 0)->equals(s1);
    assert(df->getString(1, 1)->equals(s2));
    assert(df->getString(1, 2)->equals(s3));
    assert(df->getBool(2, 0) == true);
    assert(df->getBool(2, 1) == false);
    assert(df->getBool(2, 2) == true);
    assert(abs(df->getFloat(0, 3) - 1.2) < 0.01);
    assert(abs(df->getFloat(1, 3) - 42.4) < 0.01);
    assert(abs(df->getFloat(2, 3) - 666.6) < 0.01);

    // rename rows and columns
    df->rename_row(0, 'row1');
    df->rename_row(1, 'row2');
    df->rename_row(2, 'row3');
    df->rename_col(0, 'col1');
    df->rename_col(1, 'col2');
    df->rename_col(2, 'col3');
    df->rename_col(2, 'col4');
    // tests pulling out these same values again with column/row names
    assert(df->getInt('row1', 'col1') == 2);
    assert(df->getInt('row2','col1') == 3);
    assert(df->getInt('row3','col1') == 4);
    assert(df->getString('row1', 'col2')->equals(s1);
    assert(df->getString('row2', 'col2')->equals(s2));
    assert(df->getString('row3', 'col2')->equals(s3));
    assert(df->getBool('row1', 'col3') == true);
    assert(df->getBool('row2', 'col3') == false);
    assert(df->getBool('row3', 'col3') == true);
    assert(df->getFloat('row1', 'col4') == 1.2);
    assert(df->getFloat('row2', 'col4') == 42.4);
    assert(df->getFloat('row3', 'col4') == 666.6);

    delete df;
    delete s;
    delete s1;
    delete s2;
    delete s3;
    delete n;
    delete f;
    delete b;
}

void testSet(){
    // nonempty dataframe with all types
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Column *b = new BoolColumn(true, false, true);
    Column *f = new FloatColumn(1.2, 42.4, 666.6)
    Dataframe *df = new Dataframe(5, n, s, b, f);

    String *s1 = new String("hello");
    String *s2 = new String("hello");

    String *s3 = new String("helloo");
    String *s4 = new String("helloo");

    // checking these are in the df
    assert(df->getInt(0, 1) == 3);
    assert(df->getInt(0, 2) == 4);
    assert(df->getString(1, 2)->equals(s3));
    assert(df->getBool(2, 0) == true);
    assert(abs(df->getFloat(3, 0)) == 1.2);

    // set the cells to new values via positional indicies
    df->set(0, 0, 111);
    df->set(2, 0, 4);
    df->set(1, 1, s1);
    df->set(2, 2, false);
    df->set(2, 3, 1.45);
    // check that these cells changed as expected
    assert(df->getInt(0, 0) == 111);
    assert(df->getInt(2, 0) == 4);
    assert(df->getString(1, 1)->equals(s2));
    assert(df->getBool(2, 2) == false);
    assert(abs(df->getFloat(2, 3) - 1.45) < 0.01);

    // rename rows and columns
    df->rename_row(0, 'row1');
    df->rename_row(1, 'row2');
    df->rename_row(2, 'row3');
    df->rename_row(3, 'row4');
    df->rename_col(0, 'col1');
    df->rename_col(1, 'col2');
    df->rename_col(2, 'col3');

    // set the cells to new values via referrable indicies
    df->set('row1', 'col1', 1111);
    df->set('row2', 'col1', 44);
    df->set('row3', 'col2', s3);
    df->set('row2', 'col3', true);
    df->set('row3', 'col4', 1.85);
    // check that the cells changed as expected
    assert(df->get('row1', 'col1') == 1111);
    assert(df->get('row2', 'col1') == 44);
    assert(df->get('row3', 'col2')->equals(s4));
    assert(df->get('row2', 'col3') == true);
    assert(abs(df->get('row3', 'col4') - 1.85) < 0.01);

    delete df;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s;
    delete n;
    delete b;
    delete f;
}

void testEquals(){
    // creating nonempty data frame
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Dataframe *df = new Dataframe(3, n, s);
    // creating same onempty data frame
    Dataframe *df1 = new Dataframe(2, n, s);
    // creating different nonempty data frame
    Column *n1 = new IntColumn(2, 3, 4);
    Column *s1 = new StringColumn("s", "gg", "ee");
    Dataframe *df2 = new Dataframe(3, n1, s1);
    // creating empty dataframes
    Dataframe *df3 = new Dataframe();
    Dataframe *df4 = new Dataframe();

    assert(df->equals(df1)); // same not empty == same not empty
    assert(!df->equals(df2)); // diff not empty != diff not empty
    assert(!df3->equals(df2)); // empty != not empty
    assert(!df->equals(df3)); // not empty != empty
    assert(df3->equals(df4)); // empty == empty

    delete df;
    delete df1;
    delete df2;
    delete df3;
    delete df4;
    delete n;
    delete s;
    delete n1;
    delete s1;
}

void testSizesandShapes(){
    // nonempty dataframe with all types
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Column *b = new BoolColumn(true, false, true);
    Column *f = new FloatColumn(1.2, 42.4, 666.6)
    Dataframe *df = new Dataframe(5, n, s, b, f);

    IntArray *a = new IntArray();
    a->insertAtEnd(3);
    a->insertAtEnd(4);
    assert(df->size() == 12);
    assert(df->shape()->a);

    // check empty array
    Dataframe df1 = new Dataframe();
    assert(df->size() == 0);
    IntArray *a1 = new IntArray();
    a->insertAtEnd(0);
    a->insertAtEnd(0);
    assert(df->shape()->a);

    delete df;
    delete s;
    delete n;
    delete b;
    delete f;
    delete a;
    delete a1;
    delete df1;
}

void testRowColInfo(){
    String *s_int = new String("int");
    String *s_str = new String("String");
    String *s_f = new String("float");
    String *s_bool = new String("bool");

    // nonempty dataframe with all types
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Column *b = new BoolColumn(true, false, true);
    Column *f = new FloatColumn(1.2, 42.4, 666.6)
    Dataframe *df = new Dataframe(5, n, s, b, f);

    // get names of rows
    StringArray a = new String
}

void testAppend(){}

void testInsert(){}

void testDelete(){}

void testRename(){}

void testClear(){
    // creating nonempty data frame
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Dataframe *df = new Dataframe(2, n, s);
    // check df is not empty
    assert(!df->empty());
    // clear and check that the df is now empty
    df->clear();
    assert(df->empty());

    delete df;
    delete n;
    delete s;
}

void testEmpty(){
    // empty dataframe
    Dataframe *df = new Dataframe();
    // creating nonempty data frame
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Dataframe *df2 = new Dataframe(2, n, s);

    assert(df->empty());
    assert(!df2->empty());

    delete df;
    delete df2;
    delete n;
    delete s;
}

void testSubset(){}

void testPrinting(){}

void testDTypes(){
    // nonempty dataframe with all types
    Column *n = new IntColumn(2, 3, 4);
    Column *s = new StringColumn("s", "gg", "ez");
    Column *b = new BoolColumn(true, false, true);
    Column *f = new FloatColumn(1.2, 42.4, 666.6)
    Dataframe *df = new Dataframe(5, n, s, b, f);

    String *s_int = new String("int");
    String *s_str = new String("String");
    String *s_f = new String("float");
    String *s_bool = new String("bool");

    StringArray a = new StringArray(s_int, s_str, s_bool, s_f);
    assert(df->dTypes()->equals(a));

    // remove a column and check
    df->delete_col(2);
    StringArray a1 = new StringArray(s_int, s_str, s_f);
    assert(df->dTypes()->equals(a1));

    // insert a column and check
    df->insert(f);
    StringArray a2 = new StringArray(s_int, s_str, s_f, s_f);
    assert(df->dTypes()->equals(a2));

    delete df;
    delete n;
    delete s;
    delete f;
    delete b;
    delete a;
    delete a1;
    delete a2;
    delete s_int;
    delete s_str;
    delete s_f;
    delete s_bool;
}

int main(){
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

