#include <cstring>
#include <iostream>
#include "dataframe.h"
// put dataframe stuff into the project folder and import column and dataframe

/**
 * @brief reads datafile.txt into a dataframe
 * 
 * @cite https://en.cppreference.com/w/cpp/string/byte/strtok
 * @cite https://riptutorial.com/c/example/8274/get-lines-from-a-file-using-getline--
 * 
 * @return int exit status
 */
int main()
{
    char *line_buf = NULL;                              // buffer to store line contents, initialy NULL since we haven't read a line yet
    size_t line_buf_size = 0;                           // size of line buffer, initially zero since we haven't read a line yet
    size_t line_size;                                   // initialize size of line (i.e. number of chars)
    FILE *fp = fopen("datafile.txt", "r");              // open datafile.txt
    line_size = getline(&line_buf, &line_buf_size, fp); // get first line of the file, set line_size to its size
    char *token = std::strtok(line_buf, "\t");          // set token to tokenize line

    // declare all columns here, i.e.
    Column *column1 = new IntColumn();
    Column *column2 = new IntColumn();
    Column *column3 = new IntColumn();
    Column *column4 = new FloatColumn();
    Column *column5 = new FloatColumn();
    Column *column6 = new BoolColumn();
    Column *column7 = new BoolColumn();
    Column *column8 = new StringColumn();
    Column *column9 = new StringColumn();
    Column *column10 = new StringColumn();
    // whatever other columns you need

    while (line_size > 0)
    {
        column1->push_back(atoi(token));
        token = std::strtok(NULL, "\t");
        column2->push_back(atoi(token));
        token = std::strtok(NULL, "\t");
        column3->push_back(atoi(token));
        token = std::strtok(NULL, "\t");
        column4->push_back((float)atof(token));
        token = std::strtok(NULL, "\t");
        column5->push_back((float)atof(token));
        token = std::strtok(NULL, "\t");
        column5->push_back((float)atof(token));
        token = std::strtok(NULL, "\t");
        column6->push_back((bool)atoi(token)); // cast to an int, then cast as bool
        token = std::strtok(NULL, "\t");
        column7->push_back((bool)atoi(token)); // cast to an int, then cast as bool
        token = std::strtok(NULL, "\t");
        column8->push_back(token);
        token = std::strtok(NULL, "\t");
        column9->push_back(token);
        token = std::strtok(NULL, "\t");
        column10->push_back(token);
        // etc... add to all columns by getting next token

        line_size = getline(&line_buf, &line_buf_size, fp); // get the next line (at end of file, line_size should be 0)
        token = std::strtok(line_buf, "\t");                // set token to tokenize next line
    }

    // put columns into a dataframe
    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    df->add_column(column1, new String("int1"));
    df->add_column(column2, new String("int2"));
    df->add_column(column3, new String("int3"));
    df->add_column(column4, new String("float4"));
    df->add_column(column5, new String("float5"));
    df->add_column(column6, new String("bool6"));
    df->add_column(column7, new String("bool7"));
    df->add_column(column8, new String("str8"));
    df->add_column(column8, new String("str9"));
    df->add_column(column8, new String("str10"));

    fclose(fp);

    return 0;
}