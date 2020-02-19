<h1> Parallel Map </h1>

<h2> Design and Use Cases </h2>

First, a subclass of Thread (author: JV) was created called RowThread. This uses the same function as in Thread, however it has
its own constructor, and it overrides the `start()` function. The constructor takes a `Rower`, `Row` array, _size_t_ elements in the Row array (this was to get rid of the circular dependecy). 

Because we pass an array of `Rows` and a `Rower` to use on that array, RowThread's `start()` function iterates through the `Row` array and passes each `Row` to the `Rower`. The `Rower`'s `accept()` function to map the `Rower`'s function to that row. 

The `pmap(Rower &r)` function in the `modified_dataframe.h` file first creates an array of RowThreads, an array of Rowers for each thread, and fills in an array of array of Rows (Row***), depending on the number of threads. The number of RowThreads/Rowers/etc. is the number of threads which splits the work. Then, it initializes every RowThread in the array with the current Rower, Array of Rows, and the number of elements in the array. This way, it splits the work into several threads. 

<h2> Ongoing Issues! </h2>

<h4> Current Issue </h4>
We changed out implementation and design to get rid of a circular dependency which worked; however, this now causes a segfault (Signal 11) when we try to run the parallel_map_examples file. 

<h4> Previous Issue </h4>
There is a circular dependency between RowThread and DataFrame. We did not have time to think
of a better design where they are not dependent on each other. Unfortunately, because of this
issue, we were unable to actually test our implementation. 

<h2> Pmap faster than Map? </h2>

We are using gtest, as it automatically times tests. We have one test with a fairly large DataFrame (100 col x 100000 rows), to show that pmap is faster than map with large DataFrames (this is to be expected). Additionally, we show that pmap is faster than map with a small DataFrame as pmap calls map when the DataFrame is small enough that it would render the overhead work done by pmap to be unnecessary. 
