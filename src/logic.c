#include <stdio.h>
#include <stdbool.h>

#include "logic_run.h"
#include "logic_karn.h"

int main(int argc, char** argv)
{
    int x, y;
    char d[] = "((Bo((-A^-C)o(A^C)))v(A^B^C))^((DvA)o(-D^C))";

    bool* c = logic_karn_run(d, 4, &x, &y);
    logic_karn_render(c, x, y);

    return 0;
}