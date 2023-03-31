#include <stdio.h>
#include <stdbool.h>

bool logic_ops_and(bool a, bool b)
{
    return a && b;
}

bool logic_ops_or(bool a, bool b)
{
    return a || b;
}

bool logic_ops_not(bool a)
{
    return !a;
}

bool logic_ops_xor(bool a, bool b)
{
    return logic_ops_and(logic_ops_or(a, b), logic_ops_not(logic_ops_and(a, b)));
}