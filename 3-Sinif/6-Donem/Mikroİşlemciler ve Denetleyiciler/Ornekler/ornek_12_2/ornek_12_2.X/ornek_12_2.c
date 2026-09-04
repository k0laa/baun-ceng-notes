/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_12_2.c
 *
 * Code generated for Simulink model 'ornek_12_2'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 14:56:15 2026
 */

#include "ornek_12_2.h"
#include "rtwtypes.h"
#include "ornek_12_2_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals and states (default storage) */
DW_ornek_12_2_T ornek_12_2_DW;

/*
 * Output and update for enable system:
 *    '<S5>/NEGATIVE Edge'
 *    '<S8>/NEGATIVE Edge'
 */
void ornek_12_2_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S5>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S6>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S5>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S5>/POSITIVE Edge'
 *    '<S8>/POSITIVE Edge'
 */
void ornek_12_2_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S5>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S7>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S5>/POSITIVE Edge' */
}

/* Model step function */
void ornek_12_2_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o3;
  boolean_T rtb_DigitalInput_o4;
  real_T rtb_Switch1;
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */
  rtb_DigitalInput_o4 = PORTCbits.RC3; /* Read pin C3 */

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Memory: '<S4>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_DigitalInput_o1 << 1) + rtb_DigitalInput_o2) << 1) +
                     ornek_12_2_DW.bitsForTID0.Memory_PreviousInput_a);
  rtb_Logic[0U] = ornek_12_2_ConstP.Logic_table[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_12_2_ConstP.Logic_table[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB9 = rtb_Logic[0];

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   */
  if (rtb_Logic[0]) {
    rtb_Switch1 = ornek_12_2_DW.Memory_PreviousInput;
  } else {
    rtb_Switch1 = 0.0;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Switch: '<Root>/Switch2'
   */
  rtb_Switch1 = floor(39999.0 * rtb_Switch1);
  if (rtIsNaN(rtb_Switch1) || rtIsInf(rtb_Switch1)) {
    rtb_Switch1 = 0.0;
  } else {
    rtb_Switch1 = fmod(rtb_Switch1, 65536.0);
  }

  /* Gain: '<Root>/Gain' */
  ornek_12_2_DW.Gain = rtb_Switch1 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Switch1 : (uint16_T)rtb_Switch1;

  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* Outputs for Enabled SubSystem: '<S5>/POSITIVE Edge' */
  /* UnitDelay: '<S5>/Unit Delay' */
  ornek_12_2_POSITIVEEdge(ornek_12_2_ConstB.MultiportSwitch[0], rtb_DigitalInput_o3,
    ornek_12_2_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_12_2_DW.RelationalOperator1_n);

  /* End of Outputs for SubSystem: '<S5>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S5>/NEGATIVE Edge' */
  ornek_12_2_NEGATIVEEdge(ornek_12_2_ConstB.MultiportSwitch[1], rtb_DigitalInput_o3,
    ornek_12_2_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_12_2_DW.RelationalOperator1_p);

  /* End of Outputs for SubSystem: '<S5>/NEGATIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S8>/POSITIVE Edge' */
  /* UnitDelay: '<S8>/Unit Delay' */
  ornek_12_2_POSITIVEEdge(ornek_12_2_ConstB.MultiportSwitch_h[0], rtb_DigitalInput_o4,
    ornek_12_2_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_12_2_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S8>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S8>/NEGATIVE Edge' */
  ornek_12_2_NEGATIVEEdge(ornek_12_2_ConstB.MultiportSwitch_h[1], rtb_DigitalInput_o4,
    ornek_12_2_DW.bitsForTID0.UnitDelay_DSTATE_n, &ornek_12_2_DW.RelationalOperator1_a);

  /* End of Outputs for SubSystem: '<S8>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Logic: '<S5>/Logical Operator1'
   *  Logic: '<S8>/Logical Operator1'
   *  Memory: '<Root>/Memory'
   *  Sum: '<Root>/Sum1'
   *  Switch: '<Root>/Switch'
   */
  if (ornek_12_2_DW.RelationalOperator1_n || ornek_12_2_DW.RelationalOperator1_p) {
    rtb_Switch1 = ornek_12_2_DW.Memory_PreviousInput + 0.1;
  } else if (ornek_12_2_DW.RelationalOperator1 || ornek_12_2_DW.RelationalOperator1_a) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Memory: '<Root>/Memory'
     *  Sum: '<Root>/Sum'
     */
    rtb_Switch1 = ornek_12_2_DW.Memory_PreviousInput - 0.1;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Memory: '<Root>/Memory'
     */
    rtb_Switch1 = ornek_12_2_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<Root>/Switch1' */
  /* Update for Memory: '<S4>/Memory' */
  ornek_12_2_DW.bitsForTID0.Memory_PreviousInput_a = rtb_Logic[0];

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch1 > 1.0) {
    /* Update for Memory: '<Root>/Memory' */
    ornek_12_2_DW.Memory_PreviousInput = 1.0;
  } else if (rtb_Switch1 < 0.0) {
    /* Update for Memory: '<Root>/Memory' */
    ornek_12_2_DW.Memory_PreviousInput = 0.0;
  } else {
    /* Update for Memory: '<Root>/Memory' */
    ornek_12_2_DW.Memory_PreviousInput = rtb_Switch1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = ornek_12_2_DW.Gain;          /* Period for Channel 1 */

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  ornek_12_2_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o3;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  ornek_12_2_DW.bitsForTID0.UnitDelay_DSTATE_n = rtb_DigitalInput_o4;
}

/* Model initialize function */
void ornek_12_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_PWM): '<Root>/PWM' */
  PWM1CON1 = 0x11;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0xF2B2;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x87;
  P1TPER = 0x4E20;
  P1SECMP = 0x4E20;
  P1TCON = 0x8003;                     /* Enable PWM */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ornek_12_2_DW.Memory_PreviousInput = 0.5;
}

/* Model terminate function */
void ornek_12_2_terminate(void)
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
  ornek_12_2_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
