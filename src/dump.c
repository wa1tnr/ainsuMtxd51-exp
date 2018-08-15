/* dump.c */
/* 15 Aug 2018 20:21 UTC */
/* wa1tnr, Connecticut USA */
/* LICENSE: LGPL v2.1 */

#include "driver_examples.h" // "examples/driver_examples.h"
#include "common.h"

#include <string.h>

void say_something(void) { }

#define LBOUND 0x2040
#define UBOUND  0x420

/* dump 16 bytes of RAM in hex with ascii on the side */
uint8_t* srdump(void) {
    char buffer[5] = "";
    strcpy(buffer, "SeVe") ;
    uint8_t *ram;

    // ram = (uint8_t *)7; // good - don't erase

    int p = LBOUND; // 16384 is 0x4000

    // ram = (uint8_t *)p; // ptr to address p
    // strcpy(buffer, (char *) p);
    // io_write(io, (uint8_t *)buffer, 1); // compiles cleanly

    for (int adrs = p; adrs < (p + UBOUND); adrs++) {
        ram = (uint8_t *)adrs; // ptr to address
        if (*ram > 127) io_write(io, (uint8_t *)".", 1);
        if (*ram < 32)  io_write(io, (uint8_t *)".", 1);
        if ((*ram > 31) && (*ram <128)) {
            strcpy(buffer, (char *) adrs);
            io_write(io, (uint8_t *)buffer, 1); // compiles cleanly
        }
        for (volatile int j=2100; j>0; j--) { } // delay
    }


    return ram;
    // char *ram;
    // ram = (uint8_t *)7;

//  ram = 7;
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



/* dump 16 bytes of RAM in hex with ascii on the side */
uint8_t* cdump(void) {
    char buffer[5] = "";
    char *ram;
    // int p = pop();
    int p = LBOUND ;
    ram = (char*)p;

 // sprintf(buffer, "%4x", p);
    strcpy(buffer, (char *) p);



    io_write(io, (uint8_t *)"\015\012", 2); // CRLF
    io_write(io, (uint8_t *)"\015\012", 2); // CRLF
    io_write(io, (uint8_t *)"\015\012", 2); // CRLF


 // Serial.print(buffer);

    io_write(io, (uint8_t *)buffer, 1); // compiles cleanly

 // Serial.print("   ");

    io_write(io, (uint8_t *)"  ", 3);

    for (int i = 0; i < 16; i++) {
        char c = *ram++;
     // sprintf(buffer, " %2x", (c & 0xff));
        strcpy(buffer, (char *) (c & 0xff));
     // Serial.print(buffer);
        io_write(io, (uint8_t *)buffer, 1); // compiles cleanly
    }
    ram = (char*)p;
 // Serial.print("   ");
    io_write(io, (uint8_t *)"  ", 3);
    for (int i = 0; i < 16; i++) {
        buffer[0] = *ram++;
        if (buffer[0] > 0x7f || buffer[0] < ' ') buffer[0] = '.';
        buffer[1] = '\0';
     // Serial.print(buffer);
        io_write(io, (uint8_t *)buffer, 1); // compiles cleanly
    }
 // push(p + 16);
    return (uint8_t *)p;
}
