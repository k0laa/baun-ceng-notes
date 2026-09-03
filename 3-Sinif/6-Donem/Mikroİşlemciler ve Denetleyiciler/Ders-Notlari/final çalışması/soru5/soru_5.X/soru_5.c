/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_5.c
 *
 * Code generated for Simulink model 'soru_5'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jun 19 23:45:56 2026
 */

#include "soru_5.h"
#include "rtwtypes.h"
#include "soru_5_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals and states (default storage) */
DW_soru_5_T soru_5_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/*
 * Output and update for enable system:
 *    '<S14>/NEGATIVE Edge'
 *    '<S17>/NEGATIVE Edge'
 */
void soru_5_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S14>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S15>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S14>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S14>/POSITIVE Edge'
 *    '<S17>/POSITIVE Edge'
 */
void soru_5_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S14>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S16>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S14>/POSITIVE Edge' */
}

/* Model step function */
void soru_5_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  real_T rtb_Divide;
  real_T rtb_Switch1;
  int16_T tmp;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_f;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */

  /* Outputs for Enabled SubSystem: '<S17>/POSITIVE Edge' */
  /* UnitDelay: '<S17>/Unit Delay' */
  soru_5_POSITIVEEdge(soru_5_ConstB.MultiportSwitch_m[0], rtb_DigitalInput_o2,
                      soru_5_DW.bitsForTID0.UnitDelay_DSTATE, &soru_5_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S17>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S17>/NEGATIVE Edge' */
  soru_5_NEGATIVEEdge(soru_5_ConstB.MultiportSwitch_m[1], rtb_DigitalInput_o2,
                      soru_5_DW.bitsForTID0.UnitDelay_DSTATE, &soru_5_DW.RelationalOperator1_j);

  /* End of Outputs for SubSystem: '<S17>/NEGATIVE Edge' */

  /* Logic: '<S17>/Logical Operator1' */
  rtb_LogicalOperator1_f = (soru_5_DW.RelationalOperator1 || soru_5_DW.RelationalOperator1_j);

  /* Outputs for Enabled SubSystem: '<S14>/POSITIVE Edge' */
  /* UnitDelay: '<S14>/Unit Delay' */
  soru_5_POSITIVEEdge(soru_5_ConstB.MultiportSwitch[0], rtb_DigitalInput_o1,
                      soru_5_DW.bitsForTID0.UnitDelay_DSTATE_b, &soru_5_DW.RelationalOperator1_g);

  /* End of Outputs for SubSystem: '<S14>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S14>/NEGATIVE Edge' */
  soru_5_NEGATIVEEdge(soru_5_ConstB.MultiportSwitch[1], rtb_DigitalInput_o1,
                      soru_5_DW.bitsForTID0.UnitDelay_DSTATE_b, &soru_5_DW.RelationalOperator1_i);

  /* End of Outputs for SubSystem: '<S14>/NEGATIVE Edge' */

  /* Logic: '<S14>/Logical Operator1' */
  rtb_LogicalOperator1 = (soru_5_DW.RelationalOperator1_g || soru_5_DW.RelationalOperator1_i);

  /* CombinatorialLogic: '<S13>/Logic' incorporates:
   *  Memory: '<S13>/Memory'
   */
  rtb_Logic_idx_0 = soru_5_ConstP.pooled11[((((uint16_T)rtb_LogicalOperator1_f << 1) + rtb_LogicalOperator1) <<
    1) + soru_5_DW.bitsForTID0.Memory_PreviousInput_g];

  /* CombinatorialLogic: '<S12>/Logic' incorporates:
   *  Memory: '<S12>/Memory'
   */
  rtb_LogicalOperator1_f = soru_5_ConstP.pooled11[((((uint16_T)rtb_LogicalOperator1 << 1) +
    rtb_LogicalOperator1_f) << 1) + soru_5_DW.bitsForTID0.Memory_PreviousInput_n];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Memory: '<Root>/Memory'
   *  Sum: '<Root>/Add'
   *  Switch: '<Root>/Switch2'
   */
  if (rtb_LogicalOperator1_f) {
    rtb_Switch1 = soru_5_DW.Memory_PreviousInput + 0.001;
  } else if (rtb_LogicalOperator1) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_Switch1 = 0.0;
  } else {
    rtb_Switch1 = soru_5_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch7' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   */
  if (rtb_Logic_idx_0) {
    rtb_Divide = soru_5_DW.Memory_PreviousInput;
  } else {
    rtb_Divide = 0.0;
  }

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Switch: '<Root>/Switch7'
   */
  rtb_Divide = 25.2 / rtb_Divide;

  /* Switch: '<Root>/Switch6' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant9'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<Root>/AND1'
   *  Logic: '<Root>/AND2'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Switch: '<Root>/Switch'
   *  Switch: '<Root>/Switch3'
   *  Switch: '<Root>/Switch4'
   *  Switch: '<Root>/Switch5'
   */
  if (rtb_Divide > 80.0) {
    tmp = 5;
  } else if (rtb_Divide >= 80.0) {
    /* Switch: '<Root>/Switch5' incorporates:
     *  Constant: '<Root>/Constant12'
     */
    tmp = 4;
  } else if ((rtb_Divide > 60.0) && (rtb_Divide <= 70.0)) {
    /* Switch: '<Root>/Switch4' incorporates:
     *  Constant: '<Root>/Constant11'
     *  Switch: '<Root>/Switch5'
     */
    tmp = 3;
  } else if ((rtb_Divide > 50.0) && (rtb_Divide <= 60.0)) {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Switch: '<Root>/Switch4'
     *  Switch: '<Root>/Switch5'
     */
    tmp = 2;
  } else {
    tmp = 1;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant5'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  Switch: '<Root>/Switch6'
   */
  rtb_Divide = floor(soru_5_ConstP.Constant5_Value[tmp - 1] * 39999.0);
  if (rtIsNaN(rtb_Divide) || rtIsInf(rtb_Divide)) {
    rtb_Divide = 0.0;
  } else {
    rtb_Divide = fmod(rtb_Divide, 65536.0);
  }

  /* Gain: '<Root>/Gain' */
  soru_5_DW.Gain = rtb_Divide < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Divide : (uint16_T)rtb_Divide;

  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  soru_5_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o2;

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  soru_5_DW.bitsForTID0.UnitDelay_DSTATE_b = rtb_DigitalInput_o1;

  /* Update for Memory: '<S13>/Memory' */
  soru_5_DW.bitsForTID0.Memory_PreviousInput_g = rtb_Logic_idx_0;

  /* Update for Memory: '<S12>/Memory' */
  soru_5_DW.bitsForTID0.Memory_PreviousInput_n = rtb_LogicalOperator1_f;

  /* Update for Memory: '<Root>/Memory' */
  soru_5_DW.Memory_PreviousInput = rtb_Switch1;

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = soru_5_DW.Gain;              /* Period for Channel 1 */
}

/* Model initialize function */
void soru_5_initialize(void)
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
void soru_5_terminate(void)
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
    soru_5_step();

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
