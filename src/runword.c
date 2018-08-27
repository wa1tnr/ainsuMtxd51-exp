// Sun Aug 26 21:43:30 UTC 2018

/* runword.c */

#include <atmel_start.h>
#include "dict.h"
#include "serial_io.h"
#include "stack_ops.h"
#include "readword.h"
#include "debugging.h"

void runword(void) {
    int place = locate();
    if ( DEBUG_FORTH_DICT_PRIMITIVES ) {
        io_write(io,     (uint8_t *)" ~runword place echo~ ", 22);
    }
    if ( DEBUG_FORTH_DICT_PRIMITIVES ) {
        io_write(io, (uint8_t *)    " ~runword d0t~ ", 15);
                             /*  1234567890123456789012345678901234567890 */
    }
    if ( DEBUG_FORTH_DICT_PRIMITIVES ) {
        push(place); dot();
    }
    // 5 #define LOCATE_BOUNDS_ERR -11
    if ((place != LOCATE_BOUNDS_ERR) & (place < (entries - 1))) { // if ((place != 0) & ..
        if ( DEBUG_FORTH_DICT_PRIMITIVES ) {
            io_write(io, (uint8_t *)" ~runword place fgh~ ", 20);
        }
        if ( DEBUG_FORTH_DICT_PRIMITIVES ) {
            push(place); dot();
        }
        dictionary[place].function(); // meat on the bone
        _ok();
        return;
    }

    if (isNumber()) {
        push(number()); // pivotal change
        if ( DEBUG_FORTH_DICT_PRIMITIVES ) {
            io_write(io, (uint8_t *)" ~runword isNumber 773~ ", 24);
        }
        _ok();
        return;
    }
    _que(); // Serial.println("?");
}
