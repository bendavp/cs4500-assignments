#include <cstring>
#include <iostream>
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
    // Column column1 = new IntColumn();
    // whatever other columns you need

    while (line_size > 0)
    {
        // column1.push_back(token);
        token = std::strtok(NULL, "\t");
        // column2.push_back(token);
        token = std::strtok(NULL, "\t");
        // etc... add to all columns by getting next token

        line_size = getline(&line_buf, &line_buf_size, fp); // get the next line (at end of file, line_size should be 0)
        token = std::strtok(line_buf, "\t");                // set token to tokenize next line
    }

    // put columns into a dataframe

    fclose(fp);

    return 0;
}