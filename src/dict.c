// Mon Aug 27 03:53:51 UTC 2018

/* dict.c */

#include "dict.h"
#include <string.h>
#include "common.h"
#include "getKey.h"
#include "serial_io.h"

#include "stack_ops.h"
#include "math.h"
#include "flashDict.h"

/* buffer required for strings read from flash */
char namebuf[maxtib];

/* destructively display top of stack, decimal */
NAMED(_dott, ".");
void dott(void) { // earlier dot() word bypassed temporarily
    io_write(io, (uint8_t *)" ~dot~", 7);
}

NAMED(_nop, "nop"); // swapped _name with _nopp
void nop(void) { }

NAMED(_nopp, " ");  // swapped _name with _nop
void nopp(void) { }


/* look in stack_ops.c - for example - to find the
   definitions of most of the earliest dictionary
   entries referred to in the table found below. */

/* table of names and function addresses in flash */
// extern const entry dictionary[];
const entry dictionary[] = {
    { _nop,       nop    },
    { _dott,      dott   },
    { _drop,      drop   },
    { _back,      back   },
    { _swap,      swap   },
    { _dotS,      dotS   },
    { _plus,      plus   },
    { _add,       add    },
    { _nopp,      nopp   },
};

/* Number of words in the dictionary */
const int entries = sizeof dictionary / sizeof dictionary[0];

/* Find a word in the dictionary, returning its position */
int locate() {
  for (int i = entries - 1; i >= 0; i--) {
    strcpy(namebuf, dictionary[i].name);
    if (!strcmp(tib, namebuf)) return i;
  }
  return LOCATE_BOUNDS_ERR ; // return 0;
}
