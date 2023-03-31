 // This header file was generated on
// z5214348.web.cse.unsw.edu.au/header_generator/

// header guard: https://en.wikipedia.org/wiki/Include_guard
// This avoids errors if this file is included multiple times
// in a complex source file setup

#ifndef LOGIC_SYMB_H
#define LOGIC_SYMB_H

// #includes

#include <stdint.h>
#include <stdbool.h>

#define logic_symb_and '^'
#define logic_symb_or  'v'
#define logic_symb_xor 'o'
#define logic_symb_not '-'

// arg positions
// bit 1 - left, bit 2 - right

#define logic_symb_args_and 1 + 2
#define logic_symb_args_or  1 + 2
#define logic_symb_args_not 0 + 2
#define logic_symb_args_xor 1 + 2

// Functions

void logic_symbs_args_calc(int args, bool *left, bool *right);
int logic_symbs_args_num(int args);

// End of header file
#endif
