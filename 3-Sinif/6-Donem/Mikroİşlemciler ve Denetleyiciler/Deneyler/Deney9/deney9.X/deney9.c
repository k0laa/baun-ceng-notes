/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney9.c
 *
 * Code generated for Simulink model 'deney9'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jun  3 14:34:43 2026
 */

#include "deney9.h"
#include "rtwtypes.h"
#include "deney9_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals and states (default storage) */
DW_deney9_T deney9_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/*
 * Output and update for enable system:
 *    '<S13>/NEGATIVE Edge'
 *    '<S16>/NEGATIVE Edge'
 *    '<S19>/NEGATIVE Edge'
 */
void deney9_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S13>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S14>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S13>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S13>/POSITIVE Edge'
 *    '<S16>/POSITIVE Edge'
 *    '<S19>/POSITIVE Edge'
 */
void deney9_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S13>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S15>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S13>/POSITIVE Edge' */
}

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
void deney9_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_DigitalInput_o3;
  real_T rtb_Memory;
  real_T rtb_Switch6;
  real_T rtb_Switch7;
  uint16_T rtb_DataTypeConversion;
  boolean_T rtb_Counter1;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = deney9_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  rtb_Switch6 = floor(deney9_ConstP.Constant2_Value[(int16_T)deney9_DW.Memory_PreviousInput - 1]);
  if (rtIsNaN(rtb_Switch6) || rtIsInf(rtb_Switch6)) {
    rtb_Switch6 = 0.0;
  } else {
    rtb_Switch6 = fmod(rtb_Switch6, 65536.0);
  }

  rtb_DataTypeConversion = rtb_Switch6 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Switch6 : (uint16_T)
    rtb_Switch6;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S8>/Digital Output Write' */
  LATE = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTDbits.RD0; /* Read pin D0 */
  rtb_DigitalInput_o2 = PORTDbits.RD2; /* Read pin D2 */
  rtb_DigitalInput_o3 = PORTDbits.RD3; /* Read pin D3 */

  /* Outputs for Enabled SubSystem: '<S19>/POSITIVE Edge' */
  /* UnitDelay: '<S19>/Unit Delay' */
  deney9_POSITIVEEdge(deney9_ConstB.MultiportSwitch_b[0], rtb_DigitalInput_o3,
                      deney9_DW.bitsForTID0.UnitDelay_DSTATE, &deney9_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S19>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S19>/NEGATIVE Edge' */
  deney9_NEGATIVEEdge(deney9_ConstB.MultiportSwitch_b[1], rtb_DigitalInput_o3,
                      deney9_DW.bitsForTID0.UnitDelay_DSTATE, &deney9_DW.RelationalOperator1_p);

  /* End of Outputs for SubSystem: '<S19>/NEGATIVE Edge' */

  /* Logic: '<S19>/Logical Operator1' */
  rtb_Counter1 = (deney9_DW.RelationalOperator1 || deney9_DW.RelationalOperator1_p);

  /* Logic: '<Root>/OR' incorporates:
   *  Constant: '<S5>/Constant'
   *  Memory: '<Root>/Memory4'
   *  RelationalOperator: '<S5>/Compare'
   */
  deney9_DW.bitsForTID0.OR = (rtb_Counter1 || (deney9_DW.Memory4_PreviousInput > 7.0));

  /* Outputs for Enabled SubSystem: '<S13>/POSITIVE Edge' */
  /* UnitDelay: '<S13>/Unit Delay' */
  deney9_POSITIVEEdge(deney9_ConstB.MultiportSwitch[0], rtb_DigitalInput_o1,
                      deney9_DW.bitsForTID0.UnitDelay_DSTATE_m, &deney9_DW.RelationalOperator1_g);

  /* End of Outputs for SubSystem: '<S13>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S13>/NEGATIVE Edge' */
  deney9_NEGATIVEEdge(deney9_ConstB.MultiportSwitch[1], rtb_DigitalInput_o1,
                      deney9_DW.bitsForTID0.UnitDelay_DSTATE_m, &deney9_DW.RelationalOperator1_a);

  /* End of Outputs for SubSystem: '<S13>/NEGATIVE Edge' */

  /* S-Function (sdspcount2): '<Root>/Counter' incorporates:
   *  Logic: '<S13>/Logical Operator1'
   */
  if (MWDSP_EPH_R_B(deney9_DW.bitsForTID0.OR, &deney9_DW.Counter_RstEphState) != 0UL) {
    deney9_DW.Counter_Count = 0U;
  }

  if (MWDSP_EPH_R_B((deney9_DW.RelationalOperator1_g || deney9_DW.RelationalOperator1_a),
                    &deney9_DW.Counter_ClkEphState) != 0UL) {
    if (deney9_DW.Counter_Count < 255) {
      deney9_DW.Counter_Count++;
    } else {
      deney9_DW.Counter_Count = 0U;
    }
  }

  /* Outputs for Enabled SubSystem: '<S16>/POSITIVE Edge' */
  /* UnitDelay: '<S16>/Unit Delay' */
  deney9_POSITIVEEdge(deney9_ConstB.MultiportSwitch_j[0], rtb_DigitalInput_o2,
                      deney9_DW.bitsForTID0.UnitDelay_DSTATE_d, &deney9_DW.RelationalOperator1_c);

  /* End of Outputs for SubSystem: '<S16>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S16>/NEGATIVE Edge' */
  deney9_NEGATIVEEdge(deney9_ConstB.MultiportSwitch_j[1], rtb_DigitalInput_o2,
                      deney9_DW.bitsForTID0.UnitDelay_DSTATE_d, &deney9_DW.RelationalOperator1_l);

  /* End of Outputs for SubSystem: '<S16>/NEGATIVE Edge' */

  /* Logic: '<Root>/OR1' incorporates:
   *  Constant: '<S6>/Constant'
   *  Memory: '<Root>/Memory3'
   *  RelationalOperator: '<S6>/Compare'
   */
  deney9_DW.bitsForTID0.OR1 = (rtb_Counter1 || (deney9_DW.Memory3_PreviousInput > 7.0));

  /* S-Function (sdspcount2): '<Root>/Counter1' incorporates:
   *  Logic: '<S16>/Logical Operator1'
   */
  if (MWDSP_EPH_R_B(deney9_DW.bitsForTID0.OR1, &deney9_DW.Counter1_RstEphState) != 0UL) {
    deney9_DW.Counter1_Count = 0U;
  }

  if (MWDSP_EPH_R_B((deney9_DW.RelationalOperator1_c || deney9_DW.RelationalOperator1_l),
                    &deney9_DW.Counter1_ClkEphState) != 0UL) {
    if (deney9_DW.Counter1_Count < 255) {
      deney9_DW.Counter1_Count++;
    } else {
      deney9_DW.Counter1_Count = 0U;
    }
  }

  /* Switch: '<Root>/Switch6' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Memory: '<Root>/Memory3'
   *  S-Function (sdspcount2): '<Root>/Counter1'
   *  Sum: '<Root>/Sum'
   */
  if (deney9_DW.Counter1_Count == 1) {
    rtb_Switch6 = deney9_DW.Memory3_PreviousInput + 0.001;
  } else {
    rtb_Switch6 = 0.0;
  }

  /* End of Switch: '<Root>/Switch6' */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Memory: '<Root>/Memory3'
   *  Memory: '<Root>/Memory4'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   *  Switch: '<Root>/Switch'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch2'
   */
  if (rtb_Memory == 0.0) {
    rtb_Memory = 8.0;
  } else if (rtb_Memory == 9.0) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_Memory = 1.0;
  } else if (deney9_DW.Memory4_PreviousInput <= 7.0) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<S7>/FixPt Constant'
     *  Sum: '<S7>/FixPt Sum1'
     *  Switch: '<Root>/Switch2'
     */
    rtb_Memory--;
  } else if (deney9_DW.Memory3_PreviousInput <= 7.0) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<S12>/FixPt Constant'
     *  Sum: '<S12>/FixPt Sum1'
     *  Switch: '<Root>/Switch1'
     *  Switch: '<Root>/Switch2'
     */
    rtb_Memory++;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Switch: '<Root>/Switch7' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   *  Memory: '<Root>/Memory4'
   *  S-Function (sdspcount2): '<Root>/Counter'
   *  Sum: '<Root>/Sum1'
   */
  if (deney9_DW.Counter_Count == 1) {
    rtb_Switch7 = deney9_DW.Memory4_PreviousInput + 0.001;
  } else {
    rtb_Switch7 = 0.0;
  }

  /* End of Switch: '<Root>/Switch7' */
  /* Update for Memory: '<Root>/Memory' */
  deney9_DW.Memory_PreviousInput = rtb_Memory;

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  deney9_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o3;

  /* Update for Memory: '<Root>/Memory4' */
  deney9_DW.Memory4_PreviousInput = rtb_Switch7;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  deney9_DW.bitsForTID0.UnitDelay_DSTATE_m = rtb_DigitalInput_o1;

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  deney9_DW.bitsForTID0.UnitDelay_DSTATE_d = rtb_DigitalInput_o2;

  /* Update for Memory: '<Root>/Memory3' */
  deney9_DW.Memory3_PreviousInput = rtb_Switch6;
}

/* Model initialize function */
void deney9_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  deney9_DW.Memory_PreviousInput = 1.0;

  /* InitializeConditions for Memory: '<Root>/Memory4' */
  deney9_DW.Memory4_PreviousInput = 1.0;

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  deney9_DW.Counter_ClkEphState = 5UL;
  deney9_DW.Counter_RstEphState = 5UL;

  /* InitializeConditions for Memory: '<Root>/Memory3' */
  deney9_DW.Memory3_PreviousInput = 1.0;

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter1' */
  deney9_DW.Counter1_ClkEphState = 5UL;
  deney9_DW.Counter1_RstEphState = 5UL;
}

/* Model terminate function */
void deney9_terminate(void)
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
    deney9_step();

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
