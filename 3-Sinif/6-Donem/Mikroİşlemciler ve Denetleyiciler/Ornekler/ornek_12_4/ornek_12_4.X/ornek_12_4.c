/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_12_4.c
 *
 * Code generated for Simulink model 'ornek_12_4'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 15:06:26 2026
 */

#include "ornek_12_4.h"
#include "rtwtypes.h"
#include "ornek_12_4_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals and states (default storage) */
DW_ornek_12_4_T ornek_12_4_DW;

/*
 * Output and update for enable system:
 *    '<S12>/NEGATIVE Edge'
 *    '<S15>/NEGATIVE Edge'
 *    '<S18>/NEGATIVE Edge'
 */
void ornek_12_4_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S12>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S13>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S12>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S12>/POSITIVE Edge'
 *    '<S15>/POSITIVE Edge'
 *    '<S18>/POSITIVE Edge'
 */
void ornek_12_4_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S12>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S14>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S12>/POSITIVE Edge' */
}

/* Model step function */
void ornek_12_4_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_DigitalInput_o3;
  real_T rtb_Switch4;
  uint16_T rtb_DataTypeConversion;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_a;
  boolean_T rtb_OR2;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */

  /* Outputs for Enabled SubSystem: '<S12>/POSITIVE Edge' */
  /* UnitDelay: '<S12>/Unit Delay' */
  ornek_12_4_POSITIVEEdge(ornek_12_4_ConstB.MultiportSwitch[0], rtb_DigitalInput_o1,
    ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_12_4_DW.RelationalOperator1_n);

  /* End of Outputs for SubSystem: '<S12>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S12>/NEGATIVE Edge' */
  ornek_12_4_NEGATIVEEdge(ornek_12_4_ConstB.MultiportSwitch[1], rtb_DigitalInput_o1,
    ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_12_4_DW.RelationalOperator1_p);

  /* End of Outputs for SubSystem: '<S12>/NEGATIVE Edge' */

  /* Logic: '<S12>/Logical Operator1' */
  rtb_OR2 = (ornek_12_4_DW.RelationalOperator1_n || ornek_12_4_DW.RelationalOperator1_p);

  /* Outputs for Enabled SubSystem: '<S15>/POSITIVE Edge' */
  /* UnitDelay: '<S15>/Unit Delay' */
  ornek_12_4_POSITIVEEdge(ornek_12_4_ConstB.MultiportSwitch_h[0], rtb_DigitalInput_o2,
    ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_12_4_DW.RelationalOperator1_h);

  /* End of Outputs for SubSystem: '<S15>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S15>/NEGATIVE Edge' */
  ornek_12_4_NEGATIVEEdge(ornek_12_4_ConstB.MultiportSwitch_h[1], rtb_DigitalInput_o2,
    ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_12_4_DW.RelationalOperator1_a);

  /* End of Outputs for SubSystem: '<S15>/NEGATIVE Edge' */

  /* Logic: '<S15>/Logical Operator1' */
  rtb_LogicalOperator1 = (ornek_12_4_DW.RelationalOperator1_h || ornek_12_4_DW.RelationalOperator1_a);

  /* Outputs for Enabled SubSystem: '<S18>/POSITIVE Edge' */
  /* UnitDelay: '<S18>/Unit Delay' */
  ornek_12_4_POSITIVEEdge(ornek_12_4_ConstB.MultiportSwitch_j[0], rtb_DigitalInput_o3,
    ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE_e, &ornek_12_4_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S18>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S18>/NEGATIVE Edge' */
  ornek_12_4_NEGATIVEEdge(ornek_12_4_ConstB.MultiportSwitch_j[1], rtb_DigitalInput_o3,
    ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE_e, &ornek_12_4_DW.RelationalOperator1_f);

  /* End of Outputs for SubSystem: '<S18>/NEGATIVE Edge' */

  /* Logic: '<S18>/Logical Operator1' */
  rtb_LogicalOperator1_a = (ornek_12_4_DW.RelationalOperator1 || ornek_12_4_DW.RelationalOperator1_f);

  /* CombinatorialLogic: '<S10>/Logic' incorporates:
   *  Logic: '<Root>/OR1'
   *  Memory: '<S10>/Memory'
   */
  rtb_Logic_idx_0 = ornek_12_4_ConstP.pooled6[((((uint16_T)rtb_OR2 << 1) + (uint16_T)(rtb_LogicalOperator1 ||
    rtb_LogicalOperator1_a)) << 1) + ornek_12_4_DW.bitsForTID0.Memory_PreviousInput_p];

  /* CombinatorialLogic: '<S11>/Logic' incorporates:
   *  Logic: '<Root>/OR2'
   *  Memory: '<S11>/Memory'
   */
  rtb_OR2 = ornek_12_4_ConstP.pooled6[((((uint16_T)rtb_LogicalOperator1 << 1) + (uint16_T)(rtb_OR2 ||
    rtb_LogicalOperator1_a)) << 1) + ornek_12_4_DW.bitsForTID0.Memory_PreviousInput_c];

  /* CombinatorialLogic: '<S9>/Logic' incorporates:
   *  Logic: '<Root>/OR'
   *  Memory: '<S9>/Memory'
   */
  rtb_LogicalOperator1 = ornek_12_4_ConstP.pooled6[((((uint16_T)(rtb_Logic_idx_0 || rtb_OR2) << 1) + false) <<
    1) + ornek_12_4_DW.bitsForTID0.Memory_PreviousInput_g];

  /* MultiPortSwitch: '<Root>/Index Vector' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   *  Switch: '<Root>/Switch2'
   */
  if (rtb_LogicalOperator1) {
    rtb_Switch4 = ornek_12_4_DW.Memory_PreviousInput;
  } else {
    rtb_Switch4 = 1.0;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant5'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  Switch: '<Root>/Switch2'
   */
  rtb_Switch4 = floor(ornek_12_4_ConstP.Constant5_Value[(int16_T)rtb_Switch4]);
  if (rtIsNaN(rtb_Switch4) || rtIsInf(rtb_Switch4)) {
    rtb_Switch4 = 0.0;
  } else {
    rtb_Switch4 = fmod(rtb_Switch4, 65536.0);
  }

  rtb_DataTypeConversion = rtb_Switch4 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Switch4 : (uint16_T)
    rtb_Switch4;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  Switch: '<Root>/Switch'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch3'
   */
  if (ornek_12_4_DW.Memory_PreviousInput == 1.0) {
    rtb_Switch4 = 9.0;
  } else if (ornek_12_4_DW.Memory_PreviousInput == 10.0) {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/ '
     */
    rtb_Switch4 = 2.0;
  } else if (rtb_OR2) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<S3>/FixPt Constant'
     *  Sum: '<S3>/FixPt Sum1'
     *  Switch: '<Root>/Switch3'
     */
    rtb_Switch4 = ornek_12_4_DW.Memory_PreviousInput - 1.0;
  } else if (rtb_Logic_idx_0) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<S8>/FixPt Constant'
     *  Sum: '<S8>/FixPt Sum1'
     *  Switch: '<Root>/Switch1'
     *  Switch: '<Root>/Switch3'
     */
    rtb_Switch4 = ornek_12_4_DW.Memory_PreviousInput + 1.0;
  } else {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Switch: '<Root>/Switch'
     *  Switch: '<Root>/Switch3'
     */
    rtb_Switch4 = ornek_12_4_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<Root>/Switch4' */
  /* Update for UnitDelay: '<S12>/Unit Delay' */
  ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o1;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE_n = rtb_DigitalInput_o2;

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  ornek_12_4_DW.bitsForTID0.UnitDelay_DSTATE_e = rtb_DigitalInput_o3;

  /* Update for Memory: '<S10>/Memory' */
  ornek_12_4_DW.bitsForTID0.Memory_PreviousInput_p = rtb_Logic_idx_0;

  /* Update for Memory: '<S11>/Memory' */
  ornek_12_4_DW.bitsForTID0.Memory_PreviousInput_c = rtb_OR2;

  /* Update for Memory: '<S9>/Memory' */
  ornek_12_4_DW.bitsForTID0.Memory_PreviousInput_g = rtb_LogicalOperator1;

  /* Update for Memory: '<Root>/Memory' */
  ornek_12_4_DW.Memory_PreviousInput = rtb_Switch4;
}

/* Model initialize function */
void ornek_12_4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ornek_12_4_DW.Memory_PreviousInput = 1.0;
}

/* Model terminate function */
void ornek_12_4_terminate(void)
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
  ornek_12_4_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
