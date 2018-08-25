// Sat Aug 25 00:23:10 UTC 2018

/*
parking here means leaving off work for the day, and
wanting to 'remember where we parked' (remember what
was going on when it became time to quit for the day).


parking - 0x00ff0000 mask in dump.c

NEXT:

To think of a way to get the information out of an
integer and print it to the console, in the forth
dot s word (.s).


If the value on TOS is 5280 (feet in a mile) that's
a decimal representation of

  0x14A0

which is

  0001 0100 1010 0000  in binary.

We as humans know it's 5280 by a process we use:

  2^5  =   32
  2^7  =  128
  2^10 = 1024
  2^12 = 4096
  ===========
         5280

and we add all those to get 5280 (again).

Can always '2/'  ( n = n / 2 )

and do that in a counted loop
*/

    wanted_val = 0;
    for (int i = 32; i > 0; i--) {
        wanted_val
         = wanted_val
         + (TOS & (2 ^ i));
    }

/*
Which is the same as
*/

    wanted_val2 = wanted_val;
    wanted_val  = wanted_val2;
/* Have not changed the shape of the problem at all. */

/* So, a 'overflow decimal' function could be construed,
in such a way as to generate the next higher digit.

*/


  1001 - highest binary number representable in a single decimal system digit

 64 32 16    8  4  2  1

BCD may be the way to go here.  Have to
look it up and investigate its advantages.
