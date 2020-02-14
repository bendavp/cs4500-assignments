<h1> DataFrame </h1>

<h2> Introduction & Design Choices </h2>

Firstly, we had to create a new Array data structure so that we can quickly store and retrieve items in Columns without copying the entire payload. To achieve this, we created a `_type_FastArray` class (one for each type: `Bool`, `Int`, `Float`, `String*`). This class stores an array of arrays. The "outer" array starts at size 16, and the "inner" arrays are _constant_ at size 16. When all of the inner arrays are full, then the outer array doubles in size, copying pointers of the inner arrays to the newly expanded outer array. We also had to create a FastArray of Column to be able to efficiently store Columns in a large DataFrame, so there are 5 _types_ of `FastArray`s. Our 4 Columns (and 1 "interface" Column) store a `FastArray`, and all of the functions in Column are simply calls to `FastArray`. All of this code can be found in `column.h`.

Next, our Schema can be made with a default constructor, in which case there are no Columns/column types and no column and row names. It can also be made with a copy constructor that takes a Schema and copies its values, and it can be made with a `const char*`. If made with a `const char*`, that string will be used as a representation of the column types, as noted in the spec. We use `StringFastArray`s to store `String*`s that represent row names and column names in the Schema. 

Our DataFrame takes in either a Schema, or a DataFrame. Our DataFrame constructor that takes a DataFrame pipes the given DataFrame's schema into the schema constructor. From there, our DataFrame copies the fields of the given schema, except for the row names, and creates a `ColumnFastArray` to store Columns in the DataFrame. It also computes the number of columns based on the schema. 

<h2> Use Cases </h2>

<h3> Initializing A Column </h3>

```{C++}
IntColumn *i = new IntColumn(5, 1, 2, 3, 4, 5);
BoolColumn *b = new BoolColumn(2, true, false);
FloatColumn *f = new FloatColumn(4, 4.20, 4.20, 4.20, 4.20);
StringColumn *s = new StringColumn(2, new String("hello"), new String("world"));
```

<h3> Getting from a Column </h3>

```{C++}
// based on the columns created above
i->get(0); // 1
i->get(4); // 5
b->get(0); // true
b->get(1); // false
f->get(0); // 4.20
f->get(3); // 4.20
s->get(0); // String("hello")
s->get(1); // String("world")
```

<h3> Setting a new value in a Column </h3>

```{C++}
i->set(0, 420); // i->get(0) == 420
i->set(4, 69); // i->get(4) == 69

b->set(0, true); // b->get(0) == true
b->set(1, false); // b->get(1) == false

f->set(0, 4.20); // f->get(0) == 4.20
f->set(3, 6.9); // f->get(3) == 6.9

String *h = new String("Heeellloooooo");
String *w = new String("wooooorllddddd");
s->set(0, h);
s->set(1, w);
```


<h3> Pushing back a value into a Column </h3>

```{C++}
i->push_back(123); // i->get(5) == 123

b->push_back(0); // b->get(2) == false

f->push_back(4.20); // f->get(4) == 4.20

String *str = new String("hello world"); 
s->push_back(str);
```

<h3> Creating a Schema and adding Columns to it </h3>
String *s_str = new String("FIBS");
Schema *s = new Schema(s_str->c_str()); // Schema represents a DataFrame with column types Float, Int, Bool, and String

s->add_column('S', new String("Lies")); // Schema now represents a DataFrame with column types Float, Int, Bool, String, and String
                                        // with the last column having the name "Lies"
```