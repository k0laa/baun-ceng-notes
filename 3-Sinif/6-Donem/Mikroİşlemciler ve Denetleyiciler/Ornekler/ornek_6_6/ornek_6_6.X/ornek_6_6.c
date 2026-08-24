/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_6.c
 *
 * Code generated for Simulink model 'ornek_6_6'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Aug 24 20:35:29 2026
 */

#include "ornek_6_6.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_6_T ornek_6_6_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_6_6_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o2;
  real_T rtb_Switch;
  real_T rtb_Switch1;
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_RelationalOperator1;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_LogicalOperator2 = PORTCbits.RC5;/* Read pin C5 */

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<Root>/Logical Operator4'
   *  Memory: '<Root>/Memory'
   *  Memory: '<S3>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rowIdx = (int16_T)(((((uint16_T)(PORTCbits.RC0 && PORTCbits.RC4) << 1) + (uint16_T)(rtb_LogicalOperator2 &&
    (ornek_6_6_DW.Memory_PreviousInput >= 5.0))) << 1) + ornek_6_6_DW.bitsForTID0.Memory_PreviousInput_j);
  rtb_Logic[0U] = ornek_6_6_ConstP.pooled4[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_6_6_ConstP.pooled4[(uint16_T)rowIdx + 8U];

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Memory: '<Root>/Memory1'
   */
  rtb_RelationalOperator1 = (ornek_6_6_DW.Memory1_PreviousInput >= 3.0);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];
  LATBbits.LATB1 = rtb_RelationalOperator1;

  /* Outputs for Enabled SubSystem: '<S5>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (ornek_6_6_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
     *  UnitDelay: '<S5>/Unit Delay'
     */
    ornek_6_6_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_DigitalInput_o2 > (int16_T)
      ornek_6_6_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S5>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S5>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (ornek_6_6_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
     *  UnitDelay: '<S5>/Unit Delay'
     */
    ornek_6_6_DW.bitsForTID0.RelationalOperator1_a = ((int16_T)ornek_6_6_DW.bitsForTID0.UnitDelay_DSTATE >
      (int16_T)rtb_DigitalInput_o2);
  }

  /* End of Outputs for SubSystem: '<S5>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator1'
   *  Logic: '<Root>/Logical Operator2'
   *  Logic: '<S5>/Logical Operator1'
   *  Memory: '<S4>/Memory'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rtb_RelationalOperator1 = ornek_6_6_ConstP.pooled4[((((uint16_T)
    ((ornek_6_6_DW.bitsForTID0.RelationalOperator1 || ornek_6_6_DW.bitsForTID0.RelationalOperator1_a) &&
     PORTCbits.RC2) << 1) + (uint16_T)(rtb_LogicalOperator2 || PORTCbits.RC3)) << 1) +
    ornek_6_6_DW.bitsForTID0.Memory_PreviousInput_a];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant4'
   *  Memory: '<Root>/Memory1'
   *  Sum: '<Root>/Sum1'
   */
  if (rtb_RelationalOperator1) {
    rtb_Switch1 = ornek_6_6_DW.Memory1_PreviousInput + 0.1;
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   *  Sum: '<Root>/Sum'
   */
  if (rtb_DigitalInput_o2) {
    rtb_Switch = ornek_6_6_DW.Memory_PreviousInput + 0.1;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_6_6_DW.Memory_PreviousInput = rtb_Switch;

  /* Update for Memory: '<S3>/Memory' */
  ornek_6_6_DW.bitsForTID0.Memory_PreviousInput_j = rtb_Logic[0];

  /* Update for Memory: '<Root>/Memory1' */
  ornek_6_6_DW.Memory1_PreviousInput = rtb_Switch1;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  ornek_6_6_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o2;

  /* Update for Memory: '<S4>/Memory' */
  ornek_6_6_DW.bitsForTID0.Memory_PreviousInput_a = rtb_RelationalOperator1;
}

/* Model initialize function */
void ornek_6_6_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_6_terminate(void)
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
    ornek_6_6_step();

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
