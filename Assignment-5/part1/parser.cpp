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
    char *line_buf = NULL;                 // buffer to store line contents, initialy NULL since we haven't read a line yet
    size_t line_buf_size = 0;              // size of line buffer, initially zero since we haven't read a line yet
    size_t line_size;                      // initialize size of line (i.e. number of chars)
    FILE *fp = fopen("testfile.txt", "r"); // open datafile.txt
    std::cout << "hello1"
              << "\n";
    line_size = getline(&line_buf, &line_buf_size, fp); // get first line of the file, set line_size to its size
    char *token = std::strtok(line_buf, "\t");          // set token to tokenize line
    std::cout << "hello2"
              << "\n";
    // declare all columns here, i.e.
    //IntColumn *column1 = new IntColumn();
    //IntColumn *column2 = new IntColumn();
    //IntColumn *column3 = new IntColumn();
    //FloatColumn *column4 = new FloatColumn();
    //FloatColumn *column5 = new FloatColumn();
    //BoolColumn *column6 = new BoolColumn();
    //BoolColumn *column7 = new BoolColumn();
    //StringColumn *column8 = new StringColumn();
    //StringColumn *column9 = new StringColumn();
    //StringColumn *column10 = new StringColumn();
    // whatever other columns you need
    Schema *s = new Schema("IIIFFBBSSS");
    DataFrame *df = new DataFrame(*s);
    Row *r = new Row(df->get_schema());

    float fval;
    float fval2;
    bool bval;
    bool bval2;

    size_t totalLines = 3;

    for (size_t i = 0; i < totalLines; i++)
    {
        //column1->push_back(atoi(token));
        r->set(0, atoi(token));

        token = std::strtok(NULL, "\t");

        //column2->push_back(atoi(token));
        r->set(1, atoi(token));

        token = std::strtok(NULL, "\t");
        //column3->push_back(atoi(token));
        r->set(2, atoi(token));

        token = std::strtok(NULL, "\t");
        //column4->push_back((float)atof(token));
        fval = atof(token);
        r->set(3, fval);

        token = std::strtok(NULL, "\t");
        //column5->push_back((float)atof(token));
        fval2 = atof(token);
        r->set(4, fval2);

        token = std::strtok(NULL, "\t");
        //column6->push_back((bool)atoi(token)); // cast to an int, then cast as bool
        bval = atoi(token);
        r->set(5, bval);

        token = std::strtok(NULL, "\t");
        //column7->push_back((bool)atoi(token)); // cast to an int, then cast as bool
        bval2 = atoi(token);
        r->set(6, bval2);
        token = std::strtok(NULL, "\t");

        //column8->push_back(new String(token));
        r->set(7, new String(token));
        token = std::strtok(NULL, "\t");

        //column9->push_back(new String(token));
        r->set(8, new String(token));
        token = std::strtok(NULL, "\t");

        //column10->push_back(new String(token));
        r->set(9, new String(token));

        // etc... add to all columns by getting next token

        df->add_row(*r);

        line_size = getline(&line_buf, &line_buf_size, fp); // get the next line (at end of file, line_size should be 0)

        token = std::strtok(line_buf, "\t"); // set token to tokenize next line
    }
    delete r;
    // put columns into a dataframe

    //df->add_column(column1, new String("int1"));
    //df->add_column(column2, new String("int2"));
    //df->add_column(column3, new String("int3"));
    //df->add_column(column4, new String("float4"));
    //df->add_column(column5, new String("float5"));
    //df->add_column(column6, new String("bool6"));
    //df->add_column(column7, new String("bool7"));
    //df->add_column(column8, new String("str8"));
    //df->add_column(column8, new String("str9"));
    //df->add_column(column8, new String("str10"));

    fclose(fp);

    RowPrinter rp = RowPrinter();

    df->map(rp); // as a check to see if the dataframe is as we expect

    return 0;
}