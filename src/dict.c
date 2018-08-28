// Tue Aug 28 19:29:30 UTC 2018
// On branch xKM_converser_d51-kk-

/* dict.c */

#include "dict.h"
#include <string.h>
#include "common.h"
#include "getKey.h"
#include "serial_io.h"

#include "stack_ops.h"
#include "math.h"
#include "flashDict.h"
#include "warm.h"
#include "dump.h"

// previous:
// Mon Aug 27 03:53:51 UTC 2018

/* buffer required for strings read from flash */
char namebuf[maxtib];

uint8_t* adrs_ram = 0;

/* destructively display top of stack, decimal */
NAMED(_dott, ".");
void dott(void) { // earlier dot() word bypassed temporarily
    dot(); // io_write(io, (uint8_t *)" ~dot~", 7);
}

// const char x[]=y
const char _nop[2]=" \0";
// NAMED(_nop, " "); // swapped _name with _nopp
void nop(void) { }

NAMED(_nopp, "nop");  // swapped _name with _nop
void nopp(void) { }


void dump(void) { // 28 Aug 19:39 UTC
    adrs_ram = cdump();
    push((uint32_t)adrs_ram); // address of the most recent line dumped
}

void words(void); // forward declaration // 28 Aug 22:35 UTC

/* look in stack_ops.c - for example - to find the
   definitions of most of the earliest dictionary
   entries referred to in the table found below. */

/* table of names and function addresses in flash */
// extern const entry dictionary[];
const entry dictionary[] = {
    { _plus,      plus   },
    { _nop,       nop    },
    { _cr_n,      cr     },
    { _dott,      dott   },
    { _drop,      drop   },
    { _back,      back   },
    { _swap,      swap   },
    { _dotS,      dotS   },
    { _add,       add    },
    { _dump,      dump   },
    { _words,     words  },
    { _warm_,     _warm  },
    { _nopp,      nopp   },
};

/* Number of words in the dictionary */
const int entries = sizeof dictionary / sizeof dictionary[0];

/* Find a word in the dictionary, returning its position */
int locate(void) {
  for (int i = entries - 1; i >= 0; i--) {
    strcpy(namebuf, dictionary[i].name);
    if (!strcmp(tib, namebuf)) return i;
  }
  return LOCATE_BOUNDS_ERR ; // return 0;
}

/* Display all words in dictionary */
void words(void) { // 28 Aug 20:05 UTC
}
