/* stack_ops.c */

/* from Shattuck's Tiny interpreter,
   similar to myforth's Standalone Interpreter
   This example code is in the public domain */

/* Data stack for parameter passing
   This "stack" is circular,
   like a Green Arrays F18A data stack,
   so overflow and underflow are not possible
   Number of items must be a power of 2 */


// const int STKSIZE = 8;
#define STKSIZE 8

// const int STKMASK = 7;
#define STKMASK 7

int stack[STKSIZE];
int p = 0;

/* TOS is Top Of Stack */
#define TOS stack[p]

/* push n to top of data stack */
void push(int n) {
  p = (p + 1)& STKMASK;
  TOS = n;
}

/* return top of stack */
int pop(void) {
  int n = TOS;
  p = (p - 1)& STKMASK;
  return n;
}

/* destructively display top of stack, decimal */
void dot(void) {
    // Serial.print(pop());
    // Serial.print(" ");
}
