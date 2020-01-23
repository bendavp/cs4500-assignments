#include "string.h"
#include "helper.h"
#include "column.h"

/**
 * @brief Checks that a flag in the command line matches one of the acceptable flags, and that the number of 
 * parameters given for the flag matches the appropriate number of parameters expected for the given flag
 * 
 * @param i the index in the char array of arguments corresponding to where the flag was found
 * @param arg the text of the argument given in the command line
 * @param argh the total number of strings in the command line
 * @param flag the string literal of the flag that is expected
 * @param param the number of parameters given for the flag
 * 
 * @return true if the flag matches one of the accepted flags, and the number of arguments matches the accepted number
 * of arguments for that flag
 * @return false if one of the conditions listed above is false
 */
bool checkflag(int i, char *arg, int argh, const char *flag, int param)
{
    return strcmp(arg, flag) == 0 && i + param < argh;
}

/**
 * @brief Converts the given char array into an integer
 * 
 * @param param the char array to be converted into an integer
 * @return int the integer that was once a char array
 */
int convertParamToInt(char *param)
{
    for (int i = 0; i < strlen(param); i++)
    {
        if (!isdigit(param[i]))
        {
            println("Indices must be digits!");
            exit(1);
        }
    }
    return atoi(param);
}

/**
 * @brief Determines the number of characters in a given file
 * 
 * @param file the file whose length is to be counted
 * @return size_t the length (number of characters) of the file
 * 
 * @cite Taken from Benjamin Kosiborod's warmup3
 */
size_t file_length(FILE *file)
{
    size_t initPos = ftell(file);    // Current position, which is the beginning of the file, before the first character
    fseek(file, 0, SEEK_END);        // Go to end of the file
    size_t fileLength = ftell(file); // read the position which is the size, because the position is at the end of the file, behind all the characters
    fseek(file, initPos, SEEK_SET);  // restore original position, so that later I can read the file from the beginning
    return fileLength;               // return the length of the file
}

/**
 * @brief Extracts a portion of a given char array and returns that portion
 * Includes the character at index @param start, but excludes the character at index @param end
 * 
 * @invariant assumes the given char array has a null character ('\0') at the end
 * 
 * @param start the index from which to start the copy (inclusive)
 * @param end the index at which to end the copy (exclusive)
 * @param array the char array from which to extract a subset/sub-array
 * @return char* a subset/sub-array of the given array
 */
char *copySubArray(int start, int end, char *array)
{
    // first, determine the size of the given array
    size_t givenSize = strlen(array);

    /**
     * @note now that we are have the size of the array, make sure @param start and @param end are within 
     * 0 - givenSize, and that @param start comes before @param end. Otherwise terminate the program
     */
    if (!(start >= 0 && start < givenSize && end > 0 && end <= givenSize && start < end))
    {
        println("Cannot copy sub-array: make sure the start and end index are within the array, and that the start index is before the end index!");
        exit(1);
    }

    // now we are ready to process the sub-array. First create a new array of appropriate size
    char *temp = new char[end - start + 1];

    // next, populate the new array with the values of the given array at the appropriate indices
    for (int i = start; i < end; i++)
    {
        temp[i - start] = array[i];
    }
    temp[end] = '\0';

    // return the newly created array
    return temp;
}

/**
 * @brief Recognizes if a given element is invalid or not
 * 
 * @invariant assumes the given char array has a null character ('\0') at the end
 * 
 * @param element the element to be tested for validity
 * @return true if the element _is_ invalid
 * @return false if the element is NOT invalid
 */
