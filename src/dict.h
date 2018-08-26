// Sun Aug 26 19:45:14 UTC 2018

/* dict.h */

typedef void (*func)(void);           // signature of functions in dictionary

typedef struct {
    const char*    name;              // Pointer the Word Name in flash
    const func     function;          // Pointer to function
} entry;
