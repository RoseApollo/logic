 // This header file was generated on
// z5214348.web.cse.unsw.edu.au/header_generator/

// header guard: https://en.wikipedia.org/wiki/Include_guard
// This avoids errors if this file is included multiple times
// in a complex source file setup

#ifndef LOGIC_KARN_H
#define LOGIC_KARN_H

// #includes

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "logic_run.h"

// Functions

void logic_karn_render(bool* karn, int x, int y);
bool* logic_karn_run(char* equ, int args, int *x, int *y);

// End of header file
#endif
