/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney9_main.c
 *
 * Code generated for Simulink model 'deney9'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jun  3 14:34:43 2026
 */

/* Set Fuses Options */

#pragma config GWRP = GWRP_OFF, GCP = CODE_PROT_OFF
#pragma config FPR = XT_PLL16, FOS = PRI, FCKSMEN = CSW_FSCM_OFF
#pragma config FWPSB = WDTPSB_16, FWPSA = WDTPSA_512, WDT = WDT_OFF
#pragma config ICS = ICS_PGD
#pragma config FPWRT = PWRT_64, BODENV = BORV27, BOREN = PBOR_ON, LPOL = PWMxL_ACT_HI, HPOL = PWMxH_ACT_HI, PWMPIN = RST_IOPIN, MCLRE = MCLR_EN

#define MCHP_isMainFile
#include "deney9.h"
#include "deney9_private.h"

/* Microchip Global Variables */
/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */

  /* Configure Pins as Analog or Digital */
  ADPCFG = 0x00;

  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */
  TRISE = 0xFFF0;                      /* Port input (1) / output (0) */

  /* Initialize model */
  deney9_initialize();

  /* Configure Timers */
  /* --- TIMER 1 --- This timer is enabled at end of configuration functions. */
  T1CON = 0;                           /* Stop Timer 1 and resets control register */
  _T1IP = 2;                           /* Set timer Interrupt Priority */
  _T1IF = 0;                           /* Reset pending Interrupt */
  _T1IE = 1;                           /* Enable Timer Interrupt. */
  PR1 = 0x3E7F;                        /* Period */

  /* Enable Time-step */
  TMR1 = 0x3E7E;                       /* Initialize Timer Value */
  T1CONbits.TON = 1;                /* Start timer 1. Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */

  /* Single rate scheduler function */
  MCHP_Scheduler();                    /* no return */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
