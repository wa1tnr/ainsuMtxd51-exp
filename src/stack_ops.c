/* stack_ops.c */

/* from Shattuck's Tiny interpreter,
   similar to myforth's Standalone Interpreter
   This example code is in the public domain */

/* Data stack for parameter passing
   This "stack" is circular,
   like a Green Arrays F18A data stack,
   so overflow and underflow are not possible
   Number of items must be a power of 2 */

#include <atmel_start.h>
#include "common.h"
#include "itoa.h"
#include "serial_io.h"
#include <string.h>

// const int STKSIZE = 8;
#define STKSIZE 8

// const int STKMASK = 7;
#define STKMASK 7

int stack[STKSIZE];
int p = 0;

/* TOS is Top Of Stack */
#define TOS stack[p]

/* push n to top of data stack */
void push(int n) {
  p = (p + 1)& STKMASK;
  TOS = n;
}

/* return top of stack */
int pop(void) {
  int n = TOS;
  p = (p - 1)& STKMASK;
  return n;
}

/* destructively display top of stack, decimal */
void dot(void) {
    _spc(); _spc(); // print formatting/spacing
    // push(7345280); // could do this here as a test
    int len_pr_strn = 0;
    int popped = pop();
    pr_strn[0] = (uint32_t) "\0";
    input_intgr = popped; // 5280; // feet in a mile
    itoa (input_intgr, pr_strn);
    len_pr_strn = strlen(pr_strn);
    io_write(io, (uint8_t *)pr_strn, len_pr_strn);
    _spc();
}
