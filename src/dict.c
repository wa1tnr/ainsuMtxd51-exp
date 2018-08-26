// Sun Aug 26 20:40:59 UTC 2018

/* dict.c */

// typedef found in dict.h rather than here
#include "dict.h"

/* NAMED creates a string in flash */
#define NAMED(x, y) const char x[]=y

NAMED(_dott, ".");
void dott(void) { // earlier dot() word bypassed temporarily
    // io_write(io, (uint8_t *)" ~dot~", 7);
}

NAMED(_nopp, "nop");
void nopp() { }

NAMED(_nop, " ");
void nop() { }

NAMED(_swap, "swap");
void swap() {
    // io_write(io, (uint8_t *)" ~swap~", 7);
}

/* table of names and function addresses in flash */
// extern const entry dictionary[];
const entry dictionary[] = { // populated just enough to test basics
    { _nop,       nop    },
    { _swap,      swap   },
    { _dott,      dott   },
    { _nopp,      nopp   },
};
