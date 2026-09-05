/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_8.c
 *
 * Code generated for Simulink model 'ornek_13_8'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 16:38:33 2026
 */

#include "ornek_13_8.h"
#include "rtwtypes.h"
#include "ornek_13_8_private.h"

/* Block signals and states (default storage) */
DW_ornek_13_8_T ornek_13_8_DW;

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
    /* Re-enable timer or interrupt */
    _AD1IF = 0;                        /*  */
    MCHP_Scheduler();
  }
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo)
{
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T in1Lo;
  uint32_T outBitsLo;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16UL;
  in0Lo = in0 & 65535UL;
  in1Hi = in1 >> 16UL;
  in1Lo = in1 & 65535UL;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0UL;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16UL) + /*MW:OvCarryOk*/ in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1UL;
  }

  in0Lo = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16UL;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16UL) + (productHiLo >> 16UL)) + in0Hi * in1Hi) + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_loSR(uint32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T result;
  uint32_T u32_chi;
  mul_wide_u32(a, b, &u32_chi, &result);
  return u32_chi << /*MW:OvBitwiseOk*/ (32UL - aShift) | result >> aShift;
}

/* Model step function */
void ornek_13_8_step(void)
{
  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  ornek_13_8_DW.ADC = ADC1BuffChannelA[0];

  /* Gain: '<Root>/Gain1' incorporates:
   *  Bias: '<Root>/Bias'
   *  Gain: '<Root>/Gain'
   */
  ornek_13_8_DW.Gain1 = (uint16_T)mul_u32_loSR(49999UL, 52429UL * ornek_13_8_DW.ADC + 53687091UL, 30UL);

  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = ornek_13_8_DW.Gain1;         /* Period for Channel 1 */
}

/* Model initialize function */
void ornek_13_8_initialize(void)
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
  PWM1CON1 = 0x10;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0xF2B2;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x87;
  P1TPER = 0x61A8;
  P1SECMP = 0x04E2;
  P1TCON = 0x800B;                     /* Enable PWM */
}

/* Model terminate function */
void ornek_13_8_terminate(void)
{
  /* (no terminate code required) */
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  /* Call model Scheduler */

  /* Step the model for base rate */
  ornek_13_8_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
