// Sun Aug 26 21:43:30 UTC 2018

/* runword.c */

#include <atmel_start.h>
#include "dict.h"
#include "serial_io.h"

void runword(void) {
    int place = locate();
    io_write(io,     (uint8_t *)" ~runword place echo~ ", 22);
    if ((place != 0) & (place < (entries - 1))) {
        return;
    }
    return;
}
