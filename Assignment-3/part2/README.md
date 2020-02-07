<h1> Read Me </h1>
<h2> Introduction </h2>
A Dataframe can hold 4 different types of Data: Booleans, Integers, Floats, and Strings. These 4 types of data can be housed in Columns that are then stored in the Dataframe.
There are 4 different types of columns, that are each a subclass of Column, so that each different type of Column can be unified under one type to be stored in Dataframe. 
Each type of column is named accordingly: BoolColumn, IntColumn, FloatColumn, and StringColumn. 
As you may have guessed, each subclass of Column can only hold one type, and as such each Column in the Dataframe must be homogeneous, as Dataframes are not meant to take actual Column objects, only Column _subclass_ objects. 
Each row, however, can contain different types of data across the multiple columns in the Dataframe.

<h2> Columns </h2>
Column objects can be initialized with any number of arguments that match the type of the object, so long as the total number of arguments are included beforehand.
However, the primitive arguments must actually be pointers. This is to support representing missing values as `nullptr`. 
i.e.:
```{C++}
Column *boolColumn = new BoolColumn(5, new bool(true), new bool(true), new bool(false), new bool(false), new bool(true));
Column *intColumn = new IntColumn(4, new int(3), new int(2), new int(1), new int(0));
Column *floatColumn = new FloatColumn(3, new float(1.0), new float(2.0), nullptr); // missing value example here! one of the arguments is missing
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
```

Column objects can also be initialized via copy constructor, and can also be intialized as empty Columns using either the default constructor, or passing in 0 (indicating there are 0 arguments coming)
Both do the same
```{C++}
Column *boolColumn = new BoolColumn();
Column *boolColumn2 = new BoolColumn(0); // same as above
```

The `hash()`, `equals(Object *other)`, and `print()` functions are inherited from Object. Two Columns are equal if they are the same class and have the same elements in the same order. All methods work the same as in Object:
```{C++}
BoolColumn *boolColumn = new BoolColumn(1, new bool(true));
boolColumn->hash() // gets the hashcode for the column
boolColumn->equals(boolColumn) // checks for equality between boolColumn and boolColumn. Would return true in this case
boolColumn->equals(new Object()) // would return false in this case
boolColumn->equals(new IntColumn(1, new int(2))); // would return false in this case
boolColumn->equals(new BoolColumn(1, new bool(false))); // would return false in this case
boolColumn->equals(new BoolColumn(1, new bool(true))); // would return true in this case
println(boolColumn->print()) // would return a const char*, i.e. a string representation of the boolColumn and its elements
```

Column objects have a `subset(size_t idx1, size_t idx2)` function, which returns the same type of object as the column object, but with only a subset of its elements. 
The first index is inclusive, while the second index is exclusive. The second index must always be greater than the first.
```{C++}
Column *boolColumn = new BoolColumn(5, new bool(true), new bool(true), new bool(false), new bool(false), new bool(true));
Column *boolColumnSubset = boolColumn->subset(1, 3); // this sets boolColumnSubset to a BoolColumn with elements new bool(true) and new bool(false)
Column *boolColumnSubset = boolColumn->subset(3, 1); // bad. will terminate execution
Column *boolColumnSubset = boolColumn->subset(3, 3); // will return an empty BoolColumn
Column *boolColumnSubset = boolColumn->subset(7, 8); // bad. will terminate execution
```

Column objects have `getBool()`, `getInt()`, `getFloat()`, and `getString()`. These retrieve pointers to the primitive types based on the Columns
```{C++}
Column *boolColumn = new BoolColumn(5, new bool(true), new bool(true), new bool(false), new bool(false), new bool(true));
Column *intColumn = new IntColumn(4, new int(3), new int(2), new int(1), new int(0));
Column *floatColumn = new FloatColumn(3, new float(1.0), new float(2.0), nullptr); 
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
bool *b = boolColumn->getBool(1); // new bool(true)
int *i = intColumn->getInt(1); // new int(2)
float *f = floatColumn->getFloat(2); // nullptr
String *s = stringColumn->getString(1); // new String("world")
```

