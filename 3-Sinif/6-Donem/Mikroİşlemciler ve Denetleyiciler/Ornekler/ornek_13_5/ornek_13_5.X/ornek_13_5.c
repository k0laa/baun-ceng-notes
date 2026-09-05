/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_5.c
 *
 * Code generated for Simulink model 'ornek_13_5'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 15:34:46 2026
 */

#include "ornek_13_5.h"
#include "rtwtypes.h"
#include "ornek_13_5_private.h"

/* Block signals and states (default storage) */
DW_ornek_13_5_T ornek_13_5_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/*
 * Output and update for enable system:
 *    '<S7>/NEGATIVE Edge'
 *    '<S10>/NEGATIVE Edge'
 */
void ornek_13_5_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S7>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S8>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S7>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S7>/POSITIVE Edge'
 *    '<S10>/POSITIVE Edge'
 */
void ornek_13_5_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S7>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S9>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S7>/POSITIVE Edge' */
}

uint32_T MWDSP_EPH_F_B(boolean_T evt, uint32_T *sta)
{
  uint32_T previousState;
  uint32_T retVal;
  int16_T curState;
  int16_T lastzcevent;
  int16_T newState;
  int16_T newStateR;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  /* Detect falling edge events */
  previousState = *sta;
  retVal = 0UL;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5UL) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3UL) {
      if ((uint16_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1UL;
      }
    }

    if (previousState == 4UL) {
      if ((uint16_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1UL;
      }
    }

    if (previousState == 2UL) {
      retVal = 3UL;
    }

    if ((uint16_T)retVal == (uint16_T)lastzcevent) {
      retVal = 0UL;
    }

    if (((uint16_T)curState == 1U) && ((uint16_T)retVal == 3U)) {
      newState = 4;
    } else {
      newState = curState;
    }
  }

  if ((uint16_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0UL;
  }

  if ((uint16_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<Root>/Counter' */
  return retVal;
}

/* Model step function */
void ornek_13_5_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput;
  real_T rtb_Switch1;
  int16_T rtb_Switch2;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_Memory1;

  /* Memory: '<Root>/Memory2' */
  ornek_13_5_DW.bitsForTID0.Memory2 = ornek_13_5_DW.bitsForTID0.Memory2_PreviousInput;

  /* Memory: '<Root>/Memory1' */
  rtb_Memory1 = ornek_13_5_DW.bitsForTID0.Memory1_PreviousInput;

  /* S-Function (MCHP_Digital_Output_Write): '<S3>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Memory1;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  if (MWDSP_EPH_F_B(ornek_13_5_DW.bitsForTID0.Memory2, &ornek_13_5_DW.Counter_RstEphState) != 0UL) {
    ornek_13_5_DW.Counter_Count = 0U;
  }

  if (MWDSP_EPH_F_B(rtb_Memory1, &ornek_13_5_DW.Counter_ClkEphState) != 0UL) {
    if (ornek_13_5_DW.Counter_Count < 255) {
      ornek_13_5_DW.Counter_Count++;
    } else {
      ornek_13_5_DW.Counter_Count = 0U;
    }
  }

  rtb_Memory1 = (ornek_13_5_DW.Counter_Count == 5);

  /* End of S-Function (sdspcount2): '<Root>/Counter' */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTCbits.RC0;    /* Read pin C0 */

  /* Outputs for Enabled SubSystem: '<S7>/POSITIVE Edge' */
  /* UnitDelay: '<S7>/Unit Delay' */
  ornek_13_5_POSITIVEEdge(ornek_13_5_ConstB.MultiportSwitch[0], rtb_DigitalInput,
    ornek_13_5_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_13_5_DW.RelationalOperator1_k);

  /* End of Outputs for SubSystem: '<S7>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S7>/NEGATIVE Edge' */
  ornek_13_5_NEGATIVEEdge(ornek_13_5_ConstB.MultiportSwitch[1], rtb_DigitalInput,
    ornek_13_5_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_13_5_DW.RelationalOperator1_a);

  /* End of Outputs for SubSystem: '<S7>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S6>/Logic' incorporates:
   *  Logic: '<S7>/Logical Operator1'
   *  Memory: '<S6>/Memory'
   */
  rtb_Logic_idx_0 = ornek_13_5_ConstP.Logic_table[((((uint16_T)(ornek_13_5_DW.RelationalOperator1_k ||
    ornek_13_5_DW.RelationalOperator1_a) << 1) + ornek_13_5_DW.bitsForTID0.Memory2) << 1) +
    ornek_13_5_DW.bitsForTID0.Memory_PreviousInput_a];

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S1>/Constant'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<S1>/Compare'
   */
  if (rtb_Logic_idx_0) {
    rtb_Switch2 = (ornek_13_5_DW.Memory_PreviousInput <= 3.0);
  } else {
    rtb_Switch2 = 0;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S2>/Constant'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<S2>/Compare'
   *  Switch: '<Root>/Switch'
   */
  if (ornek_13_5_DW.Memory_PreviousInput >= 5.0) {
    rtb_Switch1 = 0.0;
  } else if (rtb_Logic_idx_0) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    rtb_Switch1 = ornek_13_5_DW.Memory_PreviousInput + 0.01;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S10>/POSITIVE Edge' */
  /* UnitDelay: '<S10>/Unit Delay' */
  ornek_13_5_POSITIVEEdge(ornek_13_5_ConstB.MultiportSwitch_a[0], rtb_DigitalInput,
    ornek_13_5_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_13_5_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S10>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S10>/NEGATIVE Edge' */
  ornek_13_5_NEGATIVEEdge(ornek_13_5_ConstB.MultiportSwitch_a[1], rtb_DigitalInput,
    ornek_13_5_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_13_5_DW.RelationalOperator1_p);

  /* End of Outputs for SubSystem: '<S10>/NEGATIVE Edge' */

  /* Logic: '<S10>/Logical Operator1' */
  rtb_LogicalOperator1 = (ornek_13_5_DW.RelationalOperator1 || ornek_13_5_DW.RelationalOperator1_p);

  /* Update for Memory: '<Root>/Memory2' incorporates:
   *  Logic: '<Root>/Logical Operator'
   */
  ornek_13_5_DW.bitsForTID0.Memory2_PreviousInput = (rtb_LogicalOperator1 || rtb_Memory1);

  /* Update for Memory: '<Root>/Memory1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  ornek_13_5_DW.bitsForTID0.Memory1_PreviousInput = (rtb_Switch2 != 0);

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  ornek_13_5_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput;

  /* Update for Memory: '<S6>/Memory' */
  ornek_13_5_DW.bitsForTID0.Memory_PreviousInput_a = rtb_Logic_idx_0;

  /* Update for Memory: '<Root>/Memory' */
  ornek_13_5_DW.Memory_PreviousInput = rtb_Switch1;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  ornek_13_5_DW.bitsForTID0.UnitDelay_DSTATE_n = rtb_DigitalInput;
}

/* Model initialize function */
void ornek_13_5_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  ornek_13_5_DW.Counter_ClkEphState = 5UL;
  ornek_13_5_DW.Counter_RstEphState = 5UL;
}

/* Model terminate function */
void ornek_13_5_terminate(void)
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
    ornek_13_5_step();

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
