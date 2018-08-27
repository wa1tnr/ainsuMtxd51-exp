/* math.c */

#include "stack_ops.h"

/* add top two stack items */
// NAMED(_plus, "plus");
void plus(void) {
    int a = 0;
    int b = 0;
    a = pop();
    b = pop();
    push(a+b);
}

/* add top two items */
// NAMED(_add, "+");
void add(void) {
    int a = pop();
    TOS = a + TOS;
}
