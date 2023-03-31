 // This header file was generated on
// z5214348.web.cse.unsw.edu.au/header_generator/

// header guard: https://en.wikipedia.org/wiki/Include_guard
// This avoids errors if this file is included multiple times
// in a complex source file setup

#ifndef LOGIC_RUN_H
#define LOGIC_RUN_H

// #includes

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "logic_ops.h"
#include "logic_symb.h"

// Functions

void logic_run_replace_char(char* str, char old, char new);
bool logic_run_runner(char* equ, int argc, bool* argv);

// End of header file
#endif
