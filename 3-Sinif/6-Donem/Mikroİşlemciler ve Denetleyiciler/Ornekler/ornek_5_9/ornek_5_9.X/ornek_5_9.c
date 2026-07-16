/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_5_9.c
 *
 * Code generated for Simulink model 'ornek_5_9'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jul 16 20:29:58 2026
 */

#include "ornek_5_9.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_5_9_T ornek_5_9_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_5_9_step(void)
{
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Logic_m[2];
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_DigitalInput_o3;
  boolean_T rtb_LogicalOperator1;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_LogicalOperator1 = PORTCbits.RC0;/* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  Memory: '<S2>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)(rtb_LogicalOperator1 && rtb_DigitalInput_o2) << 1) + rtb_DigitalInput_o3) <<
                      1) + ornek_5_9_DW.bitsForTID0.Memory_PreviousInput);
  rtb_Logic[0U] = ornek_5_9_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_5_9_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator1'
   *  Memory: '<S3>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)(rtb_LogicalOperator1 && rtb_DigitalInput_o3) << 1) + rtb_DigitalInput_o2) <<
                      1) + ornek_5_9_DW.bitsForTID0.Memory_PreviousInput_g);
  rtb_Logic_m[0U] = ornek_5_9_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic_m[1U] = ornek_5_9_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];
  LATBbits.LATB1 = rtb_Logic_m[0];

  /* Update for Memory: '<S2>/Memory' */
  ornek_5_9_DW.bitsForTID0.Memory_PreviousInput = rtb_Logic[0];

  /* Update for Memory: '<S3>/Memory' */
  ornek_5_9_DW.bitsForTID0.Memory_PreviousInput_g = rtb_Logic_m[0];
}

/* Model initialize function */
void ornek_5_9_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_5_9_terminate(void)
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
    ornek_5_9_step();

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
