#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "logic_ops.h"
#include "logic_symb.h"

void logic_run_remove_char(char* str, char* index)
{
    memmove(index, index + 1, strlen(str) - (str - index));
}

void logic_run_replace_char(char* str, char old, char new)
{
    char* strp = str;

    while (*(++strp) != '\0')
    {
        *strp = (*strp == old) ? new : *strp;
    }
}

void logic_run_eval(char* sym)
{
    char  cop = *sym;
    bool  (*fop)(bool, bool);
    char  carg1, carg2;
    bool  arg1,  arg2;
    int   args;
    bool  result;

    switch (cop)
    {
        case (logic_symb_and):
            fop = &logic_ops_and;
            args = logic_symbs_args_num(logic_symb_args_and);
            break;
        case (logic_symb_or):
            fop = &logic_ops_or;
            args = logic_symbs_args_num(logic_symb_args_or);
            break;
        case (logic_symb_not):
            fop = &logic_ops_not;
            args = logic_symbs_args_num(logic_symb_args_not);
            break;
        case (logic_symb_xor):
            fop = &logic_ops_xor;
            args = logic_symbs_args_num(logic_symb_args_xor);
            break;
        default:
            printf("INCORCT VALUE OMG FU %c\n", cop);
            return;
    }

    arg1 = false; // always default to false
    arg2 = false;

    switch (args)
    {
        case (2):
            arg2 = '0' - *(sym - 1); // convert '0' / '1' to 0 / 1
        case (1):
            arg1 = '0' - *(sym + 1); // i <3 pointer math
        default:
            break;
    }

    if (*(sym + 1) == logic_symb_not)
    {
        logic_run_remove_char(sym, sym + 1);
        arg1 = !('0' - *(sym + 1));
    }

    result = (*fop)(arg1, arg2); // its fine if we pass too many args

    switch (args)
    {
        case (2):
            logic_run_remove_char(sym - 1, sym - 1); // we should techinically use the origin, but we dont have that and since it doesnt realloc, it doesnt matter
            sym--; // everyhing has been shifted back
        case (1):
            logic_run_remove_char(sym, sym + 1);
        default:
            *sym = '0' + result; // covert 0 / 1 to '0' / '1'
    }
}

char* logic_run_get_deepest(char* str)
{
    int   cdepth = 0;
    char* maxpoint = str;
    int   maxdepth = 0;

    str--;

    while (*(++str) != '\0')
    {
        if (*str == '(')
        {
            cdepth++;

            if (cdepth > maxdepth)
            {
                maxdepth = cdepth;
                maxpoint = str + 1;
            }
        }
        else if (*str == ')')
        {
            cdepth--;
        }
    }

    return maxpoint;
}

void logic_run_remove_useless(char *str)
{
    char *pstr = str - 1;

    while (*(++pstr) != '\0')
    {
        if ((*pstr == '(') && (*(pstr + 2) == ')'))
        {
            logic_run_remove_char(str, pstr + 2);
            logic_run_remove_char(str, pstr);
        }
    }
}

bool logic_run_runner(char* equ, int argc, bool* argv)
{
    logic_ops_and(true, true);

    int equsize = strlen(equ) + 1;

    char* nequ = malloc(equsize + 1); // serve as a buffer for bracket remover so that it dont segfault on bad input
    memcpy(nequ, equ, equsize);

    printf("ORIGINAL STRING: %s\n", nequ);

    for (char i = 'a'; (i - 'a') < argc; i++)
    {
        logic_run_replace_char(nequ, (i),       (argv[i - 'a'] + '0')); // lower case
        logic_run_replace_char(nequ, (i - 32),  (argv[i - 'a'] + '0')); // upper case
    }

    printf("REPLACED STRING: %s\n", nequ);

    while (nequ[1] != '\0') // when 1 char long we know it done
    {
        logic_run_remove_useless(nequ);

        char *deepest = logic_run_get_deepest(nequ);

        if (*deepest == '0' || *deepest == '1')
        {
            deepest++;
        }

        logic_run_eval(deepest);

        printf("DIS   ITERATION: %s\n", nequ);
    }

    bool ret = '0' - *nequ;

    free(nequ);

    return ret;
}