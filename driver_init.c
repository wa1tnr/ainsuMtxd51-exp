/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

struct usart_sync_descriptor USART_0;

void USART_0_PORT_init(void)
{

/*
3.0 is 22   3.1 is 23

#define  TX   GPIO(GPIO_PORTA, 22) // 3.0
#define  PA22 GPIO(GPIO_PORTA, 22) // 3.0

#define  RX   GPIO(GPIO_PORTA, 23) // 3.1
#define  PA23 GPIO(GPIO_PORTA, 23) // 3.1
*/

   //   gpio_set_pin_function(PB16, PINMUX_PB16C_SERCOM5_PAD0); // TX
	gpio_set_pin_function(PA22, PINMUX_PA22C_SERCOM3_PAD0); // TX

   //   gpio_set_pin_function(PB17, PINMUX_PB17C_SERCOM5_PAD1); // RX
	gpio_set_pin_function(PA23, PINMUX_PA23C_SERCOM3_PAD1); // RX
}

void USART_0_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_SLOW, CONF_GCLK_SERCOM3_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

    //  hri_mclk_set_APBDMASK_SERCOM3_bit(MCLK);
        hri_mclk_set_APBBMASK_SERCOM3_bit(MCLK);

/* hri_mclk_d51.h:2084:static inline void hri_mclk_set_APBBMASK_SERCOM3_bit(const void *const hw) */
}

void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_sync_init(&USART_0, SERCOM3, (void *)NULL);
	USART_0_PORT_init();
}

void system_init(void) {

/*

  12:20 pm Philly cheese steak 16"

*/
        // init_mcu();

	// gpio_set_pin_direction(D11, GPIO_DIRECTION_OUT);

	// gpio_set_pin_level(D11, false);

	// gpio_set_pin_function(D11, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_direction(D13, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(D13, false);

	// gpio_set_pin_function(D13, GPIO_PIN_FUNCTION_OFF);

	USART_0_init();
}


/* want D11, D13 */
/*
13 16 11 19

  D13 PA16   D11 PA19
*/

                                    /* hri_mclk_set_APBDMASK_SERCOM3_bit(MCLK); */

/*
 rvim $ ag  hri_mclk | egrep SERC |  egrep MASK | egrep SERCOM3
hri_mclk_d51.h:2084:static inline void hri_mclk_set_APBBMASK_SERCOM3_bit(const void *const hw)


*/
