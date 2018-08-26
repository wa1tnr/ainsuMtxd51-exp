// Sun Aug 26 20:40:59 UTC 2018

/* dict.c */

// typedef found in dict.h rather than here
#include "dict.h"
#include <string.h>
#include "common.h"
#include "getKey.h"
#include "serial_io.h"
#include "stack_ops.h"

/* NAMED creates a string in flash */
#define NAMED(x, y) const char x[]=y

/* buffer required for strings read from flash */
char namebuf[maxtib];

/* destructively display top of stack, decimal */
NAMED(_dott, ".");
void dott(void) { // earlier dot() word bypassed temporarily
    io_write(io, (uint8_t *)" ~dot~", 7);
}

NAMED(_nop, "nop"); // swapped _name with _nopp
void nop(void) { }

NAMED(_drop, "drop");
void drop(void) {
    io_write(io, (uint8_t *)" ~drop~", 7);
}

/* exchange top two stack items */
NAMED(_swap, "swap");
void swap(void) {
  int a;
  int b;
  a = pop();
  b = pop();
  push(a);
  push(b);
}

/* display whole stack, decimal */
NAMED(_dotS, ".s");
void dotS(void) {
    for (int i = 0; i < STKSIZE; i++) dot();
}

NAMED(_nopp, " ");  // swapped _name with _nop
void nopp(void) { }

/* table of names and function addresses in flash */
// extern const entry dictionary[];
const entry dictionary[] = { // populated just enough to test basics
    { _nop,       nop    },
    { _dott,      dott   },
    { _drop,      drop   },
    { _swap,      swap   },
    { _dotS,      dotS   },
    { _nopp,      nopp   },
};

/* Number of words in the dictionary */
const int entries = sizeof dictionary / sizeof dictionary[0];

/* Find a word in the dictionary, returning its position */
int locate() {
  for (int i = entries - 1; i >= 0; i--) {
    strcpy(namebuf, dictionary[i].name);
 // int  strcmp (const char *, const char *);
    if (!strcmp(tib, namebuf)) return i;
  }
  //  5 #define LOCATE_BOUNDS_ERR -11
  return LOCATE_BOUNDS_ERR ; // return 0;
}

