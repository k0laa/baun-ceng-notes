/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru1_1.c
 *
 * Code generated for Simulink model 'soru1_1'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Sep  3 19:48:14 2026
 */

#include "soru1_1.h"
#include "soru1_1_private.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_soru1_1_T soru1_1_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */
uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T previousState;
  uint32_T retVal;
  int16_T curState;
  int16_T lastzcevent;
  int16_T newState;
  int16_T newStateR;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  /* Detect rising edge events */
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

    if ((previousState == 1UL) && ((uint16_T)curState == 2U)) {
      retVal = 2UL;
    }

    if (previousState == 0UL) {
      retVal = 2UL;
    }

    if ((uint16_T)retVal == (uint16_T)lastzcevent) {
      retVal = 0UL;
    }

    if (((uint16_T)curState == 1U) && ((uint16_T)retVal == 2U)) {
      newState = 3;
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
void soru1_1_step(void)
{
  real_T rtb_Memory;
  boolean_T rtb_Compare;
  boolean_T rtb_LogicalOperator;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = soru1_1_DW.Memory_PreviousInput;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  rtb_LogicalOperator = ((soru1_1_DW.Memory_PreviousInput > 0.0) && (soru1_1_DW.Memory_PreviousInput <= 3.0));

  /* S-Function (MCHP_Digital_Output_Write): '<S3>/Digital Output Write' */
  LATBbits.LATB0 = rtb_LogicalOperator;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_Compare = PORTCbits.RC0;         /* Read pin C0 */

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  soru1_1_DW.bitsForTID0.Compare = (rtb_Memory > 3.0);

  /* S-Function (sdspcount2): '<Root>/Counter' */
  if (MWDSP_EPH_R_B(soru1_1_DW.bitsForTID0.Compare, &soru1_1_DW.Counter_RstEphState) != 0UL) {
    soru1_1_DW.Counter_Count = 0U;
  }

  if (MWDSP_EPH_R_B(rtb_Compare, &soru1_1_DW.Counter_ClkEphState) != 0UL) {
    if (soru1_1_DW.Counter_Count < 10) {
      soru1_1_DW.Counter_Count++;
    } else {
      soru1_1_DW.Counter_Count = 0U;
    }
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (sdspcount2): '<Root>/Counter'
   */
  rtb_Compare = (soru1_1_DW.Counter_Count >= 5);

  /* Outputs for Enabled SubSystem: '<S6>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (soru1_1_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
     *  UnitDelay: '<S6>/Unit Delay'
     */
    soru1_1_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_LogicalOperator > (int16_T)
      soru1_1_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S6>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S6>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (soru1_1_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
     *  UnitDelay: '<S6>/Unit Delay'
     */
    soru1_1_DW.bitsForTID0.RelationalOperator1_o = ((int16_T)soru1_1_DW.bitsForTID0.UnitDelay_DSTATE >
      (int16_T)rtb_LogicalOperator);
  }

  /* End of Outputs for SubSystem: '<S6>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S5>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator1'
   *  Memory: '<S5>/Memory'
   */
  rtb_Compare = soru1_1_ConstP.Logic_table[((((uint16_T)rtb_Compare << 1) + (uint16_T)
    (soru1_1_DW.bitsForTID0.RelationalOperator1 || soru1_1_DW.bitsForTID0.RelationalOperator1_o)) << 1) +
    soru1_1_DW.bitsForTID0.Memory_PreviousInput_c];

  /* Switch: '<Root>/Switch3' */
  if (rtb_Compare) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    soru1_1_DW.Memory_PreviousInput = rtb_Memory + 0.1;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    soru1_1_DW.Memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  soru1_1_DW.bitsForTID0.UnitDelay_DSTATE = rtb_LogicalOperator;

  /* Update for Memory: '<S5>/Memory' */
  soru1_1_DW.bitsForTID0.Memory_PreviousInput_c = rtb_Compare;
}

/* Model initialize function */
void soru1_1_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  soru1_1_DW.Counter_ClkEphState = 5UL;
  soru1_1_DW.Counter_RstEphState = 5UL;
}

/* Model terminate function */
void soru1_1_terminate(void)
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
    soru1_1_step();

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
