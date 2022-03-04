/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;
volatile int *LEDctrl = (volatile int*) 0xbf886110;

/* Lab-specific initialization goes here */
void labinit( void )
{
  volatile int *trise = (volatile int*) 0xbf886100;
  *trise = *trise & 0xff00;
  *LEDctrl = 0x00000000;
  TRISD = 0x0fe0;
  return;
}

