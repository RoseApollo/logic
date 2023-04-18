#include <stdio.h>
#include <stdbool.h>

#include "logic_run.h"
#include "logic_karn.h"

int main(int argc, char** argv)
{
    int x, y;
    char d[] = "(-(AvB)v-(A^B))^((-A^B)v((AvB)^(-Bv-A)))";

    bool* c = logic_karn_run(d, 2, &x, &y);
    logic_karn_render(c, x, y);

    return 0;
}