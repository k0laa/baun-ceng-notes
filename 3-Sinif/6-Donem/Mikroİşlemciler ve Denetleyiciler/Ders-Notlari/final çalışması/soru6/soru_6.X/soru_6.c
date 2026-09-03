/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_6.c
 *
 * Code generated for Simulink model 'soru_6'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 00:51:59 2026
 */

#include "soru_6.h"
#include <math.h>
#include "rtwtypes.h"
#include "soru_6_private.h"

/* Block signals and states (default storage) */
DW_soru_6_T soru_6_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* ADC - Interrupt: <Root>/ADC */
volatile uint16_T ADC1BuffChannelA[1];
void __attribute__((__interrupt__,__auto_psv__)) _T3Interrupt(void)
{
  AD1CON1 = 0x80E4;                    /* Force bits 4-7 for automatic sampling */
  _T3IF = 0;                           /* Disable Interrupt */
}

void __attribute__((__interrupt__,__auto_psv__)) _ADC1Interrupt(void)
{
  ADC1BuffChannelA[0] = ADC1BUF0;      /* Copy value from ADC buffer  */
  AD1CON1 &= 0x7FFF;                   /* Must cancel current sampling */

  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _AD1IF = 0;                        /* Re-enable interrupt */
  }
}

/* Model step function */
void soru_6_step(void)
{
  real_T rtb_Gain;
  real_T rtb_Switch;
  boolean_T rtb_Compare;
  boolean_T rtb_Logic_idx_0;

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  Memory: '<Root>/Memory'
   */
  rtb_Compare = (soru_6_DW.Memory_PreviousInput > 0.0);

  /* S-Function (MCHP_Digital_Output_Write): '<S8>/Digital Output Write' */
  LATBbits.LATB2 = rtb_Compare;

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  soru_6_DW.ADC = ADC1BuffChannelA[0];

  /* Gain: '<Root>/Gain' */
  rtb_Gain = 0.1466275659824047 * (real_T)soru_6_DW.ADC;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Compare = (rtb_Gain <= 20.0);

  /* Outputs for Enabled SubSystem: '<S11>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (soru_6_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S13>/Relational Operator1' incorporates:
     *  UnitDelay: '<S11>/Unit Delay'
     */
    soru_6_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_Compare > (int16_T)
      soru_6_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S11>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S11>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (soru_6_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S12>/Relational Operator1' incorporates:
     *  UnitDelay: '<S11>/Unit Delay'
     */
    soru_6_DW.bitsForTID0.RelationalOperator1_f = ((int16_T)soru_6_DW.bitsForTID0.UnitDelay_DSTATE > (int16_T)
      rtb_Compare);
  }

  /* End of Outputs for SubSystem: '<S11>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S10>/Logic' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S6>/Constant'
   *  Logic: '<Root>/AND2'
   *  Logic: '<Root>/OR'
   *  Logic: '<S11>/Logical Operator1'
   *  Memory: '<Root>/Memory'
   *  Memory: '<S10>/Memory'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  rtb_Logic_idx_0 = soru_6_ConstP.Logic_table[(((uint16_T)(((rtb_Gain >= 21.0) && (rtb_Gain <= 75.0)) ||
    (soru_6_DW.Memory_PreviousInput > 7200.0)) + ((uint16_T)(soru_6_DW.bitsForTID0.RelationalOperator1 ||
    soru_6_DW.bitsForTID0.RelationalOperator1_f) << 1)) << 1) + soru_6_DW.bitsForTID0.Memory_PreviousInput_f];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   *  Sum: '<Root>/Sum'
   */
  if (rtb_Logic_idx_0) {
    rtb_Switch = soru_6_DW.Memory_PreviousInput + 0.01;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  Switch: '<Root>/Switch1'
   */
  if (rtb_Gain >= 100.0) {
    rtb_Gain = 95.0;
  } else if (rtb_Gain >= 76.0) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Constant: '<Root>/Constant3'
     *  Gain: '<Root>/Gain1'
     *  Sum: '<Root>/Sum1'
     *  Sum: '<Root>/Sum2'
     */
    rtb_Gain = (rtb_Gain - 76.0) * 1.875 + 50.0;
  } else {
    rtb_Gain = 0.0;
  }

  /* Gain: '<Root>/Gain2' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Switch: '<Root>/Switch2'
   */
  soru_6_DW.Gain2 = (uint16_T)floor(0.01 * rtb_Gain * 39999.0);

  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* Update for Memory: '<Root>/Memory' */
  soru_6_DW.Memory_PreviousInput = rtb_Switch;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  soru_6_DW.bitsForTID0.UnitDelay_DSTATE = rtb_Compare;

  /* Update for Memory: '<S10>/Memory' */
  soru_6_DW.bitsForTID0.Memory_PreviousInput_f = rtb_Logic_idx_0;

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = soru_6_DW.Gain2;             /* Period for Channel 1 */
}

/* Model initialize function */
void soru_6_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_ADC): '<Root>/ADC' */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Initialize */
  AD1CHS0 = 0x00;
  AD1CHS123 = 0x00;
  AD1CON3 = 0x06;
  AD1CON2 = 0x00;
  AD1CON1 = 0x8044;
  _AD1IP = 2;                          /*Interrupt Priority : 2*/
  _AD1IF = 0;
  _AD1IE = 1;                          /* Enable ADC Interrupt */

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
void soru_6_terminate(void)
{
  /* (no terminate code required) */
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
    soru_6_step();

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
