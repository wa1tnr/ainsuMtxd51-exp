// Sun Aug 26 21:43:30 UTC 2018

/* runword.c */

#include <atmel_start.h>
#include "dict.h"
#include "serial_io.h"
#include "stack_ops.h"
#include "readword.h"

void runword(void) {
    int place = locate();
    io_write(io,     (uint8_t *)" ~runword place echo~ ", 22);
    push(place);
    io_write(io, (uint8_t *)    " ~runword dot~ ", 15);
                             /*  1234567890123456789012345678901234567890 */
    dot();
    // 5 #define LOCATE_BOUNDS_ERR -11
    if ((place != LOCATE_BOUNDS_ERR) & (place < (entries - 1))) { // if ((place != 0) & ..
        io_write(io, (uint8_t *)" ~runword place fgh~ ", 20);
        push(place); dot();
        dictionary[place].function(); // meat on the bone
        _ok();
        return;
    }

    if (isNumber()) {
        push(number()); // pivotal change
        io_write(io, (uint8_t *)" ~runword isNumber 773~ ", 24);
        _ok();
        return;
    }
    // Serial.println("?");
}
