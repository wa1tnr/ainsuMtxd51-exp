/* fmacros.h */

#define uBackDotBack() \
    back(); \
    dot(); \
    back();

#define u_dotsR() \
    for (int i = 8; i > 0; i--) { \
        uBackDotBack() \
    }

#define bk_bk_dr() \
    back(); \
    back(); \
    drop();

#define swdr() \
    swap(); \
    drop();

#define swdr_four() \
    for (int mi = 4; mi > 0; mi--) { \
        swap(); drop();  \
    }

#define drp_four() \
    for (int mj = 4; mj > 0; mj--) { \
        drop();  \
    }

#define swdr_three() \
    for (int mk = 3; mk > 0; mk--) { \
        swap(); drop();  \
    }

#define bkbkdr_three() \
    for (int mk = 3; mk > 0; mk--) { \
        bk_bk_dr(); \
    }

#define rev_coll_stack() \
    swdr_four();    \
    swdr_four();    \
    drop();         \
    swdr_four()     \
    swap();         \
    drp_four()      \
    swdr_four()     \
    drp_four()      \
    swdr_three()    \
    bkbkdr_three()  \
    swdr();         \
    swap();         \
    bk_bk_dr();     \
    swap();


/* from: dump.c

 40 void new_ascii_emit(void) {
 44     rbyte = rbyte + 0x30; // normalize (in ASCII) for 0-9
 56     io_write(io, (uint8_t *) char_r, 1);
 57 }
*/

/* u_emit - cpp macro for emit() */
// ( n -- )

#define u_emit() \
    uint32_t  rbyte = 0; \
    int       char_r   =  '0'; \
    char      *cbyte; \
    rbyte = pop(); \
    cbyte = (char*) &rbyte; \
    int df = (uint32_t) cbyte; \
    char *dfbyte = (char*) df; \
    char_r = (int)dfbyte; \
    io_write(io, (uint8_t *) char_r, 1);

/* end fmacros.h */