bool isInvalidElement(char *element)
{
    // start at the beginning of the element
    size_t index = 0;
    // skip all the whitespace before the start of the element
    while (element[index] == ' ')
    {
        index++;
    }
    // if the first character is a quote
    if (element[index] == '"')
    {
        // go to the character after the quote
        index++;
        // go to the next character until the next quote
        while (element[index] != '"')
        {
            index++;
        }
        // check that we are not at the end, and if we are return false
        if (element[index] == '\0')
        {
            return false;
        }
        // otherwise, go to the character after the close quote
        index++;
        // there should only be whitespace starting at this character until the end, so skip to the end
        while (element[index] == ' ')
        {
            index++;
        }
        // if we're at the end, then the element is valid
        if (element[index] == '\0')
        {
            return false;
        }
        // otherwise, if we're not at the end, the element is invalid
        // as it should not have spaces between the characters
        else
        {
            return true;
        }
    }
    // otherwise, if the first character is something other than a quote
    else
    {
        // go to the next character
        index++;
        // go to the next space or the end of the element
        while (element[index] != ' ' && element[index] != '\0')
        {
            index++;
        }
        // if we're at the end, then the element is valid
        if (element[index] == '\0')
        {
            return false;
        }
        // go to the character after the space, if we are not at the end
        index++;
        // there should only be whitespace starting at this character until the end, so skip to the end
        while (element[index] == ' ')
        {
            index++;
        }
        // if we're at the end, then the element is valid
        if (element[index] == '\0')
        {
            return false;
        }
        // otherwise, if we're not at the end, the element is invalid
        // as it should not have spaces between the characters
        else
        {
            return true;
        }
    }
}

/**
 * @brief Determines the number of columns in a given line
 * 
 * @param line a char array that represents a line in the schema
 * @return size_t the number of columns in the given line
 */
size_t numCols(char *line)
{
    bool open = false;             // whether there is a currently open bracket, meaning  we are currently reading an element in the schema
    bool readingString = false;    // whether we are currently reading inside quotes i.e. inside a multi-word String
    size_t charNum = strlen(line); // the number of characters in the line we are reading
    size_t colNum = 0;             // the current number of columns seen
    size_t startOfElement = 0;     // the index of the first character of the element we are currently reading
    size_t endOfElement = 0;       // the index of the closing bracket of the element we are currently reading
    // Column** columns = new Column*[columns->getSize()]

    // for each character in the line
    for (int i = 0; i < charNum; i++)
    {
        // if we are not currently reading an element and the current character is an opening bracket
        if (!open && line[i] == '<')
        {
            open = true;            // since we found an opening bracket, set open to true, as we are currently reading an element
            startOfElement = i + 1; // set the startOfElement to the next character, as that is the index of the first character in the element we are reading
        }

        // if we are not currently reading an element and the next character is not an open bracket
        // then return 0 columns, as this is a misformed schema
        else if (!open && line[i] != ' ')
        {
            return 0;
        }

        // if we are currently reading an element that is not a string and we're not at the end of the element
        // if we run into an open bracket outside a string, we throw out the whole line, so we return 0 columns
        else if (open && !readingString && line[i] == '<')
        {
            return 0;
        }

        // otherwise, if we are currently reading an element, and that element is not a string, and we find a closing bracket
        else if (open && !readingString && line[i] == '>')
        {
            open = false;     // we set open to false since we are done reading the element
            endOfElement = i; // we set the end of the element to the index of the closing bracket
            // if the element is invalid, then the whole row is invalid, so return 0 columns
            if (isInvalidElement(copySubArray(startOfElement, endOfElement, line)))
            {
                return 0;
            }
            colNum++; // this column is fine, so add 1 to the number of columns in this row
        }

        // we see "" and we are currently not reading a string so this is the start of our string element
        // (allows for '>' and '<' included)
        else if (open && !readingString && line[i] == '"')
        {
            readingString = true;
        }
        // we see "" and we are currently reading a string so this is the end of our string element
        else if (open && readingString && line[i] == '"')
        {
            readingString = false;
        }
    }
    return colNum;
}

/**
 * @brief checks if the given element is of type float
 * 
 * @invariant assumes the given char array has a null character ('\0') at the end
 * 
 * @param element the element to be checked for type float
 * @return true if the element is a float
 * @return false if the element is NOT a float
 */