Column objects have `getType()`. This returns a String with a representation of the type of the column.
```{C++}
Column *boolColumn = new BoolColumn(5, new bool(true), new bool(true), new bool(false), new bool(false), new bool(true));
Column *intColumn = new IntColumn(4, new int(3), new int(2), new int(1), new int(0));
Column *floatColumn = new FloatColumn(3, new float(1.0), new float(2.0), nullptr); 
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
boolColumn->getType()->equals(“BOOL”); // returns true
intColumn->getType()->equals(“INT”); // true
floatColumn->getType()->equals(“FLOAT”); // true
stringColumn->getType()->equals(“STRING”); // true
```
Column objects have `remove(size_t idx)`. This is a void function that removes an element from the column.
```{C++}
Column *boolColumn = new BoolColumn(5, new bool(true), new bool(true), new bool(false), new bool(false), new bool(true));
boolColumn->remove(0); // removes the first element
```

Column objects have `isEmpty()`. This returns true if the given Column does not have _any_ elements in it.
```{C++}
Column *intColumn = new IntColumn(); // empty
Column *floatColumn = new FloatColumn(0); // also empty
Column *stringColumn = new StringColumn(1, new String(“hello”)); // not empty
intColumn->isEmpty(); // true
floatColumn->isEmpty(); // true
stringColumn->isEmpty(); // false
```

Column objects have `size()`. This returns the number of elements in the column.
```{C++}
Column *boolColumn = new BoolColumn(5, new bool(true), new bool(true), new bool(false), new bool(false), new bool(true));
Column*boolColumn2 = new BoolColumn();
Column *boolColumn3 = new BoolColumn(0);
Column *intColumn = new IntColumn(4, new int(3), new int(2), new int(1), new int(0));
Column *floatColumn = new FloatColumn(3, new float(1.0), new float(2.0), nullptr); // missing value example here! one of the arguments is missing
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
boolColumn->size(); // 5
boolColumn2->size(); // 0
boolColumn3->size(); // 0
intColumn->size(); // 4
floatColumn->size(); // 3
stringColumn->size();
```

Column objects have `insert(val)` and `insertAt(size_t idx, val)`. This is a void function that inserts a value into the column, either at the end of the column (in the case of `insert()`) or at a particular specified index (in the case of `insertAt()`). 
```{C++}
Column*boolColumn2 = new BoolColumn();
Column *boolColumn3 = new BoolColumn(0);
Column *intColumn = new IntColumn(4, new int(3), new int(2), new int(1), new int(0));
boolColumn2->insert(new bool(true)); // puts a new bool at the end of the empty column (so it is now the only element
boolColumn3->insertAt(1, new bool(true)); // would fail since index 1 does not exist in boolColumn3
boolColumn3->insertAt(0, new bool(true)); // does the same as above with boolColumn2
intColumn->insert(new int(7)); // inserts int 7 at the end
```

As you can probably tell, the functions that were built in to Columns are really there to facilitate similar functions in Dataframe. 

<h2> Dataframe </h2>
Dataframe objects can be initialized either as an empty Dataframe or Dataframe with specified columns. If initialized as a nonempty Dataframe object, all of the Columns must be the same length, and the total number of columns being used to initialize the Dataframe must be specified before any Columns are given. Additionally, Dataframe objects also have a copy constructor.

```{C++}
Dataframe *df = new Dataframe(); // empty dataframe

Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df2 = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

Column *col1 = new BoolColumn(1, new bool(true));
Dataframe *df_bad = new Dataframe(2, boolColumn, col1); // this does NOT work; the number of items in each column added needs to be equal

Dataframe *df3 = new Dataframe(0); // another way to initialize an empty dataframe
```

Dataframe objects like Column objects inherit from the Object class, and as such have `equals(Object *other)`, `hash()`, and `print()`. Two Dataframe objects are considered equal if all of their Columns are the same type, in the same order, and those Columns have the same values. `print()` gives a `const char*` that represents the Dataframe object as a string, using a tab-delimited format.
```{C++}
Dataframe *df = new Dataframe();
df->equals(new Dataframe();) // returns true, since both are empty
df->equals(new Dataframe(0)); // also returns true
df->equals(new Dataframe(1, new BoolColumn())); // returns false, since an empty Dataframe is not the same as a Dataframe with a Column in it. 
df->hash(); // returns the hashcode of the DataFrame
println(df->print()); // returns a const char* which can be used to display the df
```

