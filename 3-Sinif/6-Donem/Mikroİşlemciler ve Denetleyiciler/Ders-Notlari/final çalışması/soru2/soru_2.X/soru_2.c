/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_2.c
 *
 * Code generated for Simulink model 'soru_2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jun 19 23:42:19 2026
 */

#include "soru_2.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "soru_2_private.h"

/* Block signals and states (default storage) */
DW_soru_2_T soru_2_DW;
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
void soru_2_step(void)
{
  real_T rtb_Gain;
  int16_T tmp;
  int16_T tmp_0;
  uint16_T rtb_DataTypeConversion;

  /* MultiPortSwitch: '<Root>/Index Vector' incorporates:
   *  Constant: '<S11>/Vector'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   *  MultiPortSwitch: '<S11>/Output'
   *  UnitDelay: '<S12>/Output'
   */
  tmp_0 = (int16_T)soru_2_ConstP.Vector_Value[soru_2_DW.Output_DSTATE] - 1;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  rtb_Gain = floor(soru_2_ConstP.Constant3_Value[tmp_0]);
  if (rtIsNaN(rtb_Gain) || rtIsInf(rtb_Gain)) {
    rtb_Gain = 0.0;
  } else {
    rtb_Gain = fmod(rtb_Gain, 65536.0);
  }

  rtb_DataTypeConversion = rtb_Gain < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (uint16_T)rtb_Gain;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (MCHP_Digital_Output_Write): '<S9>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  soru_2_DW.ADC = ADC1BuffChannelA[0];

  /* Gain: '<Root>/Gain' */
  rtb_Gain = 0.0032258033752441406 * (real_T)soru_2_DW.ADC;

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/Constant9'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Logic: '<Root>/AND'
   *  Logic: '<Root>/AND1'
   *  Logic: '<Root>/AND2'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  Switch: '<Root>/Switch'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch2'
   */
  if ((rtb_Gain >= 3.0) && (rtb_Gain < 3.3)) {
    tmp = 4;
  } else if ((rtb_Gain >= 2.0) && (rtb_Gain < 3.0)) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant11'
     */
    tmp = 3;
  } else if ((rtb_Gain >= 1.0) && (rtb_Gain < 2.0)) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Switch: '<Root>/Switch2'
     */
    tmp = 2;
  } else {
    tmp = 1;
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Switch: '<Root>/Switch3'
   */
  switch (tmp) {
   case 1:
    /* MultiPortSwitch: '<Root>/Index Vector1' */
    rtb_Gain = 0.0;
    break;

   case 2:
    /* MultiPortSwitch: '<Root>/Index Vector1' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    rtb_Gain = soru_2_ConstP.Constant4_Value[tmp_0];
    break;

   case 3:
    /* MultiPortSwitch: '<Root>/Index Vector1' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    rtb_Gain = soru_2_ConstP.Constant5_Value[tmp_0];
    break;

   default:
    /* MultiPortSwitch: '<Root>/Index Vector1' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    rtb_Gain = soru_2_ConstP.Constant6_Value[tmp_0];
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_Gain = floor(rtb_Gain);
  if (rtIsNaN(rtb_Gain) || rtIsInf(rtb_Gain)) {
    rtb_Gain = 0.0;
  } else {
    rtb_Gain = fmod(rtb_Gain, 65536.0);
  }

  rtb_DataTypeConversion = rtb_Gain < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (uint16_T)rtb_Gain;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (MCHP_Digital_Output_Write): '<S10>/Digital Output Write' */
  LATC = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* Switch: '<S14>/FixPt Switch' incorporates:
   *  Constant: '<S13>/FixPt Constant'
   *  Constant: '<S14>/Constant'
   *  Sum: '<S13>/FixPt Sum1'
   *  UnitDelay: '<S12>/Output'
   */
  if ((uint8_T)(soru_2_DW.Output_DSTATE + 1U) > 4) {
    soru_2_DW.Output_DSTATE = 0U;
  } else {
    soru_2_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S14>/FixPt Switch' */
}

/* Model initialize function */
void soru_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

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
}

/* Model terminate function */
void soru_2_terminate(void)
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
    soru_2_step();

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
