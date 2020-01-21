#include "string.h"
#include "helper.h"

// checks if: 1) flag is matched, 2) num of params following flag could be found
bool checkflag(int i, char *arg, int argh, const char *flag, int param)
{
    return strcmp(arg, flag) == 0 && i + param < argh;
}

// converts the char[] into an int if chars are digits; else exit(1)
// by only allowing digits, force everything to be 0+
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

// from Ben's Warmup Exercise 3 code 
size_t file_length(FILE *file)
{
    size_t initPos = ftell(file);    // Current position, which is the beginning of the file, before the first character
    fseek(file, 0, SEEK_END);        // Go to end of the file
    size_t fileLength = ftell(file); // read the position which is the size, because the position is at the end of the file, behind all the characters
    fseek(file, initPos, SEEK_SET);  // restore original position, so that later I can read the file from the beginning
    return fileLength;               // return the length of the file
}

// returns portion of array from index j to index i, not including index i
char* copySubArray(int i, int j, char* array) {
    char *temp = new char[i -j];
    for (int n = j; n < i; n++) {
        temp[n-j] = array[n];
    }
    return temp;
}

// parses through line to determine the num of cols
size_t checkCols(char* line) {
    size_t charnum = strlen(line);
    bool fstart = false;
    bool fcanend = false;
    size_t cols = 0;
    for (int i = 0; i < charnum; i++) {
        if (!fstart && !fcanend && line[i] == '<') {
            fstart = true;
        }
        // end of a col, checks for > char
        // also checks that next char is either ' ', '<' or nothing (ie reached true end of col)
        else if (fstart && fcanend && line[i] == '>' && (i+1 < charnum && (line[i+1] == '<' || line[i+1] == ' ') || i == charnum - 1)) {
            cols++;
            fstart = false;
            fcanend = false;
        }
        else if (fstart && !fcanend && line[i] != ' ') {
            if (line[i] != '>') {
                fcanend = true;
            }
            // checking for a special case of <>>>
            else if (line[i] == '>' && i+1 < charnum && (line[i] != '<' || line[i] != ' ')) {
                fcanend = true;
            }
        }
    }
    return cols;
}

// use this to further define the schema
char* defineSchema(char* coltypes, char* line){

}

void findSchema(char *fileContents) {
    // finds the largest row; stored in colnum
    int lines = 0; int i = 0; int j = 0; size_t colnum = 0; size_t currentcolnum = 0;
    while (fileContents[i]!='\0' && lines <= 500) {
        if(fileContents[i]!='\n') {
            char * line = new char[i-j];
            line = copySubArray(i, j, fileContents);
            currentcolnum = checkCols(line);
            if (colnum < currentcolnum) { 
                colnum = currentcolnum;
            }
        }
    }
    // for storing the coltypes as a char before initializing the columns
    // b = bool, i = int, f = float, s = string
    char * coltypes = new char[colnum];
    // assume everything is a bool initially
    for (int i = 0; i < colnum; i++) {
        coltypes[i] = 'b';
    }
    // using the file to start identifying the schema now
    lines = 0; i = 0; j = 0;
    while (fileContents[i]!='\0' && lines <= 500) {
        if(fileContents[i]!='\n') {
            char * line = new char[i-j];
            line = copySubArray(i, j, fileContents);
            coltypes = defineSchema(coltypes, line);
        }
    }
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
            println("from found");
        }
        else if (checkflag(i, argv[i], argh, "-len", 1) && len == -1)
        {
            i++;
            len = convertParamToInt(argv[i]);
            println("len found");
        }
        else if (checkflag(i, argv[i], argh, "-print_col_type", 1) && !ftype)
        {
            i++;
            typeuint = convertParamToInt(argv[i]);
            ftype = true;
            println("col type found");
        }
        else if (checkflag(i, argv[i], argh, "-print_col_idx", 2) && !fidx)
        {
            i++;
            idxcol = convertParamToInt(argv[i]);
            i++;
            idxoff = convertParamToInt(argv[i]);
            fidx = true;
            println("print col and row found");
        }
        else if (checkflag(i, argv[i], argh, "-is_missing_idx", 2) && !fmissing)
        {
            i++;
            miscol = convertParamToInt(argv[i]);
            i++;
            misoff = convertParamToInt(argv[i]);
            fmissing = true;
            println("print is missing found");
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