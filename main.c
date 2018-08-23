#include <atmel_start.h>
#include "driver_examples.h"
#include "pins.h"
#include "src/dump.h"

void delays(void) { // delay some
    for (volatile int i=1299999; i>0; i--) {
        // empty loop
    }
}

void blink_two(void) {
    // clear first
    PORT->Group[PORTA].OUTCLR.reg  = (uint32_t)(1 << 16); // PA16 //  0 13 pinwrite  // D13
    for (int blinks=2; blinks >0; blinks--) {
        PORT->Group[PORTA].OUTTGL.reg  = (uint32_t)(1 << 16); // PA16 //    13 pintoggle // D13
        delays();
    }
}


void ldelays(void) {
    for (int ie=7; ie >0; ie--) {
        delays();
    }
}

void blink_awhile(void) {

    for (int iter=5; iter >0; iter--) {
        blink_two();
    }

/*
    ldelays();

    for (int iter=3 ; iter >0; iter--) {
        blink_two();
    }

    ldelays();

    for (int iter=3 ; iter >0; iter--) {
        blink_two();
    }

    ldelays();
*/

}

int main(void)
{
    uint8_t* rram = 0;
    int q = 0;
    /* Initializes MCU, drivers and middleware */
    atmel_start_init();
    SystemInit();
    pins_setup(); // initialize GPIO D13 PA16

    // blink_awhile(); // is the clock running?

    USART_0_example();

    blink_two(); blink_two();

    io_write(io, (uint8_t *) "feh", 3);
    io_write(io, (uint8_t *) "feh", 3);
    io_write(io, (uint8_t *) "feh", 3);

    // srdump();
    rram = srdump();

    io_write(io, (uint8_t *) "foy", 3);
    io_write(io, (uint8_t *) "foy", 3);
    io_write(io, (uint8_t *) "foy", 3);

    trapped(); // traps in an endless loop

    rram = cdump();

    q = (int)rram;
    if (q > 2)  q = 2;
    if (q < 1)  q = 2;
    for (volatile int i=-1; i<q; i++) {
        blink_two();
        // ldelays();
    }
    /* Replace with your application code */


    while (1) {
    }
}
