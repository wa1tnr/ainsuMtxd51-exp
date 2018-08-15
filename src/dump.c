/* dump.c */
/* 15 Aug 2018 20:21 UTC */
/* wa1tnr, Connecticut USA */
/* LICENSE: LGPL v2.1 */

#include "driver_examples.h" // "examples/driver_examples.h"
#include "common.h"

#include <string.h>

void say_something(void) { }

// #ifdef NOT_DEFINED_NOW_BUT
/* dump 16 bytes of RAM in hex with ascii on the side */
uint8_t* srdump(void) {
    char buffer[5] = "";
    strcpy(buffer, "SeVe") ;
    uint8_t *ram;
    // ram = (uint8_t *)7; // good - don't erase

    // int p = 16397; // 16384 is 0x4000
    // int p = 16197; // 16384 is 0x4000
    int p = 16397; // 16384 is 0x4000

    // ram = (uint8_t *)p; // ptr to address p
    // strcpy(buffer, (char *) p);
    // io_write(io, (uint8_t *)buffer, 1); // compiles cleanly

    for (int adrs = p; adrs < (p + 0x1000); adrs++) {
        ram = (uint8_t *)adrs; // ptr to address
        strcpy(buffer, (char *) adrs);
        // int w = strtol(buffer);
        // ram = w; // fake just to quiet compiler about unused 
        io_write(io, (uint8_t *)buffer, 1); // compiles cleanly

        for (volatile int j=2100; j>0; j--) { } // delay
    }


    return ram;
    // char *ram;
    // ram = (uint8_t *)7;

//  ram = 7;
//  blink_two();
 // int p = pop();
 // ram = (char*)p;

//  io_write(io, (uint8_t *)buffer, 1); // compiles cleanly

// sprintf(buffer, "%4x", p);
/*
  Serial.print(buffer);
  Serial.print("   ");
  for (int i = 0; i < 16; i++) {
    char c = *ram++;
    sprintf(buffer, " %2x", (c & 0xff));
    Serial.print(buffer);
  }
  ram = (char*)p;
  Serial.print("   ");
  for (int i = 0; i < 16; i++) {
    buffer[0] = *ram++;
    if (buffer[0] > 0x7f || buffer[0] < ' ') buffer[0] = '.';
    buffer[1] = '\0';
    Serial.print(buffer);
  }
  push(p + 16);
*/
}


// #endif // #ifdef NOT_DEFINED_NOW_BUT