Columns and rows in Dataframes can be named. To name a column, use the `rename_col(size_t cidx, String *new_cidx)` function, which takes the index of the column you want to rename, and a String* of the name you want to give it. Renaming a row is similar using the `rename_row(size_t ridx, String *new_ridx)` function. To get the names of all columns, use the `getColNames()` function, which returns a StringArray* of all the names of the columns (and nullptr if there is an unnamed column). Similarly, you can use the `getRowNames()` function with rows. 
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df2 = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

df2->rename_row(0, “testing”);
df2->rename_row(1, “testing123”);
df2->rename_row(2, “invalid”); // will terminate execution because row 2 does not exist
df2->rename_col(0, “test”);
df2->getRowNames(); // [new String(“testing”), new String(“testing123”)]
df2->getColNames(); // [new String(“test”), nullptr, nullptr, nullptr]

The first 6 rows of the Dataframe can be printed out with the `head()` function. This returns a const char* that represents the first 6 rows of the Dataframe.
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe();
Dataframe *df2 = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows
println(df->head()); // in this case would print nothing
println(df2->head()); // in this case would only print 2 rows
```

Dataframes also have a `subset(ridx1, ridx2, cidx1, cidx2)` function. `subset(...)` takes two row indices and two column indices, then returns a new Dataframe which is a subset of the original dataframe. The `subset(...)`  function can use the Columns’ `subset(...)` function in its implementation. 
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

df->subset(0,2,1,3); // creates a new dataframe with all of the rows and just the middle 2 columns from the original dataframe
df->subset(1, 0, 1, 3); // the row indices must be given in ascending order; this will terminate the execution
df->subset(0, 2, 3, 1); // the col indices must be given in ascending order; this will terminate the execution
df->subset(0, 3, 1, 2); // the row indices must be valid; this is out of bounds and will terminate the execution
df->subset(0, 1, 3, 4); // the col indices must be valid; this is out of bounds and will terminate the execution
df->subset(0, 0, 1, 1); // gives a empty dataframe
```

Dataframes have `getBool(size_t cidx, size_t ridx)`, `getBool(String *cidx, String *ridx)`, `getInt(size_t cidx, size_t ridx)`, `getInt(String *cidx, String *ridx)`, `getFloat(size_t cidx, size_t ridx)`, `getFloat(String *cidx, String *ridx)`, `getString(size_t cidx, size_t ridx)`, and `getString(String *cidx, String *ridx)`. These functions get data points at individual cells in the Dataframe, either by column/row index, or by column/row name (note: both applicable column AND row must be named for this to work):
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

df->getBool(0, 1); // returns bool at column 0 row 1
df->getInt(1, 0); // returns int at column 1 row 0
df->getBool(1, 0); // terminates execution, as column 1 is only ints
df->getBool(0, 7); // terminates execution, as there is no row with index 7 in column 0
df->renameCol(0, "column");
df->renameRow(0, "row");
df->getBool("column", "row"); // same as getBool(0,0)
df->getBool(1, "row"); // terminates execution -- can't mix indices and names
df->getBool("column", 1); // same as above
```

Dataframes have `dTypes()`, `getColType(size_t idx)`, `getColType(String *idx)`. `dTypes()` returns a StringArray with a list of all the types of the Columns in the Dataframe (e.g. `"BOOL"`, `"INT"`, `"FLOAT"`, `"STRING"`). The latter two functions allow you to get the type of a specific column by index or by name.
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

df->dTypes(); // returns ["BOOL", "INT", "FLOAT", "STRING"]
df->getColType(0); // returns "BOOL"
df->getColType(3); // returns "STRING"
df->renameCol(0, "column");
df->getColType("column"); // returns "BOOL"
```

Dataframes can delete a row or column at a specified index using `delete_row(ridx)` and `delete_col(cidx)` where ridx and cidx are the specified indices. Similarly to the subset(...) and getInt()/getFloat()/etc. functions, the execution will be terminated
if the speicified indices are out of bounds.
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

df->delete_row(0); // the dataframe will only have 1 row now; the first row is deleted
df->delete_col(2); // the dataframe deletes the third column; now there are only 3 columns
```

Dataframes can check if they are empty (i.e. have no columns/no cells), and Dataframes can also clear() themselves to become empty (i.e.: get rid of any Columns that the Dataframe contains).
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

df->empty(); // returns false since the dataframe contains Columns

df->clear(); // clears the dataframe of all its Columns
df->empty(); // returns true since now there are no Columns

df->clear(); // we should be able to clear an empty df without an errors (although nothing will change)
df->empty(); // returns true (df is still empty)
```

