#include <atmel_start.h>
#include "pins.h"
#include "clock_gen_OE.h"
void clock_gen_oe(void) { // ainsu new idiom 24 August 2018
#if defined ADAFRUIT_METRO_M4_EXPRESS
    PORT->Group[PORTB].DIRSET.reg  = (uint32_t)(1 << 14); // PB14 //  1  5 pinmode  // D5 // SAMD51

    PORT->Group[PORTB].PINCFG[14].bit.PMUXEN = 1; // enable the peripheral mux for this pin

    PORT->Group[PORTB].PMUX[(14>>1)].bit.PMUXE
        = MUX_PB14M_GCLK_IO0; // select the GCLK_IO0 peripheral function

    GCLK->GENCTRL[0].bit.OE = 1; // enable output from clock generator 0
#endif
}
