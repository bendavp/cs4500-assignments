<h1> Read Me <h1>
<h2> Introduction <h2>
A Dataframe can hold 4 different types of Data: Booleans, Integers, Floats, and Strings. These 4 types of data can be housed in Columns that are then stored in the Dataframe.
There are 4 different types of columns, that are each a subclass of Column, so that each different type of Column can be unified under one type to be stored in Dataframe. 
Each type of column is named accordingly: BoolColumn, IntColumn, FloatColumn, and StringColumn. 
As you may have guessed, each subclass of Column can only hold one type, and as such each Column in the Dataframe must be homogeneous, as Dataframes are not meant to take actual Column objects, only Column _subclass_ objects. 
Each row, however, can contain different types of data across the multiple columns in the Dataframe.

<h2> Columns <h2>
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

The `hash()`, `equals(Object *other)`, and `print()` functions are inherited from Object. They work the same as in Object:
```{C++}
BoolColumn *boolColumn = new BoolColumn(1, new bool(true));
boolColumn->hash() // gets the hashcode for the column
boolColumn->equals(boolColumn) // checks for equality between boolColumn and boolColumn. Would return true in this case
boolColumn->equals(new Object()) // would return false in this case
boolColumn->equals(new IntColumn(1, new int(2))); // would return false in this case
boolColumn->equals(new BoolColumn(1, new bool(false))); // would return false in this case
boolColumn->equals(new BoolColumn(1, new bool(true))); // would return true in this case
boolColumn->print() // would return a const char*, i.e. a string representation of the boolColumn and its elements
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

