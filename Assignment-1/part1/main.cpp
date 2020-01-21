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

int main(int argh, char **argv)
{
    // file and flags to keep track of for later outputting
    String *file = new String("");
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
        if (checkflag(i, argv[i], argh, "-f", 1) && file->equals(new String("")))
        {
            i++;
            file = new String(argv[i]);
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
    }
}