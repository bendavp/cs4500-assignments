<h1> DataFrame </h1>

<h2> Introduction & Design Choices </h2>

Firstly, we had to create a new Array data structure so that we can quickly store and retrieve items in Columns without copying the entire payload. To achieve this, we created a `_type_FastArray` class (one for each type: `Bool`, `Int`, `Float`, `String*`). This class stores an array of arrays. The "outer" array starts at size 16, and the "inner" arrays are _constant_ at size 16. When all of the inner arrays are full, then the outer array doubles in size, copying pointers of the inner arrays to the newly expanded outer array. We also had to create a FastArray of Column to be able to efficiently store Columns in a large DataFrame, so there are 5 _types_ of `FastArray`s. Our 4 Columns (and 1 "interface" Column) store a `FastArray`, and all of the functions in Column are simply calls to `FastArray`. 

Our DataFrame takes in either a Schema, or a DataFrame. Our DataFrame constructor that takes a DataFrame pipes the given DataFrame's schema into the schema constructor. From there, our DataFrame copies the fields of the given schema, except for the row names, 