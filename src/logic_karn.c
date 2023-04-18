#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "logic_run.h"

int logic_karn_1_gray[] = {0b0,  0b1};
int logic_karn_2_gray[] = {0b00, 0b01, 0b11, 0b10};

void logic_karn_render(bool* karn, int x, int y)
{
    bool *c = karn;

    printf("|   ");

    for (int iy = 0; iy < y; iy++)
    {
        if (y == 2)
        {
            printf("| %d ", (logic_karn_1_gray[iy] & (1)));
        }
        else
        {
            printf("|%d%d ", (logic_karn_2_gray[iy] & (1 << 0)), ((logic_karn_2_gray[iy] & (1 << 1)) / 2));
        }
    }

    printf("|\n");
    
    for (int ix = 0; ix < x; ix++)
    {
        if (x == 2)
        {
            printf("| %d ", (logic_karn_1_gray[ix] & (1)));
        }
        else
        {
            printf("|%d%d ", (logic_karn_2_gray[ix] & (1 << 0)), ((logic_karn_2_gray[ix] & (1 << 1)) / 2));
        }

        for (int iy = 0; iy < y; iy++)
        {
            if (*c == 1)
            {
                printf("| 1 ");
            }
            else
            {
                printf("|   ");
            }

            c++; // lmao
        }

        printf("|\n");
    }

    printf("\n"); // just nicely end it
}

bool* logic_karn_run(char* equ, int args, int *x, int *y)
{
    if (args > 4)
    {
        printf("\nMAX 4 ARGS FOR KARNAU\n");
        return NULL;
    }
    if (args < 2)
    {
        printf("\nMIN 2 ARGS FOR KARNAU\n");
        return NULL;
    }

    *x = (args == 4) ? 4 : 2;
    *y = (args >= 3) ? 4 : 2;

    printf("X: %d\nY: %d\n\n", *x, *y);

    bool *data = malloc((*x) * (*y));
    bool *dp   = data;

    bool bargs[4];

    for (int ix = 0; ix < *x; ix++)
    {
        if (*x == 2)
        {
            bargs[((*y) / 2) + 0] = logic_karn_1_gray[ix];
        }
        else
        {
            bargs[((*y) / 2) + 0] = logic_karn_2_gray[ix] & (1 << 0);
            bargs[((*y) / 2) + 1] = logic_karn_2_gray[ix] & (1 << 1);
        }

        for (int iy = 0; iy < *y; iy++)
        {
            if (*y == 2)
            {
                bargs[0] = logic_karn_1_gray[iy];
            }
            else
            {
                bargs[0] = logic_karn_2_gray[iy] & (1 << 0);
                bargs[1] = logic_karn_2_gray[iy] & (1 << 1);
            }

            *dp = logic_run_runner(equ, args, bargs);
            printf("\nKARNAU: %d\n\n", *dp);
            dp++;
        }
    }

    return data;
}