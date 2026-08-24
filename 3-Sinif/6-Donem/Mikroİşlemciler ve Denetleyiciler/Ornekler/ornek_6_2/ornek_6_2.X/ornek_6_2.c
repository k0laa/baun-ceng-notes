/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_2.c
 *
 * Code generated for Simulink model 'ornek_6_2'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 23 22:37:08 2026
 */

#include "ornek_6_2.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_2_T ornek_6_2_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_6_2_step(void)
{
  int16_T idxDelay;
  boolean_T rtb_DataTypeConversion;
  boolean_T rtb_DigitalInput;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTCbits.RC0;    /* Read pin C0 */

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rtb_DigitalInput = ornek_6_2_ConstP.Logic_table[((((uint16_T)rtb_DigitalInput << 1) + false) << 1) +
    ornek_6_2_DW.bitsForTID0.Memory_PreviousInput];

  /* Delay: '<Root>/Enabled Delay' */
  if (rtb_DigitalInput) {
    /* Delay: '<Root>/Enabled Delay' */
    ornek_6_2_DW.EnabledDelay = ornek_6_2_DW.EnabledDelay_DSTATE[0];
  }

  /* End of Delay: '<Root>/Enabled Delay' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_DataTypeConversion = (ornek_6_2_DW.EnabledDelay != 0.0);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_DataTypeConversion;

  /* Update for Memory: '<S2>/Memory' */
  ornek_6_2_DW.bitsForTID0.Memory_PreviousInput = rtb_DigitalInput;

  /* Update for Delay: '<Root>/Enabled Delay' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (rtb_DigitalInput) {
    for (idxDelay = 0; idxDelay < 49; idxDelay++) {
      ornek_6_2_DW.EnabledDelay_DSTATE[idxDelay] = ornek_6_2_DW.EnabledDelay_DSTATE[idxDelay + 1];
    }

    ornek_6_2_DW.EnabledDelay_DSTATE[49] = 1.0;
  }

  /* End of Update for Delay: '<Root>/Enabled Delay' */
}

/* Model initialize function */
void ornek_6_2_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_2_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _T1IF = 0;                         /* Re-enable interrupt */
  }
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  for (;;) {                           /* Infinite loop, no return */
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    _IPL0 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1U */

    /* Call model Scheduler */
    /* Step the model for base rate */
    ornek_6_2_step();

    /* Get model outputs here */

    /* Re-Enable Scheduler Interrupt */
    _IPL0 = 0;                         /* Enable Scheduler interrupt. Lower IPL from 1 to 0 */
  }                                    /* end infinite loop for(;;) */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