bool isTypeFloat(char *element)
{
    bool foundDot = false; // once the dot has been found, set flag to true to make sure there aren't 2 dots

    // skip to the first non-space character
    size_t index = 0;
    while (element[index] == ' ')
    {
        index++;
    }

    // now we are at the first non-space index, so check if there is a sign
    // and if there is, then go to the next character
    if (element[index] == '+' || element[index] == '-')
    {
        index++;
    }

    // this character can be a dot, so if it is go to the next one
    if (element[index] == '.')
    {
        index++;
        foundDot = true;
    }

    // this character and any number of next characters must be digits, so keep
    // going to the next character until it is not a digit
    while (isdigit(element[index]))
    {
        index++;
    }

    // this character is either a dot, or a whitespace
    // if it is a dot, then keep going until we get to the next whitespace
    if (element[index] == '.' && !foundDot)
    {
        index++;
        while (isdigit(element[index]))
        {
            index++;
        }
    }

    // now the current index should be a whitespace, so keep going until the end of the element
    while (element[index] == ' ')
    {
        index++;
    }

    // now, we should be at the end. If we are not at the end,
    // then this element is not a float and return false.
    // otherwise, if we are at the end, return true
    if (element[index] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief checks if the given element is of type int
 * 
 * @param element the element, represented as a char array, to check for int type
 * @return true if the type of the element is int
 * @return false if the type of the element is NOT int
 */
bool isTypeInt(char *element)
{
    // skip to the first non-space character
    size_t index = 0;
    while (element[index] == ' ')
    {
        index++;
    }

    // now we are at the first non-space index, so check if there is a sign
    // and if there is, then go to the next character
    if (element[index] == '+' || element[index] == '-')
    {
        index++;
    }

    // make sure that the character is a digit, and if it is,
    // then keep going to the next character until the first
    // non-digit
    while (isdigit(element[index]))
    {
        index++;
    }

    // now, this character and the rest should all be whitespace
    while (element[index] == ' ')
    {
        index++;
    }

    // now, we should be at the end. If we are not at the end,
    // then this element is not an int and return false.
    // otherwise, if we are at the end, return true
    if (element[index] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Determines if the given element is of type bool i.e. if it is a 0 or a 1
 * 
 * @param element the element to be determined if bool
 * @return true if the element is a bool
 * @return false if the element is NOT a bool
 */
bool isTypeBool(char *element)
{
    size_t index = 0; // we start at the beginning of the element

    // first skip to the first non-space character
    while (element[index] == ' ')
    {
        index++;
    }

    // now we are at the first non-space character, so check that it is either 0 or 1
    // otherwise, return false
    if (!(element[index] == '0' || element[index] == '1'))
    {
        return false;
    }

    // go to the next character
    index++;

    // make sure all characters after the 0/1 are spaces
    while (element[index] == ' ')
    {
        index++;
    }

    // if we are at the end, then it is a valid bool, otherwise
    // if there is another character other than the null character,
    // then this is not a bool, so return false
    if (element[index] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

// processes what is found in between < > and determines if it is a bool, int, float, or string
// if it is not processable (i.e. 1 . 2, then just return the current type)
// returns null if its wrong

/**
 * @brief Determines the type of the element, and returns that type in a char representation
 * with 's' meaning String, 'f' meaning Float, 'i' meaning Int, and 'b' meaning Bool. 
 * 
 * @param element the given element whose type we want to determine
 * @return char a char representation of the element's type
 * @return NULL if the element is invalid/poorly formed
 */
char processType(char *element)
{
    // if the element is invalid, return null
    if (isInvalidElement(element))
    {
        return NULL;
    }
    // if the element is not invalid, return what type it is based on the helper functions
    else
    {
        if (isTypeBool(element))
        {
            return 'b';
        }
        else if (isTypeInt(element))
        {
            return 'i';
        }
        else if (isTypeFloat(element))
        {
            return 'f';
        }
        else
        {
            return 's';
        }
    }
}

/**
 * @brief defines all the column types in the given line based on the spec of the assignment
 * 
 * @param coltypes the current types of the columns
 * @param columns the columns in our current understanding of the schema
 * @param line one row in the schema
 * @return char* the column types, represented in array form
 * @return an array of Columns, representing the columns in the file
 */
char *defineLine(char *coltypes, char *line)
{
    bool open = false;                                  // whether there is a currently open bracket, meaning  we are currently reading an element in the schema
    bool readingString = false;                         // whether we are currently reading inside quotes i.e. inside a multi-word String
    size_t charNum = strlen(line);                      // the number of characters in the line we are reading
    size_t currentcol = 0;                              // the current column in the line that we are reading
    size_t startOfElement = 0;                          // the index of the first character of the element we are currently reading
    size_t endOfElement = 0;                            // the index of the closing bracket of the element we are currently reading
    char *currentcoltypes = new char[strlen(coltypes)]; // the column types found based on reading this line
    // Column** columns = new Column*[columns->getSize()]

    // for each character in the line
    for (int i = 0; i < charNum; i++)
    {
        // if we are not currently reading an element and the current character is an opening bracket
        if (!open && line[i] == '<')
        {
            open = true;            // since we found an opening bracket, set open to true, as we are currently reading an element
            startOfElement = i + 1; // set the startOfElement to the next character, as that is the index of the first character in the element we are reading
        }

        // if we are not currently reading an element and the next character is not an open bracket
        // then throw out the line, as this is a misformed schema
        // i.e. return the given coltypes
        else if (!open && line[i] != ' ')
        {
            return coltypes;
        }

        // if we are currently reading an element that is not a string and we're not at the end of the element
        // if we run into an open bracket outside a string, we throw out the whole line, so we return the coltypes we were given
        else if (open && !readingString && line[i] == '<')
        {
            return coltypes;
        }

        // otherwise, if we are currently reading an element, and that element is not a string, and we find a closing bracket
        else if (open && !readingString && line[i] == '>')
        {
            open = false;     // we set open to false since we are done reading the element
            endOfElement = i; // we set the end of the element to the index of the closing bracket
            // set the current column type to whatever the element type is, if that is appropriate based on the spec
            char tempType = processType(copySubArray(startOfElement, endOfElement, line));
            if (currentcoltypes[currentcol] != 's')
            {
                if (tempType == 's')
                {
                    currentcoltypes[currentcol] = 's';
                }
                else if (tempType == 'f')
                {
                    currentcoltypes[currentcol] = 'f';
                }
                else if (tempType == 'i')
                {
                    if (currentcoltypes[currentcol] == 'f')
                    {
                        currentcoltypes[currentcol] == 'i';
                    }
                }
            }
            currentcoltypes[currentcol] = processType(copySubArray(startOfElement, endOfElement, line));
            currentcol++; // now we're on the next column
        }

        // we see "" and we are currently not reading a string so this is the start of our string element
        // (allows for '>' and '<' included)
        else if (open && !readingString && line[i] == '"')
        {
            readingString = true;
        }
        // we see "" and we are currently reading a string so this is the end of our string element
        else if (open && readingString && line[i] == '"')
        {
            readingString = false;
        }
    }
    return currentcoltypes;
}

/**
 * @brief Determines the number of columns in the schema and their type
 * 
 * @param fileContents a char array of all the charcters in the schema file
 * 
 * @return an array of columns 
 */
Column **defineSchema(char *fileContents)
{
    int lines = 0;            // the number of lines in the schema that have been parsed
    int numParsedChars = 0;   // the number of characters that have been parsed
    int startOfLine = 0;      // the index in the fileContents char array that represents the start of a line
    size_t maxColNum = 0;     // the maximum number of columns found in the schema
    size_t currentColNum = 0; // the number of columns in the line that was just parsed
    // iterates through the fileContents until the end, or until 500 lines have been parsed
    while (fileContents[numParsedChars] != '\0' && lines <= 500)
    {
        // if we're at the end of the current line
        if (fileContents[numParsedChars] == '\n')
        {

            char *line = new char[numParsedChars - startOfLine];            // create a new char array of the same size as the length of the current line
            line = copySubArray(startOfLine, numParsedChars, fileContents); // sets line to a char array that contains all the chars in the line
            currentColNum = numCols(line);                                  // sets the number of columns in the line just parsed

            // if the max column number so far is less than the number of columns in this line,
            // then set the max column number to the numnber of columns in the line just parsed
            if (maxColNum < currentColNum)
            {
                maxColNum = currentColNum;
            }

            // set the start of the next line to the number of already parsed characters, plus 1
            // because the number of parsed characters is at the index in the fileContents
            // that represents the end of the current line, so we need to set it to the beginning of the
            // next line, rather than the end of the just parsed line
            startOfLine = numParsedChars + 1;

            // increments the numnber of lines already parsed, as we just finished parsing the current line
            line++;
        }
        // increments the number of already parsed characters, as we just finished parsing one
        numParsedChars++;
    }
    // for storing the coltypes as a char before initializing the columns
    // b = bool, i = int, f = float, s = string
    char *coltypes = new char[maxColNum];

    // Column** columns = new Column*[maxColNum];

    // assume everything is a bool initially
    // sets all the columns to bool type initally
    for (int i = 0; i < maxColNum; i++)
    {
        coltypes[i] = 'b';
    }
    // using the file to start identifying the schema now
    // set lines back to 0, as this now represents the number of lines that have been
    // used to define the schema
    lines = 0;

    numParsedChars = 0; // reset num parsed chars back to 0, as we need to parse the file again to define the schema
    startOfLine = 0;    // set start of line to 0, as we are at the start of the first line in the file to be parsed to define the schema
    // iterates through the fileContents until the end, or until 500 lines have been parsed
    while (fileContents[numParsedChars] != '\0' && lines <= 500)
    {
        // if we're at the end of the current line
        if (fileContents[numParsedChars] != '\n')
        {
            char *line = new char[numParsedChars - startOfLine];            // create a new char array of the same size as the length of the current line
            line = copySubArray(startOfLine, numParsedChars, fileContents); // sets line to a char array that contains all the chars in the line
            coltypes = defineLine(coltypes, line);                          // sets the column types found in the schema based on the given line
            // columns = defineSchema(columns, line);
        }
    }

    // return columns;
}

int main(int argh, char **argv)
{
    // file and flags to keep track of for later outputting
    char *filename = '\0';
    int from = -1;
    int len = -1;
    bool ftype = false;
    int typeuint = -1;
    bool fidx = false;
    int idxcol = -1;
    int idxoff = -1;
    bool fmissing = false;
    int miscol = -1;
    int misoff = -1;

    // parsing the command line arguments:
    // checks if validity of flag and if flag has been seen
    for (int i = 1; i < argh; i++)
    {
        if (checkflag(i, argv[i], argh, "-f", 1) && filename == '\0')
        {
            i++;
            filename = argv[i];
            println("file found");
        }
        else if (checkflag(i, argv[i], argh, "-from", 1) && from == -1)
        {
            i++;
            from = convertParamToInt(argv[i]);
        }
        else if (checkflag(i, argv[i], argh, "-len", 1) && len == -1)
        {
            i++;
            len = convertParamToInt(argv[i]);
        }
        else if (checkflag(i, argv[i], argh, "-print_col_type", 1) && !ftype)
        {
            i++;
            typeuint = convertParamToInt(argv[i]);
            ftype = true;
        }
        else if (checkflag(i, argv[i], argh, "-print_col_idx", 2) && !fidx)
        {
            i++;
            idxcol = convertParamToInt(argv[i]);
            i++;
            idxoff = convertParamToInt(argv[i]);
            fidx = true;
        }
        else if (checkflag(i, argv[i], argh, "-is_missing_idx", 2) && !fmissing)
        {
            i++;
            miscol = convertParamToInt(argv[i]);
            i++;
            misoff = convertParamToInt(argv[i]);
            fmissing = true;
        }
        else
        {
            println("Too many or too few arguments!");
            exit(1);
        }

        // parsing the file to find schema
        // open file
        FILE *file = fopen(filename, "r");
        if (file == nullptr)
        {
            println("There was a problem opening the file. Make sure you typed the name of the file correctly, with the file extension!");
            exit(1);
        }
        // find the total length of the file
        size_t fileLength = file_length(file);
        // initialize where the file will go
        char *fileContents = new char[fileLength];
        // read the file into fileContents
        fread(fileContents, 1, fileLength, file);
    }
}