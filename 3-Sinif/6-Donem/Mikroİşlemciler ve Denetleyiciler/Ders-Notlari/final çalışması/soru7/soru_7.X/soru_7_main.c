/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_7_main.c
 *
 * Code generated for Simulink model 'soru_7'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 01:35:47 2026
 */

/* Set Fuses Options */

#pragma config FNOSC = PRI
#pragma config POSCMD = HS, OSCIOFNC = ON, FCKSM = CSECMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

#define MCHP_isMainFile
#include "soru_7.h"
#include "soru_7_private.h"

extern void MCHP_IdleTask();

/* Microchip Global Variables */
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
  AD1PCFGL = 0x38;

  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */
  TRISB = 0xFF01;                      /* Port input (1) / output (0) */

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  soru_7_initialize();

  /* Configure Timers */

  /* Enable Time-step */
  AD1CON1 = 0x80E4;                    /* ADC trig the model Time-step */

  /* Main Loop */
  for (;;) {
    MCHP_IdleTask();                   /* Call user Idle Task */
  }                                    /* end of for (;;) */

  /* Terminate model */
  soru_7_terminate();
}                                      /* end of main() */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
