/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_9_2_main.c
 *
 * Code generated for Simulink model 'ornek_9_2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 18:35:57 2026
 */

/* Set Fuses Options */

#pragma config FNOSC = PRI
#pragma config POSCMD = HS, OSCIOFNC = ON, FCKSM = CSECMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

#define MCHP_isMainFile
#include "ornek_9_2.h"
#include "ornek_9_2_private.h"

/* Microchip Global Variables */
/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */

  /* Start Clock Switching */
  if ((OSCCONbits.COSC & 1) && !(OSCCONbits.COSC & 4))/* check not already in PLL mode (0?1) */
  {
    __builtin_write_OSCCONH(0);        /* Clock Switch to non PLL mode */
    __builtin_write_OSCCONL(0x01);     /* Start clock switching */
    __asm__ volatile("nop\n"
                     "nop");
    while (OSCCONbits.COSC != 0) ;
  }

  PLLFBD = 110;                        /* Oscillator PLL : PLLDIV */
  CLKDIV = 0x05;                       /* Oscillator PLL : FRCDIV ; PLLPOST ; PLLPRE */
  __builtin_write_OSCCONH(3);          /* Clock Switch to desired configuration */
  __builtin_write_OSCCONL(0x01);       /* Start clock switching */

  /* Configure Pins as Analog or Digital */
  AD1PCFGL = 0x3C;

  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */
  TRISB = 0xFC00;                      /* Port input (1) / output (0) */

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  ornek_9_2_initialize();

  /* Configure Timers */
  /* --- TIMER 3 --- This timer is enabled at end of configuration functions. */
  T3CON = 0;                           /* Stop Timer 3 and resets control register */
  PR3 = 0xC34F;                        /* Period */
  T3CON = 0x10;                        /* Set timer Prescaler ; internal clock source */

  /* Enable Time-step */
  _T3IF = 0;                           /* Clear Timer 3 Interrupt flag */
  _T3IE = 1;                           /* Enable Timer 3 model Step Interrupt */
  TMR3 = 0xC34E;                       /* Initialize Timer Value */
  T3CONbits.TON = 1;                /* Start timer 3. Timer 3 is the source trigger for the model Time-step */

  /* Main Loop */

  /* Single rate scheduler function */

  /* Main Loop */
  for (;;) ;

  /* Terminate model */
  ornek_9_2_terminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
