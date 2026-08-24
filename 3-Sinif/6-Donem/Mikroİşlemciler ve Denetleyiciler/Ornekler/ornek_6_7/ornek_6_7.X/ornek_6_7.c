/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_7.c
 *
 * Code generated for Simulink model 'ornek_6_7'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Aug 24 20:44:22 2026
 */

#include "ornek_6_7.h"
#include "rtwtypes.h"
#include "ornek_6_7_private.h"

/* Block signals and states (default storage) */
DW_ornek_6_7_T ornek_6_7_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/*
 * Output and update for enable system:
 *    '<S6>/NEGATIVE Edge'
 *    '<S9>/NEGATIVE Edge'
 */
void ornek_6_7_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S6>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S7>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S6>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S6>/POSITIVE Edge'
 *    '<S9>/POSITIVE Edge'
 */
void ornek_6_7_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S6>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S8>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S6>/POSITIVE Edge' */
}

/* Model step function */
void ornek_6_7_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput;
  real_T rtb_Switch;
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_LogicalOperator;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTCbits.RC0;    /* Read pin C0 */

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   */
  rtb_LogicalOperator = (ornek_6_7_DW.Memory_PreviousInput >= 5.0);

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Memory: '<S4>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_DigitalInput << 1) + rtb_LogicalOperator) << 1) +
                     ornek_6_7_DW.bitsForTID0.Memory_PreviousInput_j);
  rtb_Logic[0U] = ornek_6_7_ConstP.pooled6[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_6_7_ConstP.pooled6[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];

  /* Outputs for Enabled SubSystem: '<S6>/POSITIVE Edge' */
  /* UnitDelay: '<S6>/Unit Delay' */
  ornek_6_7_POSITIVEEdge(ornek_6_7_ConstB.MultiportSwitch[0], rtb_DigitalInput,
    ornek_6_7_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_6_7_DW.RelationalOperator1_h);

  /* End of Outputs for SubSystem: '<S6>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S6>/NEGATIVE Edge' */
  ornek_6_7_NEGATIVEEdge(ornek_6_7_ConstB.MultiportSwitch[1], rtb_DigitalInput,
    ornek_6_7_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_6_7_DW.RelationalOperator1_p);

  /* End of Outputs for SubSystem: '<S6>/NEGATIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S9>/POSITIVE Edge' */
  /* UnitDelay: '<S9>/Unit Delay' */
  ornek_6_7_POSITIVEEdge(ornek_6_7_ConstB.MultiportSwitch_o[0], rtb_DigitalInput,
    ornek_6_7_DW.bitsForTID0.UnitDelay_DSTATE_e, &ornek_6_7_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S9>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S9>/NEGATIVE Edge' */
  ornek_6_7_NEGATIVEEdge(ornek_6_7_ConstB.MultiportSwitch_o[1], rtb_DigitalInput,
    ornek_6_7_DW.bitsForTID0.UnitDelay_DSTATE_e, &ornek_6_7_DW.RelationalOperator1_a);

  /* End of Outputs for SubSystem: '<S9>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S5>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S9>/Logical Operator1'
   *  Memory: '<S5>/Memory'
   */
  rtb_LogicalOperator = ornek_6_7_ConstP.pooled6[((((uint16_T)(ornek_6_7_DW.RelationalOperator1_h ||
    ornek_6_7_DW.RelationalOperator1_p) << 1) + (uint16_T)(ornek_6_7_DW.RelationalOperator1 ||
    ornek_6_7_DW.RelationalOperator1_a || rtb_LogicalOperator)) << 1) +
    ornek_6_7_DW.bitsForTID0.Memory_PreviousInput_b];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   *  Sum: '<Root>/Sum'
   */
  if (rtb_LogicalOperator) {
    rtb_Switch = ornek_6_7_DW.Memory_PreviousInput + 0.1;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_6_7_DW.Memory_PreviousInput = rtb_Switch;

  /* Update for Memory: '<S4>/Memory' */
  ornek_6_7_DW.bitsForTID0.Memory_PreviousInput_j = rtb_Logic[0];

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  ornek_6_7_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  ornek_6_7_DW.bitsForTID0.UnitDelay_DSTATE_e = rtb_DigitalInput;

  /* Update for Memory: '<S5>/Memory' */
  ornek_6_7_DW.bitsForTID0.Memory_PreviousInput_b = rtb_LogicalOperator;
}

/* Model initialize function */
void ornek_6_7_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_7_terminate(void)
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
    ornek_6_7_step();

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
