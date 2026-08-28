/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_9_1.c
 *
 * Code generated for Simulink model 'ornek_9_1'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 18:23:14 2026
 */

#include "ornek_9_1.h"
#include "ornek_9_1_private.h"

/* Block signals and states (default storage) */
DW_ornek_9_1_T ornek_9_1_DW;

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

/* Model step function */
void ornek_9_1_step(void)
{
  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  ornek_9_1_DW.ADC = ADC1BuffChannelA[0];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = ornek_9_1_DW.ADC;             /* No mask required : all pins defined as digital output are updated */
}

/* Model initialize function */
void ornek_9_1_initialize(void)
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
}

/* Model terminate function */
void ornek_9_1_terminate(void)
{
  /* (no terminate code required) */
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  /* Call model Scheduler */

  /* Step the model for base rate */
  ornek_9_1_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
