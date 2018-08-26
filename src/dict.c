// Sun Aug 26 19:45:14 UTC 2018

/* dict.c */

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
