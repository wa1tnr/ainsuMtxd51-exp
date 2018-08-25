/* stack_ops.h */

// const int STKSIZE = 8;
// const int STKMASK = 7;
extern int stack[];
extern int p; // = 0;

/* TOS is Top Of Stack */
// #define TOS stack[p]

extern void push(int n);
extern int pop(void);
extern void dot(void);
