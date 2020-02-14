<h1> Parallel Map </h1>

<h2> Design and Use Cases </h2>

First, a subclass of Thread (author: JV) was created called RowThread. This uses the same function as in Thread, however it has
its own constructor, and it overrides the `start()` function. The constructor takes a `DataFrame`, `Rower`, and start and end indices.
RowThread's `start()` function creates a Row for every index from the start index inclusive to the end index exclusive. Then, it populates
that row with the given `DataFrame` and uses `Rower`'s `accept()` function to map the `Rower`'s function to that row. 

The `pmap(Rower &r)` function in the `modified_dataframe.h` file first creates an array of RowThreads, an array of Rowers for each thread,
and an array of start indices and an array of end indices, depending on the number of threads. The number of start indices is the number of
threads that split the work. Same for the number of end indices. Then, it initializes every RowThread in the array with the current DataFrame, 
Rower, and start and end index. This way, it splits the work into several threads. 

<h2> Ongoing Issues! </h2>

There is a circular dependency between RowThread and DataFrame. We did not have time to think
of a better design where they are not dependent on each other. Unfortunately, because of this
issue, we were unable to actually test our implementation. 

<h2> Pmap faster than Map? </h2>

We are using gtest, as it automatically times tests. We have one test with a fairly large DataFrame (100 col x 100000 rows), to show that pmap
is faster than map with large DataFrames (this is to be expected). Additionally, we show that pmap is faster than map with a small DataFrame as
pmap calls map when the DataFrame is small enough that it would render the overhead work done by pmap to be unnecessary. 
