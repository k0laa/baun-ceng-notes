/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney8_main.c
 *
 * Code generated for Simulink model 'deney8'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 13 13:57:13 2026
 */

/* Set Fuses Options */

#pragma config GWRP = GWRP_OFF, GCP = CODE_PROT_OFF
#pragma config FPR = XT_PLL16, FOS = PRI, FCKSMEN = CSW_FSCM_OFF
#pragma config FWPSB = WDTPSB_16, FWPSA = WDTPSA_512, WDT = WDT_OFF
#pragma config ICS = ICS_PGD
#pragma config FPWRT = PWRT_64, BODENV = BORV27, BOREN = PBOR_ON, LPOL = PWMxL_ACT_HI, HPOL = PWMxH_ACT_HI, PWMPIN = RST_IOPIN, MCLRE = MCLR_EN

#define MCHP_isMainFile
#include "deney8.h"
#include "deney8_private.h"

/* Microchip Global Variables */
/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */

  /* Configure Pins as Analog or Digital */
  ADPCFG = 0xFF;

  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */
  TRISB = 0xFF00;                      /* Port input (1) / output (0) */

  /* Initialize model */
  deney8_initialize();

  /* Configure Timers */
  /* --- TIMER 3 --- This timer is enabled at end of configuration functions. */
  T3CON = 0;                           /* Stop Timer 3 and resets control register */
  PR3 = 0x3E7F;                        /* Period */

  /* Enable Time-step */
  _T3IF = 0;                           /* Clear Timer 3 Interrupt flag */
  _T3IE = 1;                           /* Enable Timer 3 model Step Interrupt */
  TMR3 = 0x3E7E;                       /* Initialize Timer Value */
  T3CONbits.TON = 1;                /* Start timer 3. Timer 3 is the source trigger for the model Time-step */

  /* Main Loop */

  /* Single rate scheduler function */
  MCHP_Scheduler();                    /* no return */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
