/* fmacros.h */

#define uBackDotBack() \
    back(); \
    dot(); \
    back();

#define u_dotsR() \
    for (int i = 8; i > 0; i--) { \
        uBackDotBack() \
    }
