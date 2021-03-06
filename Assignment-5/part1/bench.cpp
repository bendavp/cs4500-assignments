#include "rower.h"
#include "parser.h"
#include <chrono>

// to run and pipe the out to text file:
// ./a.out datafile.txt > output.txt
// a.out = whatever the executable is called
// datafile.txt = datafile generated by file_generator.py (make sure datafile is longer than 1278600 lines long)
// output.txt = the file where all the print statements will be, will appear in part1 folder

// measuring execution time https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
int main(int argc, char **argv)
{
    assert(argc == 2);
    char *filename = argv[1];

    // rowers that will be used
    FibonnacciRower fib_rower_ = FibonnacciRower();
    AddAllInts adder_rower_ = AddAllInts();

    DataFrame *df3 = parse_file(filename, 39956); // ~3 MB file
    clock_t start, end;
    double time_taken;
    // nonexpensive function with mapw
    start = clock();
    df3->map(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, map, 3MB file: " << time_taken << '\n';
    // std::cout << adder_rower_.total_rows << '\n'; // check if correct num of rows visited
    adder_rower_.reset(); // reset the row counter
    // nonexpensive function with pmap
    start = clock();
    df3->pmap(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, pmap, 3MB file: " << time_taken << '\n';
    adder_rower_.reset(); // reset the row counter
    // expensive function with map
    start = clock();
    df3->map(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, map, 3MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // expensive function with pmap
    start = clock();
    df3->pmap(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, pmap, 3MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // finished working with ~3MB file

    DataFrame *df6 = parse_file(filename, 79912); // ~3 MB file
    // nonexpensive function with mapw
    start = clock();
    df6->map(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, map, 6MB file: " << time_taken << '\n';
    //std::cout << adder_rower_.total_rows << '\n';
    adder_rower_.reset(); // reset the row counter
    // nonexpensive function with pmap
    start = clock();
    df6->pmap(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, pmap, 6MB file: " << time_taken << '\n';
    adder_rower_.reset(); // reset the row counter
    // expensive function with map
    start = clock();
    df6->map(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, map, 6MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // expensive function with pmap
    start = clock();
    df6->pmap(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, pmap, 6MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter

    DataFrame *df12 = parse_file(filename, 159825); // ~3 MB file
    // nonexpensive function with mapw
    start = clock();
    df12->map(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, map, 12MB file: " << time_taken << '\n';
    //std::cout << adder_rower_.total_rows << '\n';
    adder_rower_.reset(); // reset the row counter
    // nonexpensive function with pmap
    start = clock();
    df12->pmap(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, pmap, 12MB file: " << time_taken << '\n';
    adder_rower_.reset(); // reset the row counter
    // expensive function with map
    start = clock();
    df12->map(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, map, 12MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // expensive function with pmap
    start = clock();
    df12->pmap(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, pmap, 12MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter

    DataFrame *df25 = parse_file(filename, 319650); // ~3 MB file
    // nonexpensive function with mapw
    start = clock();
    df25->map(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, map, 25MB file: " << time_taken << '\n';
    //std::cout << adder_rower_.total_rows << '\n';
    adder_rower_.reset(); // reset the row counter
    // nonexpensive function with pmap
    start = clock();
    df25->pmap(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, pmap, 25MB file: " << time_taken << '\n';
    adder_rower_.reset(); // reset the row counter
    // expensive function with map
    start = clock();
    df25->map(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, map, 25MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // expensive function with pmap
    start = clock();
    df25->pmap(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, pmap, 25MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter

    DataFrame *df50 = parse_file(filename, 639300); // ~3 MB file
    // nonexpensive function with mapw
    start = clock();
    df50->map(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, map, 50MB file: " << time_taken << '\n';
    //std::cout << adder_rower_.total_rows << '\n';
    adder_rower_.reset(); // reset the row counter
    // nonexpensive function with pmap
    start = clock();
    df50->pmap(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, pmap, 50MB file: " << time_taken << '\n';
    adder_rower_.reset(); // reset the row counter
    // expensive function with map
    start = clock();
    df50->map(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, map, 50MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // expensive function with pmap
    start = clock();
    df50->pmap(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, pmap, 50MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter

    DataFrame *df100 = parse_file(filename, 1278600); // ~3 MB file
    // nonexpensive function with mapw
    start = clock();
    df100->map(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, map, 100MB file: " << time_taken << '\n';
    // std::cout << adder_rower_.total_rows << '\n';
    adder_rower_.reset(); // reset the row counter
    // nonexpensive function with pmap
    start = clock();
    df100->pmap(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, pmap, 100MB file: " << time_taken << '\n';
    adder_rower_.reset(); // reset the row counter
    // expensive function with map
    start = clock();
    df100->map(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, map, 100MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // expensive function with pmap
    start = clock();
    df100->pmap(fib_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC) / 4; // divide by 4 because theres 4 threads
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, pmap, 100MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
}