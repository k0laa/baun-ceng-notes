/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_5.c
 *
 * Code generated for Simulink model 'ornek_6_5'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 23 23:19:49 2026
 */

#include "ornek_6_5.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_5_T ornek_6_5_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_6_5_step(void)
{
  real_T rtb_Switch;
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Logic_n[2];
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_RelationalOperator;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_LogicalOperator = PORTCbits.RC0; /* Read pin C0 */

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   */
  rtb_RelationalOperator = (ornek_6_5_DW.Memory_PreviousInput >= 3.0);

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Memory: '<S3>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_RelationalOperator << 1) + rtb_LogicalOperator) << 1) +
                     ornek_6_5_DW.bitsForTID0.Memory_PreviousInput_n);
  rtb_Logic[0U] = ornek_6_5_ConstP.pooled3[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_6_5_ConstP.pooled3[(uint16_T)rowIdx + 8U];

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rtb_LogicalOperator = (rtb_LogicalOperator && PORTCbits.RC2);

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_LogicalOperator << 1) + rtb_RelationalOperator) << 1) +
                     ornek_6_5_DW.bitsForTID0.Memory_PreviousInput_j);
  rtb_Logic_n[0U] = ornek_6_5_ConstP.pooled3[(uint16_T)rowIdx];
  rtb_Logic_n[1U] = ornek_6_5_ConstP.pooled3[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic_n[0];
  LATBbits.LATB1 = rtb_Logic[0];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   *  Sum: '<Root>/Sum'
   */
  if (PORTCbits.RC1) {
    rtb_Switch = ornek_6_5_DW.Memory_PreviousInput + 0.1;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_6_5_DW.Memory_PreviousInput = rtb_Switch;

  /* Update for Memory: '<S3>/Memory' */
  ornek_6_5_DW.bitsForTID0.Memory_PreviousInput_n = rtb_Logic[0];

  /* Update for Memory: '<S2>/Memory' */
  ornek_6_5_DW.bitsForTID0.Memory_PreviousInput_j = rtb_Logic_n[0];
}

/* Model initialize function */
void ornek_6_5_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_5_terminate(void)
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
    ornek_6_5_step();

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
