#include <stdint.h>
#include <stdbool.h>



void logic_symbs_args_calc(int args, bool *left, bool *right)
{
    *left  = args & (1 << 0);
    *right = args & (1 << 1);
}

int logic_symbs_args_num(int args)
{
    bool left, right;

    logic_symbs_args_calc(args, &left, &right);

    return left + right;
}