// Sun Aug 26 20:05:01 UTC 2018

/* runword.c */

#include "dict.h"

void runword(void) {
    int place = locate();
    if ((place != 0) & (place < (entries - 1))) {
        return;
    }
}
