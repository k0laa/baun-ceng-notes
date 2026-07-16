/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney8.c
 *
 * Code generated for Simulink model 'deney8'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 13 13:57:13 2026
 */

#include "deney8.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "deney8_private.h"

/* Block signals and states (default storage) */
DW_deney8_T deney8_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* ADC - Interrupt: <Root>/ADC */
volatile uint16_T ADCBuffChannelA[1];
void __attribute__((__interrupt__,__auto_psv__)) _T3Interrupt(void)
{
  ADCON1 = 0x80E4;                     /* Force bits 4-7 for automatic sampling */
  _T3IF = 0;                           /* Disable Interrupt */
}

void __attribute__((__interrupt__,__auto_psv__)) _ADCInterrupt(void)
{
  ADCBuffChannelA[0] = ADCBUF0;        /* Copy value from ADC buffer  */
  ADCON1 &= 0x7FFF;                    /* Must cancel current sampling */

  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _ADIF = 0;                         /* Re-enable interrupt */
  }
}

/* Model step function */
void deney8_step(void)
{
  real_T tmp;
  uint16_T rtb_DataTypeConversion;

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC : <Root>/ADC/Output */
  deney8_DW.ADC = ADCBuffChannelA[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(deney8_ConstP.Constant_Value[(uint16_T)((deney8_DW.ADC & 127U) != 0U) + (deney8_DW.ADC >> 7)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */
}

/* Model initialize function */
void deney8_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_ADC): '<Root>/ADC' */

  /* MCHP_ADC Block for ADC : <Root>/ADC/Initialize */
  ADCHS = 0x08;
  ADCON3 = 0x04;
  ADCON2 = 0x00;
  ADCON1 = 0x8044;
  _ADIP = 2;                           /*Interrupt Priority : 2*/
  _ADIF = 0;
  _ADIE = 1;                           /* Enable ADC Interrupt */
}

/* Model terminate function */
void deney8_terminate(void)
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
    deney8_step();

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
