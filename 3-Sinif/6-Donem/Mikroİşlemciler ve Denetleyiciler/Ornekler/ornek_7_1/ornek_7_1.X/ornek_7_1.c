/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_7_1.c
 *
 * Code generated for Simulink model 'ornek_7_1'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 10:11:19 2026
 */

#include "ornek_7_1.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ornek_7_1_private.h"

/* Block signals and states (default storage) */
DW_ornek_7_1_T ornek_7_1_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_7_1_step(void)
{
  real32_T rtb_Memory;
  real32_T tmp;
  uint16_T rtb_DataTypeConversion;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_7_1_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Memory: '<Root>/Memory'
   */
  tmp = floorf(ornek_7_1_DW.Memory_PreviousInput);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  rtb_DataTypeConversion = tmp < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_IC): '<Root>/Input Capture' */
  /* S-Function "dsPIC_PWM_IC" Block: <Root>/Input Capture */
  ornek_7_1_DW.InputCapture_o1 = MCHP_ic1up;
  ornek_7_1_DW.InputCapture_o2 = MCHP_ic1ChangeDetectedFlag;
  MCHP_ic1ChangeDetectedFlag = 0;
  ornek_7_1_DW.InputCapture_o3 = MCHP_ic2up;
  ornek_7_1_DW.InputCapture_o4 = MCHP_ic2ChangeDetectedFlag;
  MCHP_ic2ChangeDetectedFlag = 0;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S1>/FixPt Constant'
   *  Sum: '<S1>/FixPt Sum1'
   *  Switch: '<Root>/Switch'
   */
  if (ornek_7_1_DW.InputCapture_o4 > 0U) {
    rtb_Memory--;
  } else if (ornek_7_1_DW.InputCapture_o2 > 0U) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<S3>/FixPt Constant'
     *  Sum: '<S3>/FixPt Sum1'
     */
    rtb_Memory++;
  }

  /* End of Switch: '<Root>/Switch1' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_7_1_DW.Memory_PreviousInput = rtb_Memory;
}

/* Model initialize function */
void ornek_7_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_IC): '<Root>/Input Capture' */
  IC1CON = 0x83;
  IC2CON = 0x83;

  /* Set-up Input Capture Interruption */
  _IC1IF = 0;                          /* Clear interrupt Flag */
  _IC1IP = 4;                          /* Set interrupt Priority */
  _IC1IE = 1;                          /* Enable Interrupt */
  _IC2IF = 0;                          /* Clear interrupt Flag */
  _IC2IP = 4;                          /* Set interrupt Priority */
  _IC2IE = 1;                          /* Enable Interrupt */
}

/* Model terminate function */
void ornek_7_1_terminate(void)
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
    ornek_7_1_step();

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
