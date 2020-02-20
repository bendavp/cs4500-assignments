#include "rower.h"
#include "parser.h"
#include <chrono>

// measuring execution time https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/

int main(int argc, char **argv)
{
    assert(argc == 2);
    char *filename = argv[1];

    // rowers that will be used
    FibonnacciRower fib_rower_ = FibonnacciRower();
    AddAllInts adder_rower_ = AddAllInts();

    DataFrame *df3 = parse_file(filename, 30); // ~3 MB file
    std::cout << "hellob1" << '\n';
    clock_t start, end;
    double time_taken;
    // nonexpensive function with mapw
    start = clock();
    df3->map(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(adder_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "AddAllInt Rower, map, 3MB file: " << time_taken << '\n';
    adder_rower_.reset(); // reset the row counter
    // nonexpensive function with pmap
    start = clock();
    df3->pmap(adder_rower_);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
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
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //assert(fib_rower_.total_rows == 39956); // check that all rows were visited
    std::cout << "Fibonacci Rower, pmap, 3MB file: " << time_taken << '\n';
    fib_rower_.reset(); // reset the row counter
    // finished working with ~3MB file
    delete df3;
}