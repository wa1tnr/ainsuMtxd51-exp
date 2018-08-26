// Sun Aug 26 21:43:30 UTC 2018

/* runword.c */

#include <atmel_start.h>
#include "dict.h"
#include "serial_io.h"
#include "stack_ops.h"

void runword(void) {
    int place = locate();
    io_write(io,     (uint8_t *)" ~runword place echo~ ", 22);
    push(place);
    io_write(io, (uint8_t *)    " ~runword dot~ ", 15);
                             /*  1234567890123456789012345678901234567890 */
    dot();
    if ((place != 0) & (place < (entries - 1))) {
        io_write(io, (uint8_t *)" ~runword place~ ", 17);
        return;
    }
    return;
}
