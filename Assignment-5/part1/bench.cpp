#include "rower.h"
#include "parser.h"
#include <chrono>

int main(int argc, char **argv)
{
    assert(argc == 2);
    char *filename = argv[1];

    DataFrame *df3 = parse_file(filename, 39956); // 3 MB file
    //
    delete df3;

    DataFrame
}