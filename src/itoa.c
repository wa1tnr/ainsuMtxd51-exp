// Sat Aug 25 19:30:14 UTC 2018

/*
  LICENSE: LGPL v2.1 Arduino LLC > Adafruit.com > you and me ;)

  adopted for ainsMtxd51 by wa1tnr 25 August 2018

  .arduino15/packages/adafruit/hardware/samd/1.2.1/cores/arduino/itoa.c

  Copyright (c) 2014 Arduino LLC.  All right reserved.
*/

#include <atmel_start.h>
#include "serial_io.h"

char pr_strn[63]; // print string - weak naming.  review. TODO wa1tnr
int input_intgr = 0; // input integer - also a weak name. ;)  TODO wa1tnr

void prelude_to_cleo(void) {
    for (int jk = 7; jk > 0; jk--) {
        io_write(io, (uint8_t *)"m", 1);
    }
}

void call_me_now_ms_cleo(void) { // call me now for your free reading
    prelude_to_cleo(); // test basic io_write() functionality
}

/* reverse:  reverse string s in place */
/*
static void reverse(char s[]) {
  int i, j ;
  char c ;
}
*/

/* itoa:  convert n to characters in s */
extern void itoa( int n, char s[] ) {
/*
    int i, sign ;
*/
}

/*
  .arduino15/packages/adafruit/hardware/samd/1.2.1/cores/arduino/itoa.c

  Copyright (c) 2014 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
