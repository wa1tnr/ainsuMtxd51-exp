#ifndef DRIVER_EXAMPLES_H_INCLUDED
#define DRIVER_EXAMPLES_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

extern struct io_descriptor *io;

void _bkbar(void); // broken bar
void _spc(void);
void _cr(void);
void USART_0_example_upper(void);
void USART_0_example_lower(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_EXAMPLES_H_INCLUDED