Dataframes can return the number of rows and columns they have as well as the total number of cells and its shape. The functions `nrow()` and `ncol()` gives the lengths of the axes. `size()` function gives the the total number of cells (which is number of rows X number of cols). `shape()` returns an IntArray of length 2, with the first value being the number of rows and the second value being the number of cols. Aside from `shape()` function, all of these functions have a `size_t` return type. 
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows
// functions on a non-empty df
df->nrow(); // returns number of rows, 2
df->ncol(); // returns number of cols, 4
df->size(); // returns total number of cells = nrows X ncols = 2X4 = 8
df->shape(); // returns IntArray with values [2, 4]

Dataframe *df2 = new Dataframe(); // empty dataframe
// functions on an empty df
df2->nrow(); // returns number of rows, 0
df2->ncol(); // returns number of cols, 0
df2->size(); // returns total number of cells = nrows X ncols = 0X0 = 0
df2->shape(); // returns IntArray with values [0, 0]
```

Dataframes have the functionality of inserting Columns, either at the end or at a specified index with `insert(Column c)` and `insertAt(size_t idx, Column n)`. Indices are considered valid if; they are within the bounds of (0, nrow/ncol) including the upper bound. If the given index is not valid, the index will be considered out of bounds and the execution will be terminated. 
```{C++}
Dataframe *df = new Dataframe(); // empty dataframe

Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));

// inserting columns
df->insert(boolColumn); // inserts boolColumn at the end
df->insertAt(1, intColumn); // inserts intColumn at the end effectively (1 is the index of the column)
df->insertAt(1, floatColumn); // inserts floatColumn at index 1
df->insert(5, stringColumn); // index is out of bounds, so this would terminate the execution
```

Dataframes have the functionality of appending row(s), either at the bottom of the Dataframe or at a specified index. This works similarly to `insert(...)/insertAt(...)`; however, the user needs to pass in Columns which match the current Dataframe to append. This also allows the functionality of appending multiple rows at once. 
```{C++}
Dataframe *df = new Dataframe(); // empty dataframe 

Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));

df->append(4, boolColumn, intColumn, floatColumn, stringColumn); // adds these 4 columns to the dataframe

df->append(3, boolColumn, intColumn, floatColumn); // the execution will terminate, since this does not match the shape of the dataframe (there are 4 columns so now when we append we need to have 4 columns)

Column *col = new BoolColumn(1, new bool(true)); 
df->append(4, col, intColumn, floatColumn, stringColumn)); // the execution will terminate; the columns are not of equal lengths (1, 2, 2, 2)

df->append(4, intColumn, stringColumn, boolColumn, floatColumn); // the execution will terminate; the columns must adhere to the existing columns in the Dataframe (these are changing the type of Column)

// appendAt has the same restrictions as append, except now an index can be specified

df->appendAt(1, 4, boolColumn, intColumn, floatColumn, stringColumn); // adds these 4 columns at index 1

df->appendAt(100, 4, boolColumn, intColumn, floatColumn, stringColumn); // 100 is out of bounds index so the execution will be terminated
```

Dataframes have functions for setting the value in a specific cell by index. The set functions take in a specific type (Int*, Float*, etc.); therefore, when setting the cell, the user must make sure that the type is the same as the specified Column. Additionally, the indices must be in bounds (as described above), and if not, the execution will be terminated. 
```{C++}
Column *boolColumn = new BoolColumn(2, new bool(true), new bool(true));
Column *intColumn = new IntColumn(2, new int(3), new int(2));
Column *floatColumn = new FloatColumn(2, new float(1.0), nullptr);
Column *stringColumn = new StringColumn(2, new String("hello"), new String("world"));
Dataframe *df = new Dataframe(4, boolColumn, intColumn, floatColumn, stringColumn); // creates a Dataframe with 4 Columns and 2 rows

df->setBool(1, 0, new bool(false)); // sets the value @ (0,1) to false
df->setBool(1, 3, new bool(false)); // execution will be aborted because the fourth column is not a BoolColumn
// the other set functions will fail under similar conditions to setBool 

df->setInt(1, 1, new int(1000)); // sets value @ (1,1) to 1000
df->setString(0, 3, new String("str")); // sets value @ (0,3) to "str"
df->setFloat(1, 2), new float(1.2222); // sets value @ (1,2) to 1.2222


```
