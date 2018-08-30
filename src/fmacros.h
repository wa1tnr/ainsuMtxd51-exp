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
