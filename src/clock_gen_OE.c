#include <atmel_start.h>
#include "pins.h"
#include "clock_gen_OE.h"

// 24 August SAMD51 Metro M4 Express
void clock_gen_oe(void) { // ainsu new idiom 24 August 2018
#ifndef OMIT_GCLK0_OE_PINMUX_SETUP
#if defined ADAFRUIT_METRO_M4_EXPRESS
    PORT->Group[PORTB].DIRSET.reg  = (uint32_t)(1 << 14); // PB14 //  1  5 pinmode  // D5 // SAMD51

    PORT->Group[PORTB].PINCFG[14].bit.PMUXEN = 1; // enable the peripheral mux for this pin

    PORT->Group[PORTB].PMUX[(14>>1)].bit.PMUXE
        = MUX_PB14M_GCLK_IO0; // select the GCLK_IO0 peripheral function

    GCLK->GENCTRL[0].bit.OE = 1; // enable output from clock generator 0
#endif // METRO_M4

#if defined ADAFRUIT_METRO_M0_EXPRESS
    PORT->Group[PORTA].DIRSET.reg  = (uint32_t)(1 << 14); // PA14 //  1  2 pinmode   //  D2

    // enable the peripheral mux for this pin
    PORT->Group[PORTA].PINCFG[14].bit.PMUXEN = 1; // enable the peripheral mux for this pin

    PORT->Group[PORTA].PMUX[(14>>1)].bit.PMUXE
        = MUX_PA14H_GCLK_IO0; // select the GCLK_IO0 peripheral function

    // do this in ./config/hpl_gclk_config.h:
    // GCLK->GENCTRL[0].bit.OE = 1; // enable output from clock generator 0
#endif // METRO_M0

#endif // OMIT
}
