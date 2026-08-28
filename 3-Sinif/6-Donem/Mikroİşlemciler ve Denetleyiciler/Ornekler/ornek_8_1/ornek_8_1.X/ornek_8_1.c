/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_8_1.c
 *
 * Code generated for Simulink model 'ornek_8_1'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 18:14:52 2026
 */

#include "ornek_8_1.h"
#include "rtwtypes.h"
#include "ornek_8_1_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals and states (default storage) */
DW_ornek_8_1_T ornek_8_1_DW;

/*
 * Output and update for enable system:
 *    '<S3>/NEGATIVE Edge'
 *    '<S6>/NEGATIVE Edge'
 */
void ornek_8_1_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S3>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S4>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S3>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S3>/POSITIVE Edge'
 *    '<S6>/POSITIVE Edge'
 */
void ornek_8_1_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S3>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S5>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S3>/POSITIVE Edge' */
}

/* Model step function */
void ornek_8_1_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  real_T rtb_Memory;
  real_T tmp;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_8_1_DW.Memory_PreviousInput;

  /* Gain: '<Root>/Gain' incorporates:
   *  Memory: '<Root>/Memory'
   */
  tmp = floor(39999.0 * ornek_8_1_DW.Memory_PreviousInput);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Gain: '<Root>/Gain' */
  ornek_8_1_DW.Gain = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */

  /* Outputs for Enabled SubSystem: '<S6>/POSITIVE Edge' */
  /* UnitDelay: '<S6>/Unit Delay' */
  ornek_8_1_POSITIVEEdge(ornek_8_1_ConstB.MultiportSwitch_j[0], rtb_DigitalInput_o2,
    ornek_8_1_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_8_1_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S6>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S6>/NEGATIVE Edge' */
  ornek_8_1_NEGATIVEEdge(ornek_8_1_ConstB.MultiportSwitch_j[1], rtb_DigitalInput_o2,
    ornek_8_1_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_8_1_DW.RelationalOperator1_a);

  /* End of Outputs for SubSystem: '<S6>/NEGATIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S3>/POSITIVE Edge' */
  /* UnitDelay: '<S3>/Unit Delay' */
  ornek_8_1_POSITIVEEdge(ornek_8_1_ConstB.MultiportSwitch[0], rtb_DigitalInput_o1,
    ornek_8_1_DW.bitsForTID0.UnitDelay_DSTATE_a, &ornek_8_1_DW.RelationalOperator1_i);

  /* End of Outputs for SubSystem: '<S3>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S3>/NEGATIVE Edge' */
  ornek_8_1_NEGATIVEEdge(ornek_8_1_ConstB.MultiportSwitch[1], rtb_DigitalInput_o1,
    ornek_8_1_DW.bitsForTID0.UnitDelay_DSTATE_a, &ornek_8_1_DW.RelationalOperator1_o);

  /* End of Outputs for SubSystem: '<S3>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Logic: '<S3>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator1'
   *  Sum: '<Root>/Sum1'
   *  Switch: '<Root>/Switch'
   */
  if (ornek_8_1_DW.RelationalOperator1_i || ornek_8_1_DW.RelationalOperator1_o) {
    rtb_Memory -= 0.1;
  } else if (ornek_8_1_DW.RelationalOperator1 || ornek_8_1_DW.RelationalOperator1_a) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    rtb_Memory += 0.1;
  }

  /* End of Switch: '<Root>/Switch1' */
  /* Saturate: '<Root>/Saturation' */
  if (rtb_Memory > 1.0) {
    /* Update for Memory: '<Root>/Memory' */
    ornek_8_1_DW.Memory_PreviousInput = 1.0;
  } else if (rtb_Memory < 0.0) {
    /* Update for Memory: '<Root>/Memory' */
    ornek_8_1_DW.Memory_PreviousInput = 0.0;
  } else {
    /* Update for Memory: '<Root>/Memory' */
    ornek_8_1_DW.Memory_PreviousInput = rtb_Memory;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = ornek_8_1_DW.Gain;           /* Period for Channel 1 */

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  ornek_8_1_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o2;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  ornek_8_1_DW.bitsForTID0.UnitDelay_DSTATE_a = rtb_DigitalInput_o1;
}

/* Model initialize function */
void ornek_8_1_initialize(void)
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
}

/* Model terminate function */
void ornek_8_1_terminate(void)
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
  ornek_8_1_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
