# ainsuMtxd51

Working small, Forth-like interpreter (type 'words' for help).

    On branch KM_converser_d51

For SAMD51 (here) and SAMD21 (elsewhere; similarly-named repository)

Most recent work is here.  SAMD21 repository is lagging behind quite a bit.

# Intent

This is a working, USART-tethered interpreter that exhibits a very small
number of behaviors reminiscent of forth.

It can execute arbitrary functions coded in C, through a pleasant tty
(typewriter-like) interface at 38400 bps.

Intent is to use this primitive environment as a way 'in' .. as a debug
monitor running on the hardware itself -- to try to do something a bit
more interesting there.

# Build Environment

This is an Atmel Start based project.

It is built on Debian Linux 9.5 (Linux kernel 4.9.0-7-amd64).

Toolchain is the usual ARM gcc - same exact build environment as
Adafruit's CircuitPython.

Makefile is a modification of Atmel Start's version, with which
it is fundamentally compatible, except for the way the bootloader
is handled:

  $ cat ../../ainsuMtxd51-exp/gcc/Makefile | egrep bootl
-T"../gcc/gcc/samd51j19a_flash_with_bootloader.ld" \


# Lineage:

# samd51_USART_basic
   * clocks and very basic USART support

# ainsuMtxd21
  * more recent work on the command processor/interpreter loop code

Wed Aug 29 00:40:49 UTC 2018
