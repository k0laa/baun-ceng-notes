/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_12_3.c
 *
 * Code generated for Simulink model 'ornek_12_3'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 14:51:32 2026
 */

#include "ornek_12_3.h"
#include "rtwtypes.h"
#include "ornek_12_3_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals and states (default storage) */
DW_ornek_12_3_T ornek_12_3_DW;

/*
 * Output and update for enable system:
 *    '<S7>/NEGATIVE Edge'
 *    '<S10>/NEGATIVE Edge'
 */
void ornek_12_3_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
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
void ornek_12_3_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
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

/* Model step function */
void ornek_12_3_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  real_T rtb_Switch2;
  real_T tmp;
  uint16_T rtb_DataTypeConversion;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_j;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */

  /* Outputs for Enabled SubSystem: '<S7>/POSITIVE Edge' */
  /* UnitDelay: '<S7>/Unit Delay' */
  ornek_12_3_POSITIVEEdge(ornek_12_3_ConstB.MultiportSwitch[0], rtb_DigitalInput_o1,
    ornek_12_3_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_12_3_DW.RelationalOperator1_n);

  /* End of Outputs for SubSystem: '<S7>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S7>/NEGATIVE Edge' */
  ornek_12_3_NEGATIVEEdge(ornek_12_3_ConstB.MultiportSwitch[1], rtb_DigitalInput_o1,
    ornek_12_3_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_12_3_DW.RelationalOperator1_p);

  /* End of Outputs for SubSystem: '<S7>/NEGATIVE Edge' */

  /* Logic: '<S7>/Logical Operator1' */
  rtb_LogicalOperator1_j = (ornek_12_3_DW.RelationalOperator1_n || ornek_12_3_DW.RelationalOperator1_p);

  /* Outputs for Enabled SubSystem: '<S10>/POSITIVE Edge' */
  /* UnitDelay: '<S10>/Unit Delay' */
  ornek_12_3_POSITIVEEdge(ornek_12_3_ConstB.MultiportSwitch_h[0], rtb_DigitalInput_o2,
    ornek_12_3_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_12_3_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S10>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S10>/NEGATIVE Edge' */
  ornek_12_3_NEGATIVEEdge(ornek_12_3_ConstB.MultiportSwitch_h[1], rtb_DigitalInput_o2,
    ornek_12_3_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_12_3_DW.RelationalOperator1_a);

  /* End of Outputs for SubSystem: '<S10>/NEGATIVE Edge' */

  /* Logic: '<S10>/Logical Operator1' */
  rtb_LogicalOperator1 = (ornek_12_3_DW.RelationalOperator1 || ornek_12_3_DW.RelationalOperator1_a);

  /* CombinatorialLogic: '<S6>/Logic' incorporates:
   *  Logic: '<Root>/OR'
   *  Memory: '<S6>/Memory'
   */
  rtb_Logic_idx_0 = ornek_12_3_ConstP.Logic_table[((((uint16_T)(rtb_LogicalOperator1_j || rtb_LogicalOperator1)
    << 1) + false) << 1) + ornek_12_3_DW.bitsForTID0.Memory_PreviousInput_g];

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   */
  if (rtb_Logic_idx_0) {
    rtb_Switch2 = ornek_12_3_DW.Memory_PreviousInput;
  } else {
    rtb_Switch2 = 1.0;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant5'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(ornek_12_3_ConstP.Constant5_Value[(int16_T)rtb_Switch2]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (MCHP_Digital_Output_Write): '<S3>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum1'
   *  Switch: '<Root>/Switch'
   */
  if (rtb_LogicalOperator1_j) {
    rtb_Switch2++;
  } else if (rtb_LogicalOperator1) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    rtb_Switch2--;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  if (rtb_Switch2 == 10.0) {
    rtb_Switch2 = 2.0;
  }

  /* End of Switch: '<Root>/Switch3' */
  /* Update for UnitDelay: '<S7>/Unit Delay' */
  ornek_12_3_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o1;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  ornek_12_3_DW.bitsForTID0.UnitDelay_DSTATE_n = rtb_DigitalInput_o2;

  /* Update for Memory: '<S6>/Memory' */
  ornek_12_3_DW.bitsForTID0.Memory_PreviousInput_g = rtb_Logic_idx_0;

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  if (rtb_Switch2 == 1.0) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    ornek_12_3_DW.Memory_PreviousInput = 9.0;
  } else {
    /* Update for Memory: '<Root>/Memory' */
    ornek_12_3_DW.Memory_PreviousInput = rtb_Switch2;
  }

  /* End of Switch: '<Root>/Switch4' */
}

/* Model initialize function */
void ornek_12_3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ornek_12_3_DW.Memory_PreviousInput = 1.0;
}

/* Model terminate function */
void ornek_12_3_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    /* Re-enable timer or interrupt */
    _T1IF = 0;                         /*  */
    MCHP_Scheduler();
  }
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  /* Call model Scheduler */

  /* Step the model for base rate */
  ornek_12_3_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
